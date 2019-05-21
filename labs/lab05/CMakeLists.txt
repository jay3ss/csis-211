cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis211lab05)

# Create the libraries
add_library(node Node.h)
add_library(listinterface ListInterface.h)
add_library(linkedlist LinkedList.h)

# Tell the linker that the libraries are C++
set_target_properties(
    node
    listinterface
    linkedlist
    PROPERTIES LINKER_LANGUAGE CXX
)

# LinkedList depends on ListInterface
target_link_libraries(linkedlist listinterface node)

# Create the executable for the Cell class driver and link the library
add_executable(todolist todoList.cpp)
target_link_libraries(todolist linkedlist)

# Build the tests
if(BUILD_TESTING)
    include_directories(external)
    # Tests
    # Setup for the main file
    add_library(testsmain tests-main.cpp)
    target_link_libraries(testsmain Catch2::Catch2)

    # Test the Cell class
    add_executable(testlinkedlist test-linked-list.cpp)
    target_link_libraries(testlinkedlist testsmain)

    # Make tests discoverable
    # include(CTest)
    # include(Catch)
    # catch_discover_tests(testlinkedlist)

    # use `make test` to run the tests
    enable_testing()
    add_test(NAME LinkedListTest COMMAND testlinkedlist)
endif()
