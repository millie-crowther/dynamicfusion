project(dynamicfusion)

set(INCLUDE_DIR
    ../include
)

include_directories(${INCLUDE_DIR})

set(SOURCES
    ../src/main.cpp
)

add_executable(dynamicfusion ${SOURCES})
