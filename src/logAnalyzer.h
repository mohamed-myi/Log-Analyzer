#ifndef LOGANALYZER_H
#define LOGANALYZER_H

#include "logEntry.h"
#include <vector>
#include <string>
#include <map>

// Get count of entries for each log level
std::map<std::string, int> getStatsByLevel(const std::vector<LogEntry>& entries);

// Get count of errors grouped by source component
std::map<std::string, int> getErrorsBySource(const std::vector<LogEntry>& entries);

// Get source component that generated the most log entries
std::string getMostFrequentSource(const std::vector<LogEntry>& entries);

#endif