#ifndef _NODE_H
#define _NODE_H
template <class T>
class Node
{
private:
    T item;        // An item
    Node<T> *next; // Pointer to next node
    Node<T> *prev; // Pointer to previous node
public:
  
    Node(): next(nullptr), prev(nullptr){}
    Node(const T &anItem) : item(anItem), next(nullptr), prev(nullptr) {}
    Node(const T &anItem, Node<T> *nextNodePtr, Node<T> *prevNodePtr) :
        item(anItem), next(nextNodePtr), prev(prevNodePtr) {}
    void setItem(const T &anItem)
        { item = anItem; }
    void setNext(Node<T> *nextNodePtr)
        { next = nextNodePtr; }
    void setPrev(Node<T> *prevNodePtr)
        { prev = prevNodePtr; }
    T getItem() const
        { return item; }
    Node<T> *getNext() const
        { return next; }
    Node<T> *getPrev() const
        { return prev; }
}; // end Node class
#endif // _NODE_H