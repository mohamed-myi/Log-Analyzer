#ifndef LOGPARSER_H
#define LOGPARSER_H

#include <string>
#include <vector>

// Represents a single log entry with timestamp and message
struct LogEntry {
    std::string rawLine;  // Original line from log file
    std::string timestamp;
    std::string level;
    std::string message;
};

// Parses log file and returns vector of LogEntry objects
std::vector<LogEntry> parseLog(const std::string& filePath);

#endif