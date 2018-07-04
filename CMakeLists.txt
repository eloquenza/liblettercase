cmake_minimum_required(VERSION 3.11)
project(liblettercase)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FOLDER ./src)
set(INCLUDE_FOLDER ./include)
set(LIB_SOURCES ${SOURCE_FOLDER}/liblettercase)
set(LIB_HEADER ${INCLUDE_FOLDER}/liblettercase)
set(EXTERNAL_LIBS ./external)
set(CATCH2_MODULE ${EXTERNAL_LIBS}/catch2)

add_subdirectory(${CATCH2_MODULE})
include_directories(${EXTERNAL_LIBS})
include_directories(${INCLUDE_FOLDER})

set(SOURCES ${SOURCE_FOLDER}/main.cpp
        ${LIB_HEADER}/ExceptionWords.h ${LIB_SOURCES}/ExceptionWords.cpp
        ${LIB_HEADER}/helper_functions.h ${LIB_SOURCES}/helper_functions.cpp
        ${LIB_HEADER}/lettercase_conversions.h ${LIB_SOURCES}/lettercase_conversions.cpp)

add_executable(liblettercase ${SOURCES})

target_include_directories(liblettercase PRIVATE ${CATCH2_MODULE})
target_link_libraries(liblettercase Catch2::Catch2)