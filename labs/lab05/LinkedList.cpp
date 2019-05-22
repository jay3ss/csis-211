#include "LinkedList.h"

/** Constructor */
template <class T>
LinkedList<T>::LinkedList() : topPtr_(nullptr), numEntries_(0)
{

}

/** Destructor */
template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}

/** Sees if the list is empty */
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return numEntries_ == 0;
}

/** Get the number of entries in the list. */
template<class T>
int LinkedList<T>::length() const
{
    return numEntries_;
}

/** Insert an entry at a given position in the list. */
template<class T>
bool LinkedList<T>::insert(int position, const T &newEntry)
{
    // Enforce the precondition that 1 <= position <= length()
    bool canInsert = ((1 <= position) && (position <= length() + 1));
    if (canInsert)
    {
        // Create a new Node and copy the head pointer
        Node<T>* newNodePtr = new Node<T>(newEntry, nullptr);

        // If the desired position is the first, then change what the head
        // pointer points to
        if (position == 1)
        {
            topPtr_ = newNodePtr;
        }
        else
        {
            // Get the node before the node at the desired position
            Node<T>* prevNodePtr = getNodeAt(position - 1);
            prevNodePtr->next(newNodePtr);
        }
        numEntries_++;
    }
    return canInsert;
}

/** Remove the entry at a given position. */
template<class T>
bool LinkedList<T>::remove(int position)
{
    return false;
}

/** Remove all entries from the list. */
template<class T>
void LinkedList<T>::clear()
{}

/** Get the entry at a given position. */
template<class T>
T LinkedList<T>::entry(int position) const
{}

/** Replace the entry at the given position. */
template<class T>
void LinkedList<T>::replace(int position, const T &newEntery)
{}

/** Gets the pointer to a node at a desired position */
template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
    Node<T>* nodePtr = topPtr_;

    // Traverse the list until we arrive at the proper position
    for (int count = 1; count < position; count++)
    {
        nodePtr = nodePtr->next();
    }
    return nodePtr;
}
