set(TEST_SOURCES ${TEST_FOLDER}/main.cpp ${TEST_FOLDER}/test_conversions.cpp)

add_executable(${TEST_EXECUTABLE} ${TEST_SOURCES})

target_include_directories(${TEST_EXECUTABLE} PRIVATE ${CATCH2_MODULE}/single_include)
target_link_libraries(${TEST_EXECUTABLE} Catch2::Catch2)
target_link_libraries(${TEST_EXECUTABLE} lettercase)

set_target_properties(${TEST_EXECUTABLE} PROPERTIES OUTPUT_NAME ${TEST_EXECUTABLE}-${GIT_RELEASE_STRING})