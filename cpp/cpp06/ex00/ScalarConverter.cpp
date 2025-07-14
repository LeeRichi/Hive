#include "ScalarConverter.hpp"
#include <stdexcept>

bool ScalarConverter::isValidInput(const std::string &input) {
    if (input.empty()) {
        return false;
    }
    if (input == "nan" || input == "inf" || input == "-inf") {
        return true;
    }
    if (input.size() == 1 && std::isprint(input[0])) {
        return true;
    }
    try {
			std::stod(input);
			return true;
		} catch (const std::out_of_range &) {
			return true;
    } catch (const std::invalid_argument &) {
			return false;
		}
}

bool ScalarConverter::isSpecialValue(const std::string &input) {
	return input == "nan" || input == "inf" || input == "-inf";
}

void ScalarConverter::handleInvalidInput(const std::string &input) {
	std::cerr << "Invalid input: " << input << std::endl;
}

void handleOutOfRange(const std::string &input) {
	std::cerr << "Input out of range: " << input << std::endl;
}

//hard code pseudo-literals
void ScalarConverter::handleSpecialValues(const std::string &input) {
	if (input == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else if (input == "inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inf" << std::endl;
		std::cout << "double: inf" << std::endl;
	} else if (input == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inf" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convertToChar(double value) {
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits
        <char>::max() || std::isnan(value) || std::isinf(value)) {
		std::cout << "char: impossible" << std::endl;
	} else if (std::isprint(static_cast<char>(value))) {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	} else {
		std::cout << "char: Non displayable" << std::endl;
	}
}

void ScalarConverter::convertToInt(double value) {
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void ScalarConverter::convertToFloat(double value) {
	if (std::isnan(value)) {
		std::cout << "float: nanf" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "float: " << (value > 0 ? "inf" : "-inf") << std::endl;
	} else if (value < std::numeric_limits<float>::lowest() || value > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	} else {
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
}

void ScalarConverter::convertToDouble(double value) {
	if (std::isnan(value)) {
		std::cout << "double: nan" << std::endl;
	} else if (std::isinf(value)) {
		std::cout << "double: " << (value > 0 ? "inf" : "-inf") << std::endl;
	} else {
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	}
}

//     [input string]
//          ↓
//    ┌──────────────┐
//    │ std::stod()  │  → parse safely
//    └──────────────┘
//          ↓
//       [double]    → from here:
//          ↓               ↓                ↓                 ↓
//   convertToChar()  convertToInt()  convertToFloat()  convertToDouble()

//the main function
void ScalarConverter::convert(const std::string &input) {
	if (!isValidInput(input)) {
		handleInvalidInput(input);
		return;
	}
	if (isSpecialValue(input)) {
		handleSpecialValues(input);
		return;
	}

	//double can cover all possible valid inputs
	double value;
	try {
		value = std::stod(input);
	}
	catch (const std::out_of_range &) {
		handleOutOfRange(input);
		return;
	}
	catch (const std::invalid_argument &) {
		handleInvalidInput(input);
		return;
	}

	convertToChar(value);
	convertToInt(value);
	convertToFloat(value);
	convertToDouble(value);
}
