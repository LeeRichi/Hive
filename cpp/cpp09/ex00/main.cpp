// #include <iostream>
// #include <fstream>
// #include <map>
// #include <string>
// #include <sstream>
// #include <limits>
// #include "BitcoinExchange.hpp"

// bool isValidDate(const std::string& date) {
//     if (date.size() != 10) return false;
//     if (date[4] != '-' || date[7] != '-') return false;
//     // Further date validation can be added
//     return true;
// }

// bool isValidValue(float value) {
//     return value >= 0 && value <= std::numeric_limits<float>::max();
// }

// int main(int ac, char **av) {
//     if (ac != 2) {
//         std::cout << "Error: could not open file." << std::endl;
//         return 1;
//     }

//     std::ifstream file(av[1]);
//     if (!file.is_open()) {
//         std::cerr << "Error: file could not be opened." << std::endl;
//         return 1;
//     }

//     //parsing starts
//     std::map<std::string, float> data;
//     std::string line;
    
//     // Skip header line
//     std::getline(file, line);
    
    
//     //trmming logic
//     // iss >> date >> sep >> value;
//     while (std::getline(file, line)) {
//         if (line.empty()) continue;

//         std::istringstream iss(line);
//         std::string date, sep, valueStr;
//         // float value;

//          if (!std::getline(iss, date, '|') || !std::getline(iss, valueStr)) {
//             std::cerr << "Error: bad input => " << line << std::endl;
//             continue;
//         }

//         // Trim spaces
//         date.erase(0, date.find_first_not_of(" \t"));
//         date.erase(date.find_last_not_of(" \t") + 1);
//         valueStr.erase(0, valueStr.find_first_not_of(" \t"));
//         valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

//         if (!isValidDate(date)) {
//             std::cerr << "Error: invalid date => " << date << std::endl;
//             continue;
//         }

//         try {
//             float value = std::stof(valueStr);
//             if (!isValidValue(value)) {
//                 std::cerr << "Error: invalid value => " << valueStr << std::endl;
//                 continue;
//             }
//             data[date] = value;
//         } catch (const std::exception& e) {
//             std::cerr << "Error: could not parse value => " << valueStr << std::endl;
//         }
//     }

//     //data printing
//     for (const auto& pair : data) {
//         std::cout << pair.first << " => " << pair.second << std::endl;
//     }

//     file.close();

//     // convert(data); // This function must be defined in BitcoinExchange.hpp/.cpp

//     return 0;
// }


#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	btc.readStore(av[1]);

	return 0;
}
