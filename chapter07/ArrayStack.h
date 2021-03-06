#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H

#include "StackInterface.h" stack

const int MAX_STACK = 1000; // maximum size of the

template<class T>
class ArrayStack : public StackInterface<T>
{
private:
    T   items[MAX_STACK];
    int top;
public:
    ArrayStack();
    bool isEmpty() const;
    bool push(const T& newItem);
    bool pop();
    T peek() const;
};

#include "ArrayStack.cpp"
#endif // _ARRAY_STACK_H