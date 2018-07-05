add_library(${LIB_NAME} SHARED
        ${SOURCES})
set_target_properties(${LIB_NAME} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})
target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_FOLDER})
target_include_directories(${LIB_NAME} PRIVATE ${EXTERNAL_LIBS})