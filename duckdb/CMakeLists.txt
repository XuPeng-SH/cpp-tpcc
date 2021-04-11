find_package(duckdb REQUIRED)
find_package(gflags REQUIRED)

include_directories(.)
include_directories(/usr/local/include)

add_executable(duckdb-tpcc main.cpp
    DuckdbDriver.cpp)

target_link_libraries(duckdb-tpcc
    cpp-tpcc
    gflags
    duckdb)
