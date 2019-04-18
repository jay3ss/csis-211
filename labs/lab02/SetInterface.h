/** @file SetInterface.h */
#ifndef _SET_INTERFACE_H
#define _SET_INTERFACE_H
template<class T>
class SetInterface
{
public:
    /** Adds an element to the set, if possible
     @return The integer number of elements in the set */
    virtual bool add(const T& t) const = 0;

    /** Returns the the intersection of this set and aSet
     @return The integer number of elements in the set */
    virtual SetInterface<T> intersection(const SetInterface<T> &aSet) const = 0;

    /** Checks if an object is an element to the set
     @return The integer number of elements in the set */
    virtual bool isElement(const T &t) const = 0;

    /** Returns the the intersection of this set and aSet
     @return The integer number of elements in the set */
    virtual bool isSubset(const SetInterface<T> &aSet) const = 0;

    /** Removes the object from the set, if it is present
     @return The integer number of elements in the set
     */
    virtual bool remove(const T &t) const = 0;

    /** Returns the integer number of elements in the set
     @return The integer number of elements in the set */
    virtual int size() const = 0;

    /** Returns the the union of this set and aSet
     @return The integer number of elements in the set */
    virtual SetInterface<T> union(const SetInterface<T>& aSet) const = 0;
};

#endif // _SET_INTERFACE_H
