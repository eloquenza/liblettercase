add_executable(${TEST_EXECUTABLE} ${TEST_SOURCES})

target_include_directories(${TEST_EXECUTABLE} PRIVATE ${CATCH2_MODULE}/single_include)
target_link_libraries(${TEST_EXECUTABLE} Catch2::Catch2)
target_link_libraries(${TEST_EXECUTABLE} lettercase)