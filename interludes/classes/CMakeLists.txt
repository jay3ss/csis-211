cmake_minimum_required(VERSION 3.5.1)
project(interlude2)
set(CMAKE_CXX_STANDARD 11)

##########################
# MagicBox class-related #
##########################
set(MGC_SOURCES
    testMagicBox.cpp
)
add_executable(testmagicbox ${MGC_SOURCES})
target_include_directories(testmagicbox
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)

##########################
# PlainBox class-related #
##########################
set(PLAIN_SOURCES
    testPlainBox.cpp
)
add_executable(testplainbox ${PLAIN_SOURCES})
target_include_directories(testplainbox
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)