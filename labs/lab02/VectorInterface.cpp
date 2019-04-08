#include "VectorInterface.h"

// Overloaded operators
// Overloaded = operator
template <class T>
void VectorInterface<T>::operator=(const VectorInterface<T> &right)
{
    
}

// Overloaded + operator
template <class T>
VectorInterface<T> VectorInterface<T>::operator+(const VectorInterface<T> &right)
{
    VectorInterface temp;
    for (int i = 0; i < numElements; i++)
    {
        temp[i] = elements[i] + right.objects[i];
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

// Overloaded << operator
template<class T>
std::ostream &operator<<(std::ostream &strm, const VectorInterface<T> &obj)
{
    strm << "{";
    for (int i = 0; i < obj.numElements - 1; i++)
    {
        strm << obj.elements[i] << ", ";
    }

    strm << obj.elements[obj.numElements - 1] << "}";
}