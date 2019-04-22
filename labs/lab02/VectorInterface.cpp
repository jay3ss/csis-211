#include "VectorInterface.h"
#include <cmath>
#include <iterator>

// Copy constructor
template<class T>
VectorInterface<T>::VectorInterface(const VectorInterface<T> &obj)
{
    numElements = obj.numElements;
    elements = new T[numElements];

    for (int i = 0; i < numElements; i++)
    {
        elements[i] = obj.elements[i];
        // *(elements + i) = *(obj.elements + i);
    }
}

// Destructor
template<class T>
VectorInterface<T>::~VectorInterface()
{
    if (numElements > 0)
    {
        delete [] elements;
    }
}

// Norm
template<class T>
double VectorInterface<T>::norm()
{
    if (numElements == 0)
    {
        return 0;
    }

    double n = 0;
    for (int i = 0; i < numElements; i++)
    {
        n += elements[i] * elements[i];
    }

    return sqrt(n);
}

template<class T>
VectorInterface<T> VectorInterface<T>::normalize()
{
    VectorInterface<T> temp(numElements);
    double tempNorm = norm();

    for (int i = 0; i < numElements; i++)
    {
        
    }

    return temp;
}
// Overloaded operators
// Overloaded = operator
template <class T>
// const VectorInterface<T> VectorInterface<T>::operator=(const VectorInterface<T> &right)
void VectorInterface<T>::operator=(const VectorInterface<T> &right)
{
    // delete [] elements;
    // numElements = right.numElements;

    // elements = new T[numElements];

    for (int i = 0; i < numElements; i++)
    {
        elements[i] = right.elements[i];
    }

    // return *this;
}

// Overloaded + operator
template <class T>
VectorInterface<T> VectorInterface<T>::operator+(const VectorInterface<T> &right)
{
    int tempNumElems = right.numElements;
    VectorInterface temp(tempNumElems);
    for (int i = 0; i < numElements; i++)
    {
        temp.elements[i] = elements[i] + right.elements[i];
    }

    return temp;
}

// Overloaded - operator
template <class T>
VectorInterface<T> VectorInterface<T>::operator-(const VectorInterface<T> &right)
{
    int tempNumElems = right.numElements;
    VectorInterface temp(tempNumElems);
    for (int i = 0; i < numElements; i++)
    {
        temp[i] = elements[i] - right.elements[i];
    }

    return temp;
}

// Overloaded - operator
template <class T>
VectorInterface<T> VectorInterface<T>::operator*(const VectorInterface<T> &right)
{
    int tempNumElems = right.numElements;
    VectorInterface temp(tempNumElems);
    for (int i = 0; i < numElements; i++)
    {
        temp[i] = elements[i] * right.elements[i];
    }

    return temp;
}

// Overloaded [] operator
template <class T>
T &VectorInterface<T>::operator[](const int &sub)
{
    if (sub < 0 || sub >= numElements) 
    { /* ::IMPLEMENT ERROR FUNCTION HERE:: */ }

    return elements[sub];
}

template <class friendT>
std::ostream &operator<<(std::ostream &strm, const VectorInterface<friendT> &obj)
{
    strm << "{";
    for (int i = 0; i < obj.numElements - 1; i++)
    {
        strm << obj.elements[i] << ", ";
    }

    strm << obj.elements[obj.numElements - 1] << "}";
}

// Overloaded << operator
// template<class T>
// std::ostream &operator<<(std::ostream &strm, const VectorInterface<T> &obj)
// {
    // strm << "{";
    // for (int i = 0; i < obj.numElements - 1; i++)
    // {
    //     strm << obj.elements[i] << ", ";
    // }

    // strm << obj.elements[obj.numElements - 1] << "}";
// }