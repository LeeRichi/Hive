#pragma once
#include <vector>
#include <climits>
#include <stdexcept>    // for std::overflow_error, std::runtime_error, std::logic_error
#include <algorithm>    // for std::sort, std::min_element, std::max_element

class Span {
	private:
		std::vector<int> numbers;
		unsigned int max_size;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &og);
		Span &operator=(const Span &og);

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;

		template<typename InputIterator>
		void addNumbers(InputIterator begin, InputIterator end)
		{
			if (std::distance(begin, end) + numbers.size() > max_size)
				throw std::overflow_error("Error: Adding this range would exceed the span's capacity.");

			numbers.insert(numbers.end(), begin, end);
		}
};
