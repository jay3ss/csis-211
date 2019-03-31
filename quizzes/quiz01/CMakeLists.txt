cmake_minimum_required(VERSION 3.5.1)
project(classes_interlude)
set(CMAKE_CXX_STANDARD 11)

set(SOURCES main.cpp Rectangle.cpp)
add_executable(main ${SOURCES})