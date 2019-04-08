#ifndef _MATRIX_INTERFACE_H
#define _MATRIX_INTERFACE_H

#include "VectorInterface.h"

template<class T>
class MatrixInterface
{
public:
private:
    int numColumns;     // number of columns
    int numRows;        // number of rows
    T* columns;         // templated array of columns
    T* rows;            // templated array of rows
};

#endif // _MATRIX_INTERFACE_H