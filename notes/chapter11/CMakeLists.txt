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

add_library(${PROJECT_NAME}_sorters sorters.hpp)
set_target_properties(${PROJECT_NAME}_sorters PROPERTIES LINKER_LANGUAGE CXX)

add_executable(${PROJECT_NAME}_selection_sort_test selectionsorttest.cpp)
target_link_libraries(
    ${PROJECT_NAME}_selection_sort_test
    ${PROJECT_NAME}_sorters
)

add_executable(${PROJECT_NAME}_bubble_sort_test bubblesorttest.cpp)
target_link_libraries(
    ${PROJECT_NAME}_bubble_sort_test
    ${PROJECT_NAME}_sorters
)
