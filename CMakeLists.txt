cmake_minimum_required(VERSION 3.5)

project(cpp-tpcc)

find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MACOSX_RPATH 1)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

option(BUILD_DUCKDB_DRIVER "Build duckdb driver." TRUE)

include_directories(src/include)
add_subdirectory(src)

if(${BUILD_DUCKDB_DRIVER})
    # include_directories(${PROJECT_SOURCE_DIR}/duckdb/include)
    add_subdirectory(duckdb)
    add_definitions(-DBUILD_DUCKDB_DRIVER=${BUILD_DUCKDB_DRIVER})
endif()
