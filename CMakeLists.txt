cmake_minimum_required(VERSION 3.10)
project(LogAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

include_directories(${PROJECT_SOURCE_DIR}/src)

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

add_executable(logAnalyzer ${SOURCES})

enable_testing()
add_subdirectory(tests)