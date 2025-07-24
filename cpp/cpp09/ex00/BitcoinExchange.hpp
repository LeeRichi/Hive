#pragma once

class BitcoinExchange {
	private:
		std::map<int> numbers;
		

	public:
		BitcoinExchange();
		BitcoinExchange(unsigned int n);
		BitcoinExchange(const Span &og);
		BitcoinExchange &operator=(const BitcoinExchange &og);



        void readStore(int file);

		// void addNumber(int n);
		// int shortestSpan() const;
		// int longestSpan() const;

		// template<typename InputIterator>
		// void addNumbers(InputIterator begin, InputIterator end)
		// {
		// 	if (std::distance(begin, end) + numbers.size() > max_size)
		// 		throw std::overflow_error("Error: Adding this range would exceed the span's capacity.");

		// 	numbers.insert(numbers.end(), begin, end);
		// }
};
