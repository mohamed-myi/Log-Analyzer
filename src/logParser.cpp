#include "logParser.h"
#include "logEntry.h"
#include <fstream>
#include <sstream>

std::vector<LogEntry> parseLog(const std::string& filePath) {
    std::vector<LogEntry> entries;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        return entries;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            LogEntry entry = parseLogEntry(line);
            if (isValidEntry(entry)) {
                entries.push_back(entry);
            }
        }
    }

    file.close();
    return entries;
}