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

set(ARRAY_SET_SOURCES
    lab02arrayset.cpp
    SetInterface.h
    ArraySet.h
)
add_executable(lab02arrayset ${ARRAY_SET_SOURCES})
target_include_directories(lab02arrayset
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)

set(ARRAY_BAG_SOURCES
    arraybagtest.cpp
    # Baginterface.h
    ArrayBag.h
)
add_executable(arraybagtest ${ARRAY_BAG_SOURCES})
target_include_directories(arraybagtest
    PRIVATE
        ${PROJECT_SOURCE_DIR}
)

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