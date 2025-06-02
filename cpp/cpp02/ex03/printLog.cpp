#include "printLog.hpp"
#include <iostream>

void printLog(const char* msg) {
    #if defined(DEBUG) && DEBUG != 0
        std::cout << msg << std::endl;
    #else
        (void)msg;
    #endif
}
