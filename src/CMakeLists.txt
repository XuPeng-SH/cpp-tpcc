set(SOURCE_FILES
    Task.cpp
    Utils.cpp
    TpccFactory.cpp)

add_library(LOCAL_OBJECTS OBJECT ${SOURCE_FILES})
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:LOCAL_OBJECTS>)

# set(CPP_TPCC_LINK_LIBS gflags)

add_library(cpp-tpcc SHARED ${ALL_OBJECT_FILES})
# target_link_libraries(cpp-tpcc ${CPP_TPCC_LINK_LIBS})

# add_library(cpp-tpcc-static STATIC ${ALL_OBJECT_FILES})
# target_link_libraries(cpp-tpcc-static ${CPP_TPCC_LINK_LIBS})

target_include_directories(
    cpp-tpcc PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
