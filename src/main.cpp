#include <iostream>
#include <string>
#include "fileReader.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: logAnalyzer <log_file>" << std::endl;
        return 1;
    }

    std::string logFile = argv[1];
    
    if (!checkFile(logFile)) {
        std::cout << "Error: File not found or not readable" << std::endl;
        return 1;
    }

    std::cout << "Log Analyzer initialized for: " << logFile << std::endl;

    return 0;
}