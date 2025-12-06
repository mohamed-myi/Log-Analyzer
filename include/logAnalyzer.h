#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include "logEntry.h"
#include <string>
#include <vector>
#include <map>

// Get count of entries by log level
std::map<std::string, int> getStatsByLevel(const std::vector<LogEntry>& entries);

// Get count of ERROR entries by source component
std::map<std::string, int> getErrorsBySource(const std::vector<LogEntry>& entries);

// Get source component with highest number of log entries
std::string getMostFrequentSource(const std::vector<LogEntry>& entries);

#endif