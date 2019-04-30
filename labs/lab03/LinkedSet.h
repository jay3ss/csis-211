#ifndef _LINKED_SET_H
#define _LINKED_SET_H

#include <iostream>
#include "Node.h"
#include "SetInterface.h"

template<class T>
class LinkedSet: public SetInterface<T>
{
public:
    LinkedSet() {}

    /** Destructor */
    ~LinkedSet(){}
    /** Adds an element to the set, if possible
    @post the element is added to the set and the number of elements is
      increased by one (if successful)
   @param elem the object to be added as a new element of the set
   @return true if the element was added, false if it wasn't */
    bool add(const T &elem) {}

    /** Returns the the intersection of this set and aSet
    @param aSet the set to form an intersection with this set
   @return The integer number of elements in the set */
    void intersection(const SetInterface<T> &aSet, SetInterface<T> &unionSet) {}

    /** Checks if an object is an element to the set
    @param elem the object to be checked if it is an element of the set
   @return true if elem is an element of this set, false if not */
    bool isElement(const T &elem) {}

    /** Returns the the intersection of this set and aSet
    @param aSet the set to check if it is a subset of this set
   @return true if aSet is a subset of this set, false if not */
    bool isSubset(const SetInterface<T> &aSet) {}

    /** Removes the object from the set, if it is present
    @post the element is removed from the set and the number of elements is
      decreased by one (if successful)
   @param elem the object to be removed as a new element of the set
   true if the element was removed, false if it wasn't */
    bool remove(const T &elem) {}

    /** Returns the integer number of elements in the set
    @return The integer number of elements in the set */
    int size() const {}

    /** Returns the the union of this set and aSet
    @param aSet the set to form a union with this set
   @return The integer number of elements in the set */
    void unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet) {}

    /** Returns all of the elements in the set as a vector
    @return A vector containing the elements of the set */
    std::vector<T> vector() const {}

    /** Overloaded << operator to allow easy printing of LinkedSet objects
     @param strm Reference to the ostream object
            obj Reference to the LinkedSet object that's being printed
     @return The  ostream object (strm) */
    template <class friendT>
    friend std::ostream &operator<<(std::ostream &strm, const LinkedSet<friendT> &obj);
};

#include "LinkedSet.cpp"
#endif // _LINKED_SET_H
