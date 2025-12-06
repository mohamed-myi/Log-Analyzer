#ifndef LOGFILTER_H
#define LOGFILTER_H

#include "logEntry.h"
#include <vector>
#include <string>

// Filter entries by minimum severity level (returns entries at or above threshold)
std::vector<LogEntry> filterByLevel(const std::vector<LogEntry>& entries, const std::string& minLevel);

// Filter entries by date range (timestamp format: YYYY-MM-DD)
std::vector<LogEntry> filterByDateRange(const std::vector<LogEntry>& entries, const std::string& startDate, const std::string& endDate);

#endif