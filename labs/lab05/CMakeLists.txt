cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis211lab05)

# Create the libraries
add_library(node Node.cpp)
add_library(listinterface ListInterface.h)
add_library(linkedlist LinkedList.cpp)

# Tell the linker that the libraries are C++
set_target_properties(
    listinterface
    PROPERTIES LINKER_LANGUAGE CXX
)

# LinkedList depends on ListInterface
target_link_libraries(linkedlist listinterface node)

# Create the executable for the Cell class driver and link the library
add_executable(todolist todoList.cpp)
target_link_libraries(todolist linkedlist)
