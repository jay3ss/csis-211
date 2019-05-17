cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(chapter11notes)

include_directories(include)

# add_library(${PROJECT_NAME}_square
# 	src/square.cpp
# )

# target_link_libraries(mainsquare ${PROJECT_NAME}_square)
# add_executable(mainsquare src/main.cpp)

add_library(${PROJECT_NAME}_selectionsort selectionsort.cpp)
add_executable(${PROJECT_NAME}_selection_sort_test selectionsorttest.cpp)
target_link_libraries(
    ${PROJECT_NAME}_selection_sort_test
    ${PROJECT_NAME}_selectionsort
)
