#include "Node.h"

template <class T>
Node<T>::Node(const T &anItem) : item_(anItem), next_(nullptr) {}

template <class T>
Node<T>::Node(const T &anItem, const Node<T> *nextNodePtr) :
    item_(anItem), next_(nextNodePtr) {}

template <class T>
void Node<T>::item(const T &anItem)
{
    item_ = anItem;
}

template <class T>
void Node<T>::next(const Node<T> *nextNodePtr)
{
    next_ = nextNodePtr;
}

template <class T>
T Node<T>::item() const
{
    return item_;
}

template <class T>
Node<T> *Node<T>::next() const
{
    return next_;
}
