#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

// Check if file exists and is readable
bool checkFile(const std::string& filePath);

// Read all lines from file into vector
std::vector<std::string> readFile(const std::string& filePath);

#endif