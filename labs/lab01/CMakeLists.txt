cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 11)
project(lab01)

set(SOURCES
    lab01.cpp
    liblaboratory.cpp
)
add_executable(lab01 ${SOURCES})