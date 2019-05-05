/** @file SetInterface.h */
#ifndef _SET_INTERFACE_H
#define _SET_INTERFACE_H

#include <vector>

template<class T>
class SetInterface
{
public:
    /** Destructor */
    virtual ~SetInterface(){}
    /** Adds an element to the set, if possible
    @post the element is added to the set and the number of elements is
        increased by one (if successful)
    @param elem the object to be added as a new element of the set
    @return true if the element was added, false if it wasn't */
    virtual bool add(const T& elem) = 0;

    /** Creates the difference of this set and aSet. The difference of two sets
        A and B is defined as
        A difference B = {x: x is an element of A and not an element of B}
    @param aSet the set to take the difference from this set
    @param diffSet the set to form a difference with this set */
    virtual void difference(const SetInterface &aSet, SetInterface &diffSet) = 0;

    /** Creates the intersection of this set and aSet. The intersection of two
        sets A and B is defined as
        A intersection B = {x: x is an element of A and B}
    @param aSet the set to form an intersection with this set
    @param interSet the set to form the intersection with this set */
    virtual void intersection(const SetInterface &aSet, SetInterface &interSet) = 0;

    /** Checks if an object is an element to the set
    @param elem the object to be checked if it is an element of the set
    @return true if elem is an element of this set, false if not */
    virtual bool isElement(const T &elem) const = 0;

    /** Checks if the set is empty
    @return true if numElements is zero, false if not */
    virtual bool isEmpty() const = 0;

    /** Returns the the intersection of this set and aSet
    @param aSet the set to check if it is a subset of this set
    @return true if aSet is a subset of this set, false if not */
    virtual bool isSubset(const SetInterface &aSet) = 0;

    /** Removes the object from the set, if it is present
    @post the element is removed from the set and the number of elements is
        decreased by one (if successful)
    @param elem the object to be removed as a new element of the set
    true if the element was removed, false if it wasn't */
    virtual bool remove(const T &elem) = 0;

    /** Returns the integer number of elements in the set
    @return The integer number of elements in the set */
    virtual int size() const = 0;

    /** Cretaes the the union of this set and aSet. The union of two sets
        A and B is defined as
        A union B = {x: x is an element of A or B}
    @param aSet the set to form a union with this set
    @param unionSet the set to form the union with this set */
    virtual void unionSet(const SetInterface &aSet, SetInterface &unionSet) = 0;

    /** Returns all of the elements in the set as a vector
    @return A vector containing the elements of the set */
    virtual std::vector<T> vector() const = 0;
};

#endif // _SET_INTERFACE_H
