#include "LinkedList.h"

/** Constructor */
template <class T>
LinkedList<T>::LinkedList() : topPtr_(nullptr), numEntries_(0)
{

}

/** Copy constructor */
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    // We only need to do something if the list isn't empty
    if (!list.isEmpty())
    {
        T entry;
        // Take the elements from the list and add them to this one
        for (int position = 1; position <= list.length(); position++)
        {
            entry = list.entry(1);
            insert(position, entry);
        }
    }
}

/** Destructor */
template <class T>
LinkedList<T>::~LinkedList()
{
    // Free up all allocated memory by clearing the list
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
    // Enforce the precondition that 1 <= position <= length() + 1
    bool canInsert = ((1 <= position) && (position <= length() + 1));
    if (canInsert)
    {
        // Create a new Node with the entry
        Node<T>* newNodePtr = new Node<T>(newEntry, nullptr);

        if (position == 1)
        {
            // Insert at the beginning of the list
            newNodePtr->next(topPtr_);
            topPtr_ = newNodePtr;
        }
        else
        {
            // Get the previous node and set our new node's next pointer to the
            // node that the previous node points to
            Node<T>* prevNodePtr = getNodeAt(position - 1);
            newNodePtr->next(prevNodePtr->next());
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
    bool canRemove = ((1 <= position) && (position <= length()));
    if (canRemove)
    {
        Node<T> *nodeToDeletePtr = nullptr;
        if (position == 1)
        {
            nodeToDeletePtr = topPtr_;
            topPtr_ = topPtr_->next();

        }
        else
        {
            // Get the node before the one that we want to delete
            Node<T> *prevNodePtr = getNodeAt(position - 1);

            // Now get the node that want to delete so that we know what it
            // points to and use it
            nodeToDeletePtr = prevNodePtr->next();
            prevNodePtr->next(nodeToDeletePtr->next());
        }
        // Return the old node used to pointer back to the system
        nodeToDeletePtr->next(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        numEntries_--;
    }
    return canRemove;
}

/** Remove all entries from the list. */
template<class T>
void LinkedList<T>::clear()
{
    // Keep removing the first entry until the list is empty
    while(!isEmpty())
    {
        remove(1);
    }
}

/** Get the entry at a given position. */
template<class T>
T LinkedList<T>::entry(int position) const
{
    if (isEmpty())
    {
        throw EmptyList();
    }
    Node<T>* nodePtr = getNodeAt(position);
    return nodePtr->item();
}

/** Replace the entry at the given position. */
template<class T>
void LinkedList<T>::replace(int position, const T &newEntry)
{
    if (isEmpty())
    {
        throw EmptyList();
    }
    Node<T>* node = getNodeAt(position);
    node->item(newEntry);
}

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
