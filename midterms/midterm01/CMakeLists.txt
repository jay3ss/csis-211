cmake_minimum_required(VERSION 3.13.1)
set(CMAKE_CXX_STANDARD 17)
project(midterm01)

set(SET_SOURCES
    lab02set.cpp
    Set.h
)
add_executable(lab02set ${SET_SOURCES})
target_include_directories(lab02set
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)
