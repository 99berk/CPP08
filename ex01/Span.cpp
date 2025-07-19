#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : maxSize(0) {}

Span::Span(unsigned int n) : maxSize(n) {}

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
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan(void) const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough numbers to find a span");
	std::vector<int> v = numbers;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}
