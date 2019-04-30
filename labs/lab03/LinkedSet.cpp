#include "LinkedSet.h"

// Destructor
template<class T>
LinkedSet<T>::~LinkedSet()
{
}

// Adds an element to the set, if possible
template <class T>
bool LinkedSet<T>::add(const T &elem)
{
    return false;
}

// Returns the intersection of this set and aSet
template <class T>
void LinkedSet<T>::intersection(const SetInterface<T> &aSet, SetInterface<T> &interSet)
{
}

// Checks if an object is an element to the set
template <class T>
bool LinkedSet<T>::isElement(const T &elem)
{
    return false;
}

// Returns the the intersection of this set and aSet
template <class T>
bool LinkedSet<T>::isSubset(const SetInterface<T> &aSet)
{
    return false;
}

// Removes the object from the set, if it is present
template <class T>
bool LinkedSet<T>::remove(const T &elem)
{
    return false;
}

// Returns the union of this set and aSet
template <class T>
void LinkedSet<T>::unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet)
{
}

// Returns all of the elements in the set as a vector
template <class T>
std::vector<T> LinkedSet<T>::vector() const
{
    return std::vector<T>();
}

template <class friendT>
std::ostream &operator<<(std::ostream &strm, const LinkedSet<friendT> &obj)
{
    // Enter the elements to the osftream object (strm) so that the set will be
    // printed in the following format:
    // { elem1, elem2, ..., elemN}
    // where each elemI is an element in the elements array
    return strm;
}
