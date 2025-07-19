#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 1; i <= 5; ++i)
		vec.push_back(i);
	for (int i = 10; i <= 30; i += 10)
		lst.push_back(i);

	try
	{
		
		std::vector<int>::iterator itVec = easyfind(vec, 3);
		std::cout << "Found in vector: " << *itVec << std::endl;

		std::list<int>::iterator itLst = easyfind(lst, 20);
		std::cout << "Found in list: " << *itLst << std::endl;

		std::vector<int>::iterator itNotFound = easyfind(vec, 6);
		std::cout << "Found in vector: " << *itNotFound << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
