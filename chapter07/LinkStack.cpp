#include "LinkStack.h"

template<class T>
LinkStack<T>::LinkStack() {}

template<class T>
LinkStack<T>::LinkStack(const LinkStack<T>& aStack)
{
    Node<T>* origChainPtr = aStack->topPtr;

    if (origChainPtr == nullptr)
    {
        topPtr = nullptr; // Original stack is empty, so is copy
    }
    else
    {
        // Copy the first node
        topPtr = new Node<T>();
        topPtr->setItem(origChainPtr->getItem());

        // Point to the first node in the new chain
        Node<T>* newChainPtr = topPtr;

        // Copy the remaining nodes
        while (origChainPtr != nullptr)
        {
            // Advance the pointer
            origChainPtr = origChainPtr->getNext();

            // Get next item from the original chain
            T nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<T>* newNodePtr = new Node<T>(nextItem);

            // Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);
        } // end while
        newChainPtr->setNext(nullptr); // Flag end of chain
    } // end if
}

template<class T>
LinkStack<T>::~LinkStack()
{
    // Pop every item in the chain until it is empty
    while (!isEmpty())
    {
        pop();
    }
}