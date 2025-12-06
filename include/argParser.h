#ifndef ARGPARSER_H
#define ARGPARSER_H

#include <string>

struct Arguments {
    std::string logFile;
    std::string filterLevel;
    std::string startDate;
    std::string endDate;
    std::string outputFormat;
    bool validArgs;
    bool showStats;
    bool showErrors;
    bool showHelp;
};

// Parse command-line arguments into Arguments struct
Arguments parseArgs(int argc, char* argv[]);

// Display help message with usage and examples
void displayHelp(const std::string& programName);

#endif