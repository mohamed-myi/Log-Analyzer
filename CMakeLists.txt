cmake_minimum_required(VERSION 3.10)
project(LogAnalyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/logParser.cpp
)

# Header files directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Create executable
add_executable(logAnalyzer ${SOURCES})

# Compiler flags for warnings
if(MSVC)
    target_compile_options(logAnalyzer PRIVATE /W4)
else()
    target_compile_options(logAnalyzer PRIVATE -Wall -Wextra -Wpedantic)
endif()