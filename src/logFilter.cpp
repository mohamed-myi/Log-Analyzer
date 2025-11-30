#include "logFilter.h"
#include <algorithm>

std::vector<LogEntry> filterByLevel(const std::vector<LogEntry>& entries, const std::string& minLevel) {
    std::vector<LogEntry> filtered;
    int minSeverity = getLevelSeverity(minLevel);

    for (const auto& entry : entries) {
        if (entry.valid && getLevelSeverity(entry.level) >= minSeverity) {
            filtered.push_back(entry);
        }
    }

    return filtered;
}


std::vector<LogEntry> filterByDateRange(const std::vector<LogEntry>& entries, const std::string& startDate, const std::string& endDate) {
    // Extracts date portion (first 10 chars: YYYY-MM-DD) from timestamp and compares
    std::vector<LogEntry> filtered;

    for (const auto& entry : entries) {
        if (entry.valid && entry.timestamp.length() >= 10) {
            std::string entryDate = entry.timestamp.substr(0, 10);

            if (entryDate >= startDate && entryDate <= endDate) {
                filtered.push_back(entry);
            }
        }
    }

    return filtered;
}