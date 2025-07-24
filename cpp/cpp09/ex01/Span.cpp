#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int n) : max_size(n) {}

Span::Span(const Span &og) : numbers(og.numbers), max_size(og.max_size) {}

Span &Span::operator=(const Span &og)
{
	if (this != &og)
	{
		numbers = og.numbers;
		max_size = og.max_size;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (numbers.size() >= max_size)
		throw std::runtime_error("Error: Vector is full!");

	numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw std::logic_error("Error: Not enough numbers to compute span.");

	std::vector<int> sorted = numbers;
	std::sort(sorted.begin(), sorted.end());

	int leastATM = INT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; ++i)
	{
		if (sorted[i + 1] - sorted[i] < leastATM)
			leastATM = sorted[i + 1] - sorted[i];
	}
	return leastATM;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw std::logic_error("Not enough numbers to compute span.");

	int minVal = *std::min_element(numbers.begin(), numbers.end());
	int maxVal = *std::max_element(numbers.begin(), numbers.end());

	return maxVal - minVal;
}

