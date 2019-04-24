/** @file StackInterface.h */
#ifndef _STACK_INTERFACE_H
#define _STACK_INTERFACE_H

template<class ItemType>
class StackInterface
{
public:
    /** Sees whether this stack is empty
     @return True if the stack is empty, false if not */
    virtual bool isEmpty() const = 0;

    /** Adds a new entry to the top of this stack
     @post If the operation was successful, newEntry is at the top of the stack
     @param newEntry The object to be added as a new entry
     @return True if the addition was successful, false if not */
    virtual bool push(const ItemType newEntry) = 0;

    /** Removes the top of this stack
     @post If the operation was successful, the top of the stack is removed
     @return True if the removal was successful, false if not */
    virtual bool pop() = 0;

    /** Returns the top of this stack
     @pre the stack is not empty
     @post The top of the stackis returned, the stack is unchanged
     @return The top of the stack */
    virtual ItemType peek() const = 0;
};

#endif // _STACK_INTERFACE_H