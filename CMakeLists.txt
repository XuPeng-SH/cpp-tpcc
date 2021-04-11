cmake_minimum_required(VERSION 3.5)
project(cpp-tpcc)
set(CMAKE_CXX_STANDARD 17)

aux_source_directory(./ source_files)

include_directories(/usr/include)
include_directories(/usr/local/include)

link_directories(
/usr/lib
/usr/local/lib
)

set(src ${source_files})
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g -fPIC")

add_executable(cpp-tpcc ${src})

set(lab_libs
    gflags
    duckdb)

target_link_libraries(cpp-tpcc ${lab_libs})
