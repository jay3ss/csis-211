cmake_minimum_required(VERSION 3.13.1)
set(CMAKE_CXX_STANDARD 17)
project(lab02)

set(ARRAY_SET_TEST_SOURCES
    arraySetTest.cpp
)

add_executable(arraysettest ${ARRAY_SET_TEST_SOURCES})
target_include_directories(arraysettest
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)
