#include <iostream>
#include <string>
#include <map>
#include "fileReader.h"
#include "logParser.h"
#include "logAnalyzer.h"
#include "logFilter.h"

void displayMenu() {
    // Display interactive menu options for user
    std::cout << "\n=== Log Analyzer ===" << std::endl;
    std::cout << "1. View all statistics" << std::endl;
    std::cout << "2. Filter by log level" << std::endl;
    std::cout << "3. Filter by date range" << std::endl;
    std::cout << "4. View errors by source" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Select option: ";
}


void handleUserInput(int option, std::vector<LogEntry>& entries) {
    // Process user selection and execute corresponding analysis
    std::string level, startDate, endDate;
    std::vector<LogEntry> filtered;
    std::map<std::string, int> stats;

    switch(option) {
        case 1: {
            stats = getStatsByLevel(entries);
            std::cout << "\n--- Statistics by Level ---" << std::endl;
            for (const auto& pair : stats) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
            break;
        }
        case 2: {
            std::cout << "Enter minimum level (DEBUG/INFO/WARNING/ERROR): ";
            std::cin >> level;
            filtered = filterByLevel(entries, level);
            std::cout << "Found " << filtered.size() << " entries at or above " << level << std::endl;
            break;
        }
        case 3: {
            std::cout << "Enter start date (YYYY-MM-DD): ";
            std::cin >> startDate;
            std::cout << "Enter end date (YYYY-MM-DD): ";
            std::cin >> endDate;
            filtered = filterByDateRange(entries, startDate, endDate);
            std::cout << "Found " << filtered.size() << " entries in date range" << std::endl;
            break;
        }
        case 4: {
            stats = getErrorsBySource(entries);
            std::cout << "\n--- Errors by Source ---" << std::endl;
            for (const auto& pair : stats) {
                std::cout << pair.first << ": " << pair.second << " errors" << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Exiting..." << std::endl;
            break;
        }
        default: {
            std::cout << "Invalid option" << std::endl;
        }
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: logAnalyzer <log_file>" << std::endl;
        return 1;
    }

    std::string logFile = argv[1];
    
    if (!checkFile(logFile)) {
        std::cout << "Error: File not found or not readable" << std::endl;
        return 1;
    }

    std::cout << "Log Analyzer initialized for: " << logFile << std::endl;

    std::vector<LogEntry> entries = parseLog(logFile);
    std::cout << "Parsed " << entries.size() << " log entries" << std::endl;

    int option = 0;
    while (option != 5) {
        displayMenu();
        std::cin >> option;
        handleUserInput(option, entries);
    }

    return 0;
}