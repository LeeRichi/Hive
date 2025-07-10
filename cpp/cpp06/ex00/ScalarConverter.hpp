#include <string>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <sstream>
#pragma once

class ScalarConverter {
    public:
        static void convert(const std::string& input);
    private:
        static bool isValidInput(const std::string& input);
        static bool isSpecialValue(const std::string& input);

        static void handleInvalidInput(const std::string& input);
        static void handleSpecialValues(const std::string& input);

        static void convertToChar(double value);
        static void convertToInt(double value);
        static void convertToFloat(double value);
        static void convertToDouble(double value);

        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter &original) = delete;
        ScalarConverter &operator=(ScalarConverter &soriginal) = delete;
        ~ScalarConverter() = delete;
};
