#ifndef _NODE_H
#define _NODE_H

template <class T>
class Node
{
private:
    T item_;
    Node<T> *next_;

public:
    Node() {}
    Node(const T &anItem);
    Node(const T &anItem, const Node<T> *nextNodePtr);
    void item(const T &anItem);
    void next(const Node<T> *nextNodePtr);
    T item() const;
    Node<T> *next() const;
};

#include "Node.cpp"
#endif // _NODE_H
