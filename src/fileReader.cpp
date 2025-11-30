#include "fileReader.h"
#include <fstream>
#include <iostream>

bool checkFile(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.is_open();
}


std::vector<std::string> readFile(const std::string& filePath) {
    std::vector<std::string> lines;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cout << "Error: Cannot open file " << filePath << std::endl;
        return lines;
    }

    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}