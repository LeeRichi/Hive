#pragma once

class Span {
	private:
		std::vector<int> numbers;
		unsigned int max_size;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span &og);
		Span &operator=(Span &og);

		void addNumber();
		int shortestSpan() const;
		int longestSpan() const;
};
