#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : maxSize(0) {}

Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		maxSize = other.maxSize;
	}
	return *this;
}

Span::~Span() {}

Span::Span(unsigned int n) : maxSize(n) {}

void Span::addNumber(int num)
{
	if (numbers.size() >= maxSize)
		throw std::length_error("Span is full");
	numbers.push_back(num);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int min = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		if (sorted[i] - sorted[i - 1] < min)
			min = sorted[i] - sorted[i - 1];
	}
	return min;
}

int Span::longestSpan(void) const
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	return (sorted[sorted.size() - 1] - sorted[0]);
}
