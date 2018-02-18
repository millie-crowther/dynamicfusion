cmake_minimum_required(VERSION 3.5)
set (CMAKE_CXX_STANDARD 11)

project(dynamicfusion)

find_package(Ceres REQUIRED)

set(INCLUDE_DIR
    ../include
    ../include/nanoflann/include
    ${CERES_INCLUDE_DIRS}
)

include_directories(${INCLUDE_DIR})

set(SOURCES
    ../src/main.cpp

    ../include/point.h
    ../src/point.cpp

    ../include/dual_quat.h
    ../src/dual_quat.cpp

    ../include/dynamic_fusion.h
    ../src/dynamic_fusion.cpp

    ../include/deform_node.h
    ../src/deform_node.cpp

    ../include/frame.h

    ../include/warp_field.h
    ../src/warp_field.cpp

    ../include/nanoflann/include/nanoflann.hpp
)

add_executable(dynamicfusion ${SOURCES})
target_link_libraries(dynamicfusion ${CERES_LIBRARIES})

