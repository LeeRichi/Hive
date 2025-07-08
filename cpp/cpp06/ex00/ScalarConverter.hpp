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
        static void convertToChar(double value);
        static void convertToInt(double value);
        static void convertToFloat(double value);
        static void convertToDouble(double value);

        static bool isChar(const std::string& input);
        static bool isInt(const std::string& input);
        static bool isFloat(const std::string& input);
        static bool isDouble(const std::string& input);
        static bool isSpecialValue(const std::string& input);
        static bool isValidInput(const std::string& input);

        static void printChar(char value);
        static void printInt(int value);
        static void printFloat(float value);
        static void printDouble(double value);

        static void handleSpecialValues(const std::string& input);
        static void handleInvalidInput(const std::string& input);
};
