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
		~BitcoinExchange();

		void readStore(const std::string& filename); //read data.csv
		void multiplyPrint(const std::string &filename); //read input.txt(av[1]) and calculate
	};
