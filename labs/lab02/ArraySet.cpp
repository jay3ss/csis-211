#include "ArraySet.h"

// Adds an element to the set, if possible
template <class T>
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

// Returns the the intersection of this set and aSet
template <class T>
bool ArraySet<T>::isSubset(const SetInterface<T> &aSet)
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

// Removes the object from the set, if it is present
template <class T>
bool ArraySet<T>::remove(const T &elem)
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

// Returns the union of this set and aSet
template <class T>
void ArraySet<T>::unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet)
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

// Returns all of the elements in the set as a vector
template <class T>
std::vector<T> ArraySet<T>::vector() const
{
    std::vector<T> setVect;

    for (int i = 0; i < numElements; i++)
    {
        setVect.push_back(elements[i]);
    }

    return setVect;
}

template <class friendT>
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