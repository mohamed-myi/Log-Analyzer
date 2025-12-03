#include "argParser.h"
#include <iostream>
#include <algorithm>

Arguments parseArgs(int argc, char* argv[]) {
    Arguments args;
    args.validArgs = true;
    args.showStats = false;
    args.showErrors = false;
    args.showHelp = false;
    args.outputFormat = "table";

    if (argc < 2) {
        args.validArgs = false;
        args.showHelp = true;
        return args;
    }

    args.logFile = argv[1];

    for (int i = 2; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "-h" || arg == "--help") {
            args.showHelp = true;
        }
        else if (arg == "-s" || arg == "--stats") {
            args.showStats = true;
        }
        else if (arg == "-e" || arg == "--errors") {
            args.showErrors = true;
        }
        else if (arg == "-l" || arg == "--level") {
            if (i + 1 < argc) {
                args.filterLevel = argv[++i];
            }
        }
        else if (arg == "-sd" || arg == "--start-date") {
            if (i + 1 < argc) {
                args.startDate = argv[++i];
            }
        }
        else if (arg == "-ed" || arg == "--end-date") {
            if (i + 1 < argc) {
                args.endDate = argv[++i];
            }
        }
        else if (arg == "-f" || arg == "--format") {
            if (i + 1 < argc) {
                args.outputFormat = argv[++i];
            }
        }
    }

    return args;
}


void displayHelp(const std::string& programName) {
    // Display available command-line options and usage examples
    std::cout << "\n=== Log Analyzer ===" << std::endl;
    std::cout << "Usage: " << programName << " <log_file> [options]" << std::endl;
    std::cout << "\nOptions:" << std::endl;
    std::cout << "  -h, --help              Show this help message" << std::endl;
    std::cout << "  -s, --stats             Display statistics by log level" << std::endl;
    std::cout << "  -e, --errors            Show errors only" << std::endl;
    std::cout << "  -l, --level LEVEL       Filter by log level (DEBUG/INFO/WARNING/ERROR)" << std::endl;
    std::cout << "  -sd, --start-date DATE  Filter from date (YYYY-MM-DD)" << std::endl;
    std::cout << "  -ed, --end-date DATE    Filter to date (YYYY-MM-DD)" << std::endl;
    std::cout << "  -f, --format FORMAT     Output format: table or json (default: table)" << std::endl;
    std::cout << "\nExamples:" << std::endl;
    std::cout << "  " << programName << " app.log --stats" << std::endl;
    std::cout << "  " << programName << " app.log --level ERROR" << std::endl;
    std::cout << "  " << programName << " app.log --start-date 2024-01-01 --end-date 2024-01-31" << std::endl;
    std::cout << std::endl;
}