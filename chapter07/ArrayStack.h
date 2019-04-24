#ifndef _ARRAY_STACK_H
#define _ARRAY_STACK_H

#include "StackInterface.h" stack

const int MAX_STACK = 1000; // maximum size of the

template<class T>
class ArrayStack : public StackInterface
{
private:
    T   items[MAX_STACK];
    int top;
public:
    ArrayStack();
    bool isEmpty();
    bool push(const T& newItem);
    bool pop();
    T peek();
};

#include "ArrayStack.cpp"
#endif // _ARRAY_STACK_H