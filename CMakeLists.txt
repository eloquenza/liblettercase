cmake_minimum_required(VERSION 3.11)
project(liblettercase VERSION 1.0.0
        DESCRIPTION "liblettercase provides letter case conversion functions")

if( NOT CMAKE_BUILD_TYPE )
    set( CMAKE_BUILD_TYPE Debug CACHE STRING
            "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
            FORCE )
endif()

message("Build type currently set to ${CMAKE_BUILD_TYPE}")

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FOLDER ${PROJECT_SOURCE_DIR}/src)
set(INCLUDE_FOLDER ${PROJECT_SOURCE_DIR}/include)
set(TEST_FOLDER ${PROJECT_SOURCE_DIR}/test)
set(LIB_SOURCES ${SOURCE_FOLDER}/liblettercase)
set(LIB_HEADER ${INCLUDE_FOLDER}/liblettercase)
set(EXTERNAL_LIBS ./external)
set(CATCH2_MODULE ${EXTERNAL_LIBS}/catch2)

set(SOURCES ${LIB_HEADER}/ExceptionWords.h ${LIB_SOURCES}/ExceptionWords.cpp
        ${LIB_HEADER}/helper_functions.h ${LIB_SOURCES}/helper_functions.cpp
        ${LIB_HEADER}/lettercase_conversions.h ${LIB_SOURCES}/lettercase_conversions.cpp)

set(TEST_SOURCES ${TEST_FOLDER}/main.cpp ${TEST_FOLDER}/test_conversions.cpp)

set(TEST_EXECUTABLE liblettercase-test)
set(LIB_NAME lettercase)

add_subdirectory(${CATCH2_MODULE})
add_subdirectory(${SOURCE_FOLDER})
add_subdirectory(${TEST_FOLDER})