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
    { elements = new T[maxElements]; }

    ArraySet(const int setSize) : numElements(0), maxElements(setSize)
    { elements = new T[maxElements]; }

    ~ArraySet()
    { delete [] elements;
      elements = nullptr; }

    /** Adds an element to the set, if possible
     @post The element is added to the set and the number of elements is
        increased by one (if successful)
     @param elem The object to be added as a new element of the set
     @return true if the element was added, false if it wasn't */
    bool add(const T &elem);

    /** Returns the intersection of this set and aSet
     @pre The parameter interSet's size must be large enough to accommodate
        number of elements (size()) of both this set and aSet. Otherwise, the
        addition of the elements (i.e., not all of the elements in the
        intersection will be added to interSet)
     @param aSet The set to form an intersection with this set
     @param interSet Reference to the set that will be the intersection of this
        set and aSet.
     @return The ArraySet (interSet) containing the intersection of this set
        and aSet */
    void intersection(const SetInterface<T> &aSet, SetInterface<T> &interSet);

    /** Checks if an object is an element to the set
     @param elem The object to be checked if it is an element of the set
     @return true if elem is an element of this set, false if not */
    bool isElement(const T &elem);

    /** Returns the the intersection of this set and aSet
     @param aSet the set to check if it is a subset of this set
     @return true if aSet is a subset of this set, false if not */
    bool isSubset(const SetInterface<T> &aSet)
    {
        std::vector<T> aVector = aSet.vector();

        // Cycle through each element in aVector and check if each one is in
        // this set. If it is, then aSet is a subset. If any element of aSet is
        // not in this set, then aSet is not a subset of this set and return
        // false immediately.
        for (auto const &aElem : aVector)
        {
            if (!isElement(aElem))
            {
                return false;
            }
        }

        // Every element of aSet is in this set, therefore, aSet is a subset of
        // this set. So, return true
        return true;
    }

    /** Removes the object from the set, if it is present
     @post The element is removed from the set and the number of elements is
        decreased by one (if successful)
     @param elem The object to be removed from the set
     @return true if the element was removed, false if it wasn't */
    bool remove(const T &elem)
    {
        // Compare each element in the elements array to elem. If a match is
        // found, set the element at the matching index to the last element in
        // the elements array and decrease numElements, and immediately return
        // true
        for (int i = 0; i < numElements; i++)
        {
            if (elements[i] == elem)
            {
                numElements--;
                elements[i] = elements[numElements];

                return true;
            }
        }

        // elem could not be found in the elements array, therefore return
        // false
        return false;
    }

    /** Returns the integer number of elements in the set
     @return The integer number of elements in the set */
    int size() const { return numElements; }

    /** Returns the union of this set and aSet
     @pre The parameter unionSet's size must be large enough to accommodate
        number of elements (size()) of both this set and aSet. Otherwise, the
        addition of the elements from both sets will fail (i.e., not all of
        the elements in the union will be added to unionSet)
     @param aSet Reference to the set to form a union with this set.
     @param unionSet Reference to the set that will be the union of this set
        and aSet.
     @return The ArraySet (unionSet) containing the union of this set and
        aSet */
    void unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet)
    {
        // Go through each this set and aSet and each the elements from each to
        // unionSet (the union of both this set and aSet)
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
     @return A vector containing the elements of the set */
    std::vector<T> vector() const
    {
        std::vector<T> setVect;

        for (int i = 0; i < numElements; i++)
        {
            setVect.push_back(elements[i]);
        }

        return setVect;
    }

    /** Overloaded << operator to allow easy printing of ArraySet objects
     @param strm Reference to the ostream object
            obj Reference to the ArraySet object that's being printed
     @return The  ostream object (strm) */
    template <class friendT>
    friend std::ostream &operator<<(std::ostream &strm, const ArraySet<friendT> &obj);
private:
    const int DEFAULT_MAX_ELEMENTS = 3;
    T *elements;
    int numElements;
    int maxElements;
};

// Adds an element to the set, if possible
template<class T>
bool ArraySet<T>::add(const T &elem)
{
    bool canAdd = (numElements < maxElements) && !isElement(elem);
    if (canAdd)
    {
        elements[numElements] = elem;
        numElements++;
    }

    return canAdd;
}

// Returns the intersection of this set and aSet
template <class T>
void ArraySet<T>::intersection(const SetInterface<T> &aSet, SetInterface<T> &interSet)
{
    // Get the vector from aSet (aVector) and iterate through each element
    // in the vector. Compare each element in aVect and compare it to every
    // element in the elements array to find duplicates. Add all of the
    // duplicates to the intersection set (interSet) and this is the
    // intersection between this set and aSet.
    std::vector<T> aVector = aSet.vector();
    for (auto const &aElem : aVector)
    {
        for (int i = 0; i < numElements; i++)
        {
            if (aElem == elements[i])
            {
                interSet.add(aElem);
            }
        }
    }
}

// Checks if an object is an element to the set
template <class T>
bool ArraySet<T>::isElement(const T &elem)
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
    // it isn't an element and return false
    return false;
}

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