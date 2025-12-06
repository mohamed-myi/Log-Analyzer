enable_testing()

set(TEST_SOURCES
    test_logEntry.cpp
    test_logFilter.cpp
    test_errorHandler.cpp
)

foreach(test_src ${TEST_SOURCES})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})
    target_include_directories(${test_name} PRIVATE ${PROJECT_SOURCE_DIR}/src)
    target_link_libraries(${test_name} PRIVATE)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach()