#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <string>

// Validate log level is one of: DEBUG, INFO, WARNING, ERROR
bool validateLogLevel(const std::string& level);

// Validate date string matches YYYY-MM-DD format
bool validateDateFormat(const std::string& date);

// Validate start and end dates are valid and in correct order
bool validateDateRange(const std::string& startDate, const std::string& endDate);

// Validate input string is not empty
bool validateInput(const std::string& input, const std::string& fieldName);

#endif