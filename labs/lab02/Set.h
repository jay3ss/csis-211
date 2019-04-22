#ifndef _JOSH_SET_H
#define _JOSH_SET_H

#include <iostream>

template <class T>
class Set
{
public:
    // Default constructor
    Set() : numObjects(0), maxObjects(DEFAULT_MAX_OBJS)
        { objects = new T[maxObjects]; }

    // Constructor
    Set(const int num);
    // {
    //     numObjects = num;
    //     // Allocate memory for the array
    //     try
    //     {
    //         objects = new T[num];
    //     }
    //     catch (std::bad_alloc)
    //     {
    //         // Do something else here later
    //         std::cout << "ERROR: Couldn't allocate enough memory.\n";
    //     }
    // }

    // Copy constructor
    Set(const Set &set);

    // Destructor
    ~Set();

    // Checks if the set is empty
    bool isEmpty() const { return size() == 0; }

    // Returns the number of objects in the set
    int size() const { return numObjects; }
    int maxSize() const { return maxObjects; }

    // Adds a new element to the set. If the element isn't already in the set,
    // the element is added and the function returns true. Otherwise, the
    // element isn't added and the function returns false.
    // 
    // NOTE: the problem with this is that we don't automatically resize the
    // objects array so that we can add the new element to the set (if
    // possible).
    bool add(const T& elem);
    bool add(const T* arr, const int arrSize);

    // :::NOT IMPLEMENTED:::
    // Removes an element from the set. If the element isn't in the set, the
    // function returns false. Otherwise, if the element is in the set, the 
    // it is removed and the function returns false.
    //
    // NOTE: the problem with this is that we don't automatically resize the
    // objects array so that we can add the new element to the set (if
    // possible).
    bool remove(const T& elem);

    // Checks if an object is in the set. Returns true if it is in the set,
    // returns false otherwise.
    bool isIn(const T &elem);

    // For printing
    template <class friendT>
    friend std::ostream &operator<<(std::ostream &, const Set<friendT> &);

private:
    const int DEFAULT_MAX_OBJS = 3;
    int numObjects;     // current number of objects
    int maxObjects;     // max number of objects
    T* objects;


    void resize(const int s);
    int getIndexOf(const T& elem);
};

#include "Set.cpp"
#endif // _JOSH_SET_H