#include <cassert>
#include "ArrayStack.h"

template<class T>
ArrayStack<T>::ArrayStack() : top(-1) {}

template<class T>
bool ArrayStack<T>::isEmpty() const
{
    return top < 0;
}

template<class T>
bool ArrayStack<T>::push(const T& newItem)
{
    bool canPush = top < (MAX_STACK - 1);
    if (canPush)
    {
        top++;
        items[top] = newItem;
    }

    return canPush;
}
