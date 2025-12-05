#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string>
#include <vector>
#include "logEntry.h"

// Validates log level string, returns true if valid
bool validateLogLevel(const std::string& level);

// Validates date format (YYYY-MM-DD), returns true if valid
bool validateDateFormat(const std::string& date);

// Validates date range (start <= end), returns true if valid
bool validateDateRange(const std::string& startDate, const std::string& endDate);

// Validates input is not empty, returns true if valid
bool validateInput(const std::string& input, const std::string& fieldName);

#endif