cmake_minimum_required(VERSION 3.11)
project(liblettercase)

set(CMAKE_CXX_STANDARD 17)

set(EXTERNAL_LIBS ./external)
set(CATCH2_MODULE ${EXTERNAL_LIBS}/catch2)

add_subdirectory(${CATCH2_MODULE})
include_directories(${EXTERNAL_LIBS})

set(SOURCES ./src)

add_executable(liblettercase ${SOURCES}/main.cpp)

target_include_directories(liblettercase PRIVATE ${CATCH2_MODULE})
target_link_libraries(liblettercase Catch2::Catch2)