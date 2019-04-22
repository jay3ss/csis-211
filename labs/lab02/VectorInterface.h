/* @file VectorInterface.h */
#ifndef _VECTOR_INTERFACE_H
#define _VECTOR_INTERFACE_H

#include <iostream>

template<class T>
class VectorInterface
{
public:
    // Default constructor
    VectorInterface()
        { numElements = DEFAULT_NUM_ELEMS;
          elements = new T[numElements]; }
    
    // Constructor
    VectorInterface(int num)
        { numElements = num;
          elements = new T[numElements]; }

    // Copy constructor
    VectorInterface(const VectorInterface<T>&);

    // Destructor
    ~VectorInterface();

    // Operations
    double norm();
    VectorInterface normalize();

    // Overloaded operators
    // const VectorInterface<T> operator=(const VectorInterface &);
    void operator=(const VectorInterface &);
    VectorInterface operator+(const VectorInterface &);
    VectorInterface operator-(const VectorInterface &);
    VectorInterface operator*(const VectorInterface &);
    T &operator[](const int &);

    // For printing
    template <class friendT>
    friend std::ostream &operator<<(std::ostream &, const VectorInterface<friendT> &);

  private:
    const int DEFAULT_NUM_ELEMS = 3;
    int numElements;
    T *elements;
};

#include "VectorInterface.cpp"
#endif // _VECTOR_INTERFACE_H