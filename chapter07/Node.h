#ifndef _NODE_H
#define _NODE_H

template<class T>
class Node
{
private:
    T        item;
    Node<T>* next;
public:
    Node();
    Node(const T& item);
    Node(const T& item, Node<T>* nextNodePtr);
    void setItem(const T& anItem);
    void setNext(const Node<T>* nextNodePtr);
    T getItem() const;
    Node<T>* getNext() const;
};

#include "Node.cpp"
#endif // _NODE_H