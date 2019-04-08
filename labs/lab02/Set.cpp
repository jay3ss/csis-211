#include "Set.h"

// Constructor
template <class T>
Set<T>::Set(const int num)
{
    numObjects = num;
    // Allocate memory for the array
    try
    {
        objects = new T[num];
    }
    catch(std::bad_alloc)
    {
        // Do something else here later
        std::cout << "ERROR: Couldn't allocate enough memory.\n";
    }
}

// Copy constructor goes here

// Destructor
template<class T>
Set<T>::~Set()
{
    if (numObjects > 0)
    {
        delete [] objects;
        objects = nullptr;
    }
}