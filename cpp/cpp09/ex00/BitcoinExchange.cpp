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

static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isValidDate(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	try {
		year = std::stoi(date.substr(0, 4));
		month = std::stoi(date.substr(5, 2));
		day = std::stoi(date.substr(8, 2));
	} catch (...) {
		return false;
	}

	const int daysInMonth[12] = {
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};

	if (month < 1 || month > 12)
		return false;

	int maxDay = daysInMonth[month - 1];
	if (month == 2 && isLeapYear(year))
		maxDay = 29;

	if (day < 1 || day > maxDay)
		return false;

	return true;
}

static bool isPositiveValue(float value) {
	return value > 0;
}

static bool isToolargeValue(float value) {
	return value > 1000;
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

		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		// Trim
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		try {
			float value = std::stof(valueStr);
			numbers[date] = value;
		} catch (const std::exception& e) {
			std::cerr << "Error: could not parse value => " << valueStr << std::endl;
		}
	}
}

//parsing input.txt(dynamic file parsing)
void BitcoinExchange::multiplyPrint(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: file could not be opened." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line); // skip header

	if (line != "date | value")
	{
		std::cerr << "Error: missing header or header in wrong format." << std::endl;
		return;
	}

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
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		try {
			float value = std::stof(valueStr);

			if (!isPositiveValue(value))
			{
				std::cerr << "Error: not a positive number." << std::endl;
				continue;
			}

			if (isToolargeValue(value)) {
				std::cerr << "Error: too large a number." << std::endl;
				continue;
			}

			//now value is valid
			//search in data pairs (numbers)
			//also this should be the output of the program
			std::map<std::string, float>::const_iterator it = numbers.lower_bound(date);
			if (it == numbers.end() || it->first != date) {
				if (it == numbers.begin()) {
					std::cerr << "Error: no earlier date available for " << date << std::endl;
					continue;
				}
				--it;
			}

			float rate = it->second;
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Error: could not parse value => " << valueStr << std::endl;
		}
	}
}

