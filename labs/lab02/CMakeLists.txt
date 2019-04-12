cmake_minimum_required(VERSION 3.13.1)
set(CMAKE_CXX_STANDARD 17)
project(lab02)

# set(SET_SOURCES
#     lab02set.cpp
#     Set.h
# )
# add_executable(lab02set ${SET_SOURCES})

# set(MATRIX_SOURCES
#     lab02matrix.cpp
#     MatrixInterface.h
#     VectorInterface.h
# )
# add_executable(lab02matrix ${MATRIX_SOURCES})

set(SET_SOURCES
    lab02set.cpp
    Set.h
)
add_executable(lab02set ${SET_SOURCES})
target_include_directories(lab02set
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)

set(VECTOR_SOURCES
    lab02vector.cpp
    VectorInterface.h
)
add_executable(lab02vector ${VECTOR_SOURCES})
target_include_directories(lab02vector
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)

set(MATRIX_SOURCES
    lab02matrix.cpp
    MatrixInterface.h
)
add_executable(lab02matrix ${MATRIX_SOURCES})
target_include_directories(lab02set
    PRIVATE 
        ${PROJECT_SOURCE_DIR}
)