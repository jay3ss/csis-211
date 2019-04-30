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
    // Create a new node of type T and instantiate it
    // with the element to be added and the head pointer.
    // Don't forget to increase the count of the number of
    // elements in the set
    Node<T>* toAdd = new Node<T>(elem, head);
    head = toAdd;
    numElements++;

    return true;
}

// Returns the intersection of this set and aSet
template <class T>
void LinkedSet<T>::intersection(const SetInterface<T> &aSet, SetInterface<T> &interSet)
{
}

// Checks if an object is an element to the set
template <class T>
bool LinkedSet<T>::isElement(const T &elem) const
{
    // Copy the head pointer so that we can step through each node
    // in the set without modifying anything
    Node<T>* currNodePtr = head;
    int count = 0;  // To make sure that we don't go past the last node

    // Go through each node in the set and compare it with the passed in
    // element. If a node contains the element that we're checking, then
    // immediately return true. If we check every node and don't find
    // any matches, then return false
    while (currNodePtr != nullptr && count < numElements)
    {
        if (currNodePtr->getItem() == elem)
        {
            return true;
        }
        count++;
        currNodePtr = currNodePtr->getNext();
    }

    // Nothing was found
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
    // {elem1, elem2, ..., elemN}
    // where each elemI is an element in the elements array
    strm << "{";
    Node<friendT>* currNodePtr = obj.head;
    int count = 0;

    while (currNodePtr != nullptr && count < (obj.numElements - 1))
    {
        strm << currNodePtr->getItem() << ", ";
        currNodePtr = currNodePtr->getNext();
        count++;
    }

    strm << currNodePtr->getItem() << "}";
    return strm;
}
