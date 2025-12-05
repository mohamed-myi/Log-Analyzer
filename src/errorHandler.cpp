#include "errorHandler.h"
#include <iostream>
#include <sstream>
#include <algorithm>

bool validateLogLevel(const std::string& level) {
    std::vector<std::string> validLevels = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (const auto& validLevel : validLevels) {
        if (level == validLevel) {
            return true;
        }
    }
    
    std::cout << "Error: Invalid log level '" << level << "'. Valid levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
    return false;
}


bool validateDateFormat(const std::string& date) {
    // Validates YYYY-MM-DD format
    if (date.length() != 10) {
        std::cout << "Error: Invalid date format '" << date << "'. Expected YYYY-MM-DD" << std::endl;
        return false;
    }
    
    if (date[4] != '-' || date[7] != '-') {
        std::cout << "Error: Invalid date format '" << date << "'. Expected YYYY-MM-DD" << std::endl;
        return false;
    }
    
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(date[i])) {
            std::cout << "Error: Invalid date format '" << date << "'. Expected YYYY-MM-DD" << std::endl;
            return false;
        }
    }
    
    return true;
}


bool validateDateRange(const std::string& startDate, const std::string& endDate) {
    if (!validateDateFormat(startDate) || !validateDateFormat(endDate)) {
        return false;
    }
    
    if (startDate > endDate) {
        std::cout << "Error: Start date '" << startDate << "' is after end date '" << endDate << "'" << std::endl;
        return false;
    }
    
    return true;
}


bool validateInput(const std::string& input, const std::string& fieldName) {
    if (input.empty()) {
        std::cout << "Error: " << fieldName << " cannot be empty" << std::endl;
        return false;
    }
    
    return true;
}