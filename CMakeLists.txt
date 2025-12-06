cmake_minimum_required(VERSION 3.10)
project(LogAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/logParser.cpp
    src/logEntry.cpp
    src/logAnalyzer.cpp
    src/logFilter.cpp
    src/fileReader.cpp
    src/argParser.cpp
    src/errorHandler.cpp
)

set(HEADERS
    include/logParser.h
    include/logEntry.h
    include/logAnalyzer.h
    include/logFilter.h
    include/fileReader.h
    include/argParser.h
    include/errorHandler.h
)

add_executable(logAnalyzer ${SOURCES} ${HEADERS})

enable_testing()

set(TEST_SOURCES
    tests/test_logEntry.cpp
    tests/test_logFilter.cpp
    tests/test_logAnalyzer.cpp
    tests/test_errorHandler.cpp
    src/logEntry.cpp
    src/logAnalyzer.cpp
    src/logFilter.cpp
    src/fileReader.cpp
    src/errorHandler.cpp
    src/logParser.cpp
)

add_executable(runTests ${TEST_SOURCES})

add_test(NAME LogAnalyzerTests COMMAND runTests)