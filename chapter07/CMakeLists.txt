cmake_minimum_required(VERSION 3.10.1)
set(CMAKE_CXX_STANDARD 17)
project(chapter07)

set(ARRAY_STACK_SRC
    arrayStackTest.cpp
)

add_executable(arraystacktest ${ARRAY_STACK_SRC})
target_include_directories(arraystacktest
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)
