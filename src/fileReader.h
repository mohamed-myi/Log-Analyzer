#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

// Read file and return all lines as vector of strings
std::vector<std::string> readFile(const std::string& filePath);

// Check if file exists and is readable
bool checkFile(const std::string& filePath);

#endif