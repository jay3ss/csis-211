cmake_minimum_required(VERSION 3.5.1)
set(CMAKE_CXX_STANDARD 11)
project(lab01)

set(SET_SOURCES
    lab02set.cpp
    Set.h
)
add_executable(lab02set ${SET_SOURCES})

# set(MATRIX_SOURCES
#     lab02matrix.cpp
#     MatrixInterface.h
#     VectorInterface.h
# )
# add_executable(lab02matrix ${MATRIX_SOURCES})

# set(SET_SOURCES
#     Set.h
# )
# add_executable(lab02set ${SET_SOURCES})
# target_include_directories(lab02set
#     PRIVATE 
#         ${PROJECT_SOURCE_DIR}
# )

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