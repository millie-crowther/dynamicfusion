cmake_minimum_required(VERSION 3.5)
project(dynamicfusion)

set(INCLUDE_DIR
    ../include
    ../include/nanoflann/include
)

include_directories(${INCLUDE_DIR})

set(SOURCES
    ../src/main.cpp

    ../include/dynamic_fusion.h
    ../src/dynamic_fusion.cpp

    ../include/deform_node.h
    ../include/frame.h
    ../include/typedefs.h
    ../include/warp_field.h
    ../include/nanoflann/include/nanoflann.hpp
)

add_executable(dynamicfusion ${SOURCES})
