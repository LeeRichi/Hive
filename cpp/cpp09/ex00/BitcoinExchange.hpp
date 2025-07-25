#pragma once

#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float> numbers;

	public:
		BitcoinExchange();
		BitcoinExchange(unsigned int n);
		BitcoinExchange(const BitcoinExchange &og);
		BitcoinExchange &operator=(const BitcoinExchange &og);

		void readStore(const std::string& filename);  // changed from int to string
};
