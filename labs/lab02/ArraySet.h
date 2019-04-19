/** @file ArraySet.h */
#ifndef _ARRAY_SET_H
#define _ARRAY_SET_H

#include <iostream>
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
    bool isElement(const T &elem)
    {
        // Compare elem to every element in the elements array
        // and immediately return true if elem matches one of
        // the elements of the elements array
        for (int i = 0; i < numElements; i++)
        {
            if (elements[i] == elem)
            {
                return true;
            }
        }

        // elem didn't match an element in the elements array and therefore
        // it isn't an element
        return false;
    }

    /** Returns the the intersection of this set and aSet
     @param aSet the set to check if it is a subset of this set
     @return true if aSet is a subset of this set, false if not */
    bool isSubset(const SetInterface<T> &aSet)
    {
        std::vector<T> aVector = aSet.vector();
        // std::vector<T> thisVector = vector();

        for (auto const &aElem : aVector)
        {
            if (!isElement(aElem))
            {
                return false;
            }
        }

        return true;
    }

    /** Removes the object from the set, if it is present
     @post the element is removed from the set and the number of elements is
        decreased by one (if successful)
     @param elem the object to be removed as a new element of the set
     true if the element was removed, false if it wasn't */
    bool remove(const T &elem)
    {
        // compare each element in the elements array to
        // elem. If a match is found, set the element at
        // the matching index to the last element in the
        // elements array and decrease numElements, and
        // immediately return true
        for (int i = 0; i < numElements; i++)
        {
            if (elements[i] == elem)
            {
                numElements--;
                elements[i] = elements[numElements];

                return true;
            }
        }

        // elem could not be found in the elements array, therefore
        // return false
        return false;
    }

    /** Returns the integer number of elements in the set
     @return The integer number of elements in the set */
    int size() const { return numElements; }

    /** Returns the the union of this set and aSet
     @param aSet the set to form a union with this set
     @return The integer number of elements in the set */
    void unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet)
    {
        // std::vector<T> thisVect = vector();
        std::vector<T> aVector = aSet.vector();
        for (auto const &aElem : aVector)
        {
            unionSet.add(aElem);
        }

        for (int i = 0; i < numElements; i++)
        {
            unionSet.add(elements[i]);
        }
    }

    /** Returns all of the elements in the set as a vector
     @return a vector containing the elements of the set
    */
    std::vector<T> vector() const
    {
        std::vector<T> setVect;

        for (int i = 0; i < numElements; i++)
        {
            setVect.push_back(elements[i]);
        }

        return setVect;
    }

    /** Overloaded << operator to allow printing of ArraySet objects */
    template <class friendT>
    friend std::ostream &operator<<(std::ostream &strm, const ArraySet<friendT> &obj);
private:
    const int DEFAULT_MAX_ELEMENTS = 3;
    T *elements;
    int numElements;
    int maxElements;
};

template<class friendT>
std::ostream &operator<<(std::ostream &strm, const ArraySet<friendT> &obj)
{
    strm << "{";
    for (int i = 0; i < obj.numElements - 1; i++)
    {
        strm << obj.elements[i] << ", ";
    }

    strm << obj.elements[obj.numElements - 1] << "}";
	return strm;
}

// #include "ArraySet.cpp"
#endif // _ARRAY_SET_H