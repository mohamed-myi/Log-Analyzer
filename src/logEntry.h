#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

// Represents a single log entry with parsed components
struct LogEntry {
    std::string rawLine;      // Original line from log file
    std::string timestamp;    // Extracted timestamp
    std::string level;        // Log level (INFO, ERROR, WARNING, DEBUG)
    std::string source;       // Source/component that generated the log
    std::string message;      // Log message content
    bool valid;               // Whether entry was successfully parsed
};

// Parse raw log line into LogEntry structure
LogEntry parseLogEntry(const std::string& line);

// Validate log entry has required fields
bool isValidEntry(const LogEntry& entry);

#endif