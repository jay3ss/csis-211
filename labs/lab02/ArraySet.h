/** @file ArraySet.h */
#ifndef _ARRAY_SET_H
#define _ARRAY_SET_H

#include "SetInterface.h"

template<class T>
class ArraySet : public SetInterface<T>
{
public:
    ArraySet() : numElements(0), maxElements(DEFAULT_MAX_ELEMENTS)
    {
        elements = new T[maxElements];
    }
    ArraySet(const int setSize) : numElements(0), maxElements(setSize)
    {
        elements = new T[maxElements];
    }
    ~ArraySet()
    {
        delete [] elements;
        elements = nullptr;
    }
    /** Adds an element to the set, if possible
     @post the element is added to the set and the number of elements is
        increased by one (if successful)
     @param elem the object to be added as a new element of the set
     @return true if the element was added, false if it wasn't */
    bool add(const T &elem)
    {
        // bool isIn = ;
        bool canAdd = (numElements < maxElements) && !isElement(elem);
        if (canAdd)
        {
            elements[numElements] = elem;
            numElements++;
        }

        return canAdd;
    }

    /** Returns the the intersection of this set and aSet
     @param aSet the set to form an intersection with this set
     @return The integer number of elements in the set */
    void intersection(const SetInterface<T> &aSet, SetInterface<T> &interSet)
    { /* NOT IMPLEMENTED*/}

    /** Checks if an object is an element to the set
     @param elem the object to be checked if it is an element of the set
     @return true if elem is an element of this set, false if not */
    bool isElement(const T &elem) { return true; }

    /** Returns the the intersection of this set and aSet
     @param aSet the set to check if it is a subset of this set
     @return true if aSet is a subset of this set, false if not */
    bool isSubset(const SetInterface<T> &aSet) { return false; }

    /** Removes the object from the set, if it is present
     @post the element is removed from the set and the number of elements is
        decreased by one (if successful)
     @param elem the object to be removed as a new element of the set
     true if the element was removed, false if it wasn't */
    bool remove(const T &elem) { return false; }

    /** Returns the integer number of elements in the set
     @return The integer number of elements in the set */
    int size() const { return numElements; }

    /** Returns the the union of this set and aSet
     @param aSet the set to form a union with this set
     @return The integer number of elements in the set */
    void unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet)
    {
        // NOT IMPLEMENTED
    }
private:
    const int DEFAULT_MAX_ELEMENTS = 3;
    T *elements;
    int numElements;
    int maxElements;
};

// #include "ArraySet.cpp"
#endif // _ARRAY_SET_H