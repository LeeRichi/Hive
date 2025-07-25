#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(unsigned int) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &og) { *this = og; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &og) {
	if (this != &og)
		this->numbers = og.numbers;
	return *this;
}

static bool isValidDate(const std::string& date) {
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;
	// You can add more robust checks here
	return true;
}

static bool isValidValue(float value) {
	return value >= 0 && value <= std::numeric_limits<float>::max();
}

void BitcoinExchange::readStore(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: file could not be opened." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header

	while (std::getline(file, line)) {
		if (line.empty()) continue; //read the next line

		std::istringstream iss(line);
		std::string date, valueStr;

		if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Trim
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}

		try {
			float value = std::stof(valueStr);
			if (!isValidValue(value)) {
				std::cerr << "Error: invalid value => " << valueStr << std::endl;
				continue;
			}
			numbers[date] = value;
		} catch (const std::exception& e) {
			std::cerr << "Error: could not parse value => " << valueStr << std::endl;
		}
	}

	// test printing
	for (const auto& pair : numbers) {
		std::cout << pair.first << " => " << pair.second << std::endl;
	}
}
