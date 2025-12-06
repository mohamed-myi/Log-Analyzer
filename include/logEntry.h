#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>
#include <vector>

struct LogEntry {
    std::string timestamp;
    std::string level;
    std::string source;
    std::string message;
    std::string rawLine;
    bool valid;
};

// Parse single log line into LogEntry struct
LogEntry parseLogEntry(const std::string& line);

// Check if LogEntry has all required fields
bool isValidEntry(const LogEntry& entry);

// Format LogEntry as readable string: [timestamp] level source - message
std::string getFormattedEntry(const LogEntry& entry);

// Get numeric severity of log level (DEBUG=1, INFO=2, WARNING=3, ERROR=4)
int getLevelSeverity(const std::string& level);

#endif