cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis211lab04)

add_library(libcell Cell.cpp)
add_library(libmaze Maze.cpp)

add_executable(celltest cellTest.cpp)
target_link_libraries(celltest libcell)

add_executable(stackmazetest stackMazeTest.cpp)
target_link_libraries(stackmazetest libmaze)
