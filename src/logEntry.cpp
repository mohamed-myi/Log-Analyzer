#include "logEntry.h"
#include <sstream>
#include <algorithm>

LogEntry parseLogEntry(const std::string& line) {
    LogEntry entry;
    entry.rawLine = line;
    entry.valid = false;

    if (line.empty()) {
        return entry;
    }

    std::istringstream stream(line);
    std::string token;
    int fieldCount = 0;

    // Extract timestamp (first field)
    if (std::getline(stream, token, ' ')) {
        entry.timestamp = token;
        fieldCount++;
    }

    // Extract log level (second field)
    if (std::getline(stream, token, ' ')) {
        entry.level = token;
        fieldCount++;
    }

    // Extract source (third field)
    if (std::getline(stream, token, ' ')) {
        entry.source = token;
        fieldCount++;
    }

    // Extract remaining as message
    std::getline(stream, entry.message);
    if (!entry.message.empty()) {
        fieldCount++;
    }

    // Entry is valid if it has at least 3 fields
    entry.valid = fieldCount >= 3;

    return entry;
}


bool isValidEntry(const LogEntry& entry) {
    return !entry.timestamp.empty() && 
           !entry.level.empty() && 
           !entry.source.empty();
}