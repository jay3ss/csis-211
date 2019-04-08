#ifndef _JOSH_SET_H
#define _JOSH_SET_H

#include <iostream>
#include <new>

template <class T>
class Set
{
public:
    // Default constructor
    Set() : numObjects(0), objects(nullptr) {}

    // Constructor
    Set(const int num)
    {
        numObjects = num;
        // Allocate memory for the array
        try
        {
            objects = new T[num];
        }
        catch (std::bad_alloc)
        {
            // Do something else here later
            std::cout << "ERROR: Couldn't allocate enough memory.\n";
        }
    }

    // Copy constructor
    Set(const Set &set);

    // Destructor
    ~Set()
    {
        if (numObjects > 0)
        {
            delete[] objects;
            objects = nullptr;
        }
    }

    // Checks if the set is empty
    bool isEmpty() const { return size() == 0; }

    // Returns the number of objects in the set
    int size() const { return numObjects; }

    // Adds a new element to the set. If the element isn't already in the set,
    // the element is added and the function returns true. Otherwise, the
    // element isn't added and the function returns false.
    // 
    // NOTE: the problem with this is that we don't automatically resize the
    // objects array so that we can add the new element to the set (if
    // possible).
    bool add(const T& t)
    {
        bool canAdd = numObjects < maxObjects;
        if (!isIn(t) && canAdd)
        {
            objects[numObjects] = t;
            numObjects++;
        }

        return canAdd;
    }

    // :::NOT IMPLEMENTED:::
    // Removes an element from the set. If the element isn't in the set, the
    // function returns false. Otherwise, if the element is in the set, the 
    // it is removed and the function returns false.
    //
    // NOTE: the problem with this is that we don't automatically resize the
    // objects array so that we can add the new element to the set (if
    // possible).
    bool remove(const T& t)
    {
        bool canRemove = isIn(t);
        return canRemove;
    }

    // Checks if an object is in the set. Returns true if it is in the set,
    // returns false otherwise.
    bool isIn(const T& t)
    {
        for (int i = 0; i < numObjects; i++)
        {
            if (t == objects[i])
            {
                return true;
            }

        }
        return false;
    }

private:
    int numObjects;     // current number of objects
    int maxObjects;     // max number of objects
    T* objects;
};

// #include "Set.cpp"
#endif // _JOSH_SET_H