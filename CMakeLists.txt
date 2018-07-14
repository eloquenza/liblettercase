cmake_minimum_required(VERSION 3.11)

if(NOT GIT_RELEASE_STRING)
    find_package(Git)
    if (NOT Git_FOUND)
        message(FATAL "git has not been found, please install git!")
    endif()

    execute_process(
            COMMAND ${GIT_EXECUTABLE} describe --dirty
            OUTPUT_STRIP_TRAILING_WHITESPACE
            OUTPUT_VARIABLE GIT_RELEASE_STRING
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

# faster way of splitting a version string
# after regex replace, matches are safed in ${CMAKE_MATCH_n}, where n is 0 .. 9, 0 being the whole string
# doing it this way makes the whole matching more efficient and, after understanding the trick
# easier to understand and read
string(REGEX REPLACE
        "^([0-9]*)\\.([0-9]*)\\.([0-9]*).*"
        "\\1"
        THROWAWAY_VERSION_STRING
        ${GIT_RELEASE_STRING})

set(MAJOR_VERSION ${CMAKE_MATCH_1})
set(MINOR_VERSION ${CMAKE_MATCH_2})
set(PATCH_VERSION ${CMAKE_MATCH_3})

project(liblettercase VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}
        DESCRIPTION "liblettercase provides letter case conversion functions")

include(CheckIPOSupported)
check_ipo_supported()
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING
            "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
            FORCE)
endif()

message("Build type currently set to ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FOLDER ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_FOLDER ${PROJECT_SOURCE_DIR}/include)
set(TEST_FOLDER ${PROJECT_SOURCE_DIR}/test)
set(BENCHMARK_FOLDER ${PROJECT_SOURCE_DIR}/benchmark)
set(LIB_SOURCES ${SOURCE_FOLDER}/liblettercase)
set(LIB_HEADER ${INCLUDE_FOLDER}/liblettercase)
set(EXTERNAL_LIBS ${PROJECT_SOURCE_DIR}/external)
set(CATCH2_MODULE ${EXTERNAL_LIBS}/catch2)
set(BENCHMARK_MODULE ${EXTERNAL_LIBS}/google-benchmark)

set(BENCHMARK_EXECUTABLE liblettercase-benchmarking)
set(TEST_EXECUTABLE liblettercase-test)
set(LIB_NAME lettercase)

add_subdirectory(${CATCH2_MODULE})
add_subdirectory(${BENCHMARK_MODULE})

add_subdirectory(${SOURCE_FOLDER})
add_subdirectory(${TEST_FOLDER})
add_subdirectory(${BENCHMARK_FOLDER})