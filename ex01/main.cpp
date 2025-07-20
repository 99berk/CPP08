#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>

bool isValidInteger(const char* str)
{
    if (!str || *str == '\0')
        return false;
        
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i = 1;
        
    for (; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    
    return (i > (str[0] == '-' || str[0] == '+' ? 1 : 0));
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        try
        {
            std::cout << "== Test: Using command line arguments for " << ac -1 << " ==" << std::endl;
            Span sp(ac - 1);
            std::list<int> lst;
            for (int i = 1; i < ac; ++i)
            {
                if (isValidInteger(av[i]))
                {
                    int num = std::atoi(av[i]);
                    lst.push_back(num);
                }
                else
                {
                    std::cerr << "Invalid argument: " << av[i] << " (must be an integer)" << std::endl;
                    return 1;
                }
            }
            
            sp.addRange(lst.begin(), lst.end());
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
            return 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return 1;
        }
    }
    
    try
    {
        std::cout << "== Test 1: Overload the capacity ==" << std::endl;
        Span array(3);
        
        array.addNumber(12);
        array.addNumber(6);
        array.addNumber(21);
        array.addNumber(32);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        std::cout << std::endl << "== Test 2: Test the span with small numbers ==" << std::endl;
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl << "== Test 3: Large container test (10000+ numbers) ==" << std::endl;
        Span bigSpan(15000);
        std::vector<int> bigVec;
        for (int i = 0; i < 10000; ++i)
            bigVec.push_back(i * 2);
        
        bigSpan.addRange(bigVec.begin(), bigVec.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
