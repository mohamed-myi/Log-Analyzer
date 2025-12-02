#include "logAnalyzer.h"

std::map<std::string, int> getStatsByLevel(const std::vector<LogEntry>& entries) {
    // Returns map of log level to count of entries at that level
    std::map<std::string, int> stats;

    for (const auto& entry : entries) {
        if (entry.valid) {
            stats[entry.level]++;
        }
    }

    return stats;
}


std::map<std::string, int> getErrorsBySource(const std::vector<LogEntry>& entries) {
    // Returns map of source to count of ERROR level entries from that source
    std::map<std::string, int> errorCounts;

    for (const auto& entry : entries) {
        if (entry.valid && entry.level == "ERROR") {
            errorCounts[entry.source]++;
        }
    }

    return errorCounts;
}


std::string getMostFrequentSource(const std::vector<LogEntry>& entries) {
    // Returns source component that generated the most log entries
    std::map<std::string, int> sourceCounts;
    std::string maxSource;
    int maxCount = 0;

    for (const auto& entry : entries) {
        if (entry.valid) {
            sourceCounts[entry.source]++;
        }
    }

    for (const auto& pair : sourceCounts) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxSource = pair.first;
        }
    }

    return maxSource;
}