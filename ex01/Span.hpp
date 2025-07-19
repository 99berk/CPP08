#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
	private:
		std::vector<int> numbers;
		unsigned int maxSize;
	public:
		Span();
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();
		Span(unsigned int n);
		
		void addNumber(int num);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename I>
		void addRange(I begin, I end)
		{
			if (std::distance(begin, end) + numbers.size() > maxSize)
				throw std::length_error("Span is full or exceeds maximum size");
			numbers.insert(numbers.end(), begin, end);
		}
};

#endif
