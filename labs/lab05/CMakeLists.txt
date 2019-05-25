cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(csis211lab05)

# Create the libraries
add_library(node Node.h)
add_library(listinterface ListInterface.h)
add_library(linkedlist LinkedList.h)
add_library(todoitem TodoItem.cpp)
add_library(todolist TodoList.cpp)

# Tell the linker that the libraries are C++
set_target_properties(
    node
    listinterface
    linkedlist
    PROPERTIES LINKER_LANGUAGE CXX
)

# LinkedList depends on ListInterface
target_link_libraries(linkedlist listinterface node)

# TodoList depends on both LinkedList and TodoItem
target_link_libraries(todolist todoitem linkedlist)

# Create the executable for the Cell class driver and link the library
add_executable(todolistmain todoListMain.cpp)
target_link_libraries(todolistmain todolist todoitem)

# Build the tests
if(BUILD_TESTING)
    message("The first time compiling of tests make take some time...")
    include_directories(external)
    add_library(catch2 external/catch/catch.hpp)
    set_target_properties(catch2 PROPERTIES LINKER_LANGUAGE CXX)

    # Tests
    # Setup for the main file
    add_library(testsmain tests-main.cpp)
    target_link_libraries(testsmain catch2)


    # Test the LinkedList class
    add_executable(testlinkedlist test-linked-list.cpp)
    target_link_libraries(testlinkedlist testsmain linkedlist)

    # Test the TodoList class
    add_executable(testtodolist test-todo-list.cpp)
    target_link_libraries(testtodolist testsmain todolist)

    # Make tests discoverable
    include(CTest)
    # include(Catch)
    # catch_discover_tests(testlinkedlist)

    # use `make test` to run the tests
    enable_testing()
    add_test(NAME LinkedListTest COMMAND testlinkedlist)
    add_test(NAME TodoListTest COMMAND testtodolist)
endif()
