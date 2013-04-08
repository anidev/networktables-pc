cmake_minimum_required(VERSION 2.8.3)
project(networktables-pc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall -Werror -pedantic -pthread")
file(GLOB_RECURSE SOURCES1 ${PROJECT_SOURCE_DIR}/networktables/*.cpp)
file(GLOB_RECURSE SOURCES2 ${PROJECT_SOURCE_DIR}/networktables2/*.cpp)
file(GLOB_RECURSE SOURCES3 ${PROJECT_SOURCE_DIR}/tables/*.cpp)
file(GLOB_RECURSE SHIM ${PROJECT_SOURCE_DIR}/networktablesshim/*.cpp)
file(GLOB_RECURSE INCLUDESHIM ${PROJECT_SOURCE_DIR}/networktablesshim/*.h)
set(SOURCES
	${SOURCES1}
	${SOURCES2}
	${SOURCES3}
	${SHIM}
)
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/networktablesshim)
add_library(networktables SHARED ${SOURCES})
add_library(networktables_static STATIC ${SOURCES})
add_executable(networktables_test ${PROJECT_SOURCE_DIR}/test/main.cpp)
target_link_libraries(networktables_test networktables_static)
install(TARGETS networktables networktables_static
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
install(FILES ${INCLUDESHIM} DESTINATION include/networktables)
install(DIRECTORY networktables networktables2 tables
	DESTINATION include/networktables
	FILES_MATCHING PATTERN "*.h"
)