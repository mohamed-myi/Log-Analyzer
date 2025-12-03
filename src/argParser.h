#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <string>
#include <vector>

// Represents parsed command-line arguments
struct Arguments {
    std::string logFile;          // Path to log file
    std::string filterLevel;      // Filter by log level
    std::string startDate;        // Filter start date (YYYY-MM-DD)
    std::string endDate;          // Filter end date (YYYY-MM-DD)
    std::string outputFormat;     // Output format (table/json)
    bool showStats;               // Show statistics flag
    bool showErrors;              // Show errors only flag
    bool showHelp;                // Show help flag
    bool validArgs;               // Whether arguments were parsed successfully
};

// Parse command-line arguments and return Arguments struct
Arguments parseArgs(int argc, char* argv[]);

// Display help message with available options
void displayHelp(const std::string& programName);

#endif