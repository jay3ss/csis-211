#include <cassert>
#include "ArrayStack.h"

template<class T>
ArrayStack<T>::ArrayStack() : top(-1) {}

template<class T>
bool ArrayStack<T>::isEmpty() const
{
    return top < 0;
}