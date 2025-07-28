#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <chrono>
#include <climits>
#include <string>
#include <iomanip>  // <-- needed for std::fixed and std::setprecision

void printTime(const std::string &containerName,
    std::chrono::high_resolution_clock::time_point start,
    std::chrono::high_resolution_clock::time_point end,
    size_t len)
{
    auto duration = std::chrono::duration_cast<std::chrono::duration<double, std::micro>>(end - start).count();

    std::cout << std::fixed << std::setprecision(5);  // <-- ensure 5 digits after decimal
    std::cout << "Time to process a range of    " << len << " elements with " << containerName
    << " : " << duration << " us" << std::endl;
}

void printSequence(const std::vector<int>& vec, const std::string& prefix)
{
    std::cout << prefix;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printSequence(const std::deque<int>& deq, const std::string& prefix)
{
    std::cout << prefix;
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int parse_and_validate(const std::string& str)
{
    try {
        size_t pos;
        int result = std::stoi(str, &pos);

        // Check if there's junk after the number
        if (pos != str.length()) {
            throw std::invalid_argument("Extra characters after number");
        }

        if (result <= 0)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        return result;
    }
    catch (const std::exception& e) {
        std::cerr << "Error parsing '" << str << "': " << e.what() << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    PmergeMe cont;
    for (int i = 1; i < argc; i++)
    {
        int val = parse_and_validate(argv[i]);
        cont.addNumber(val);
    }

    printSequence(cont.getVector(), "Before: ");

    auto start = std::chrono::high_resolution_clock::now();
    cont.mergeInsertSortVector(cont.getVector(), 0, cont.getVector().size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    //subject print
    printSequence(cont.getVector(), "After: ");
    // printSequence(cont.getVector(), "After(vector): ");
    printTime("std::vector", start, end, cont.getVector().size());

    start = std::chrono::high_resolution_clock::now();
    cont.mergeInsertSortDeque(cont.getDeque(), 0, cont.getDeque().size() - 1);
    end = std::chrono::high_resolution_clock::now();
    // printSequence(cont.getDeque(), "After(deque): ");

    printTime("std::deque", start, end, cont.getDeque().size());

    return 0;
}
