set(BENCHMARK_SOURCES ${BENCHMARK_FOLDER}/main.cpp)
set(BENCHMARK_ENABLE_LTO true)
set(BENCHMARK_OUTPUT_NAME ${BENCHMARK_EXECUTABLE}-${GIT_RELEASE_STRING})

add_executable(${BENCHMARK_EXECUTABLE} ${BENCHMARK_SOURCES})

target_include_directories(${BENCHMARK_EXECUTABLE} PRIVATE ${BENCHMARK_MODULE}/include)
target_link_libraries(${BENCHMARK_EXECUTABLE} benchmark)
target_link_libraries(${BENCHMARK_EXECUTABLE} lettercase)

set_target_properties(${BENCHMARK_EXECUTABLE} PROPERTIES
        OUTPUT_NAME ${BENCHMARK_OUTPUT_NAME})

add_custom_command(TARGET ${BENCHMARK_EXECUTABLE} POST_BUILD
        COMMAND cp ${BENCHMARK_OUTPUT_NAME} ${BINARY_FOLDER}/${BENCHMARK_EXECUTABLE}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        COMMENT "[POST-BUILD] Copying the benchmarl executable to a easier accessible folder \
for automated scripts (i.e. git hooks).")