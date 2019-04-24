#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#include "Node.h"
#include "StackInterface.h"

template<class T>
class LinkStack : public StackInterface<T>
{
private:
    Node<T>* topPtr;

public:
// Constructors and destructor
    LinkStack();
    LinkStack(const LinkStack<T>& aStack);
    virtual ~LinkStack();

// Stack operations
    bool isEmpty() const;
    bool push(const T& newItem);
    bool pop();
    T peek() const;
};

#include "LinkStack.cpp"
#endif // _LINK_STACK_H