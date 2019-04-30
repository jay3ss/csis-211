cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis211lab03)

add_library(linkedset LinkedSet.h)
add_library(setinterface SetInterface.h)
add_library(node Node.h)

set_target_properties(
    linkedset
    setinterface
    node
    PROPERTIES LINKER_LANGUAGE CXX
)
target_link_libraries(linkedset setinterface node)

add_executable(linkedsettest linkedSetTest.cpp)
target_link_libraries(linkedsettest linkedset)
