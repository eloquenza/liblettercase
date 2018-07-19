set(TEST_SOURCES ${TEST_FOLDER}/main.cpp ${TEST_FOLDER}/test_conversions.cpp
        ${TEST_FOLDER}/test_helper_functions.cpp)
set(TEST_OUTPUT_NAME ${TEST_EXECUTABLE}-${GIT_RELEASE_STRING})

add_executable(${TEST_EXECUTABLE} ${TEST_SOURCES})

target_include_directories(${TEST_EXECUTABLE} PRIVATE ${CATCH2_MODULE}/single_include)
target_link_libraries(${TEST_EXECUTABLE} Catch2::Catch2)
target_link_libraries(${TEST_EXECUTABLE} lettercase)

set_target_properties(${TEST_EXECUTABLE} PROPERTIES OUTPUT_NAME ${TEST_OUTPUT_NAME})

add_custom_command(TARGET ${TEST_EXECUTABLE} POST_BUILD
        COMMAND cp ${TEST_OUTPUT_NAME} ${BINARY_FOLDER}/${TEST_EXECUTABLE}
        WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        COMMENT "[POST-BUILD] Copying the test executable to a easier accessible folder \
for automated scripts (i.e. pre-commit test hook).")