#ifndef LOGPARSER_H
#define LOGPARSER_H

#include "logEntry.h"
#include <string>
#include <vector>

// Parses log file and returns vector of LogEntry objects
std::vector<LogEntry> parseLog(const std::string& filePath);

#endif