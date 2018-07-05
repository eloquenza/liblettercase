set(SOURCES ${LIB_HEADER}/ExceptionWords.h ${LIB_SOURCES}/ExceptionWords.cpp
        ${LIB_HEADER}/helper_functions.h ${LIB_SOURCES}/helper_functions.cpp
        ${LIB_HEADER}/lettercase_conversions.h ${LIB_SOURCES}/lettercase_conversions.cpp)

add_library(${LIB_NAME} SHARED
        ${SOURCES})
set_target_properties(${LIB_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_FOLDER})
target_include_directories(${LIB_NAME} PRIVATE ${EXTERNAL_LIBS})