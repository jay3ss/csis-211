#include <iostream>
#include <new>

#include "Set.h"

// Constructor
template <class T>
Set<T>::Set(const int num)
{
    numObjects = 0;
    maxObjects = num;
    // Allocate memory for the array
    try
    {
        objects = new T[maxObjects];
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

// Adds a new element to the set. If the element isn't already in the set,
// the element is added and the function returns true. Otherwise, the
// element isn't added and the function returns false.
//
// NOTE: the problem with this is that we don't automatically resize the
// objects array so that we can add the new element to the set (if
// possible).
template<class T>
bool Set<T>::add(const T& elem)
{
    bool canAdd = numObjects < maxObjects;
    if (!isIn(elem) && canAdd)
    {
        objects[numObjects] = elem;
        numObjects++;
    }

    return canAdd;
}

// Adds 
template <class T>
bool Set<T>::add(const T *arr, const int arrSize)
{
    // Check how many new elements are attempted to be added
    int numNewObjs = 0;
    for (int i = 0; i < arrSize; i++)
    {
        if (!isIn(arr[i]))
        {
            numNewObjs++;
        }
    }

    std::cout << "Number of new to objects to be added: " << numNewObjs << "\n";

    // Do we have to resize the objects array?
    // NOTE: There's an error here. Too much space is being allocated
    int sizeDiff = numNewObjs - (maxObjects - numObjects) - 1;
    
    std::cout << "Size difference is " << sizeDiff << "\n";

    if (sizeDiff > 0)
    {
        maxObjects += sizeDiff;
        // resize the objects array
        resize(maxObjects);
    }

    // Add the new objects
    for (int i = numObjects - 1, j = 0; j < arrSize; i++, j++)
    {
        // std::cout << "arr[j] = " << arr[j] << "\n";
        add(arr[j]);
    }
}

template<class T>
void Set<T>::resize(const int s)
{
    T *tempObjects = nullptr;
    tempObjects = new T[s];

    for (int i = 0; i < numObjects; i++)
    {
        tempObjects[i] = objects[i];
    }

    delete [] objects;
    // objects = nullptr;
    objects = new T[s];

    for (int i = 0; i < numObjects; i++)
    {
        objects[i] = tempObjects[i];
    }

    delete[] tempObjects;
    tempObjects = nullptr;
}

// Checks if an object is in the set. Returns true if it is in the set,
// returns false otherwise.
template <class T>
bool Set<T>::isIn(const T &elem)
{
    for (int i = 0; i < numObjects; i++)
    {
        if (elem == objects[i])
        {
            return true;
        }
    }
    return false;
}

// :::NOT IMPLEMENTED:::
// Removes an element from the set. If the element isn't in the set, the
// function returns false. Otherwise, if the element is in the set, the
// it is removed and the function returns false.
//
// NOTE: the problem with this is that we don't automatically resize the
// objects array so that we can add the new element to the set (if possible).
template <class T>
bool Set<T>::remove(const T &elem)
{
    bool canRemove = isIn(elem);

    if (isIn(elem))
    {
        int index = getIndexOf(elem);
        numObjects--;
        objects[index] = objects[numObjects];
    }

    return canRemove;
}

template<class T>
int Set<T>::getIndexOf(const T& elem)
{
    int index = -1;
    if (isIn(elem))
    {
        for (int i = 0; i < numObjects; i++)
        {
            if (elem == objects[i])
            {
                return i;
            }
        }
    }

    return index;
}

template <class friendT>
std::ostream &operator<<(std::ostream &strm, const Set<friendT> &obj)
{
    strm << "{";
    for (int i = 0; i < obj.numObjects - 1; i++)
    {
        strm << obj.objects[i] << ", ";
    }

    strm << obj.objects[obj.numObjects - 1] << "}";
}
