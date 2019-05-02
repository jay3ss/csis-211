#include "LinkedSet.h"

// Destructor
template<class T>
LinkedSet<T>::~LinkedSet()
{
    // Create a temporary Node pointer to hold the head pointer.
    Node<T>* tempHeadPtr = nullptr;
    while (head != nullptr)
    {
        // Update the current head pointer to point to the next
        // node and release the memory pointed to by the temporary
        // head pointer
        tempHeadPtr = head;
        head = head->getNext();

        tempHeadPtr->setNext(nullptr);
        delete tempHeadPtr;
    }
    // Don't forget to set the temporary head pointer to NULL and
    // to set the number of elements to zero
    tempHeadPtr = nullptr;
    numElements = 0;
}

// Adds an element to the set, if possible
template <class T>
bool LinkedSet<T>::add(const T &elem)
{
    // Before adding, we must check that the element does not already
    // exist in the set. If it is in the set, then we cannot add it.
    // Otherwise, we can add it
    bool canAdd = (nullptr == getPointerTo(elem));
    if (canAdd)
    {
        // Create a new node of type T and instantiate it
        // with the element to be added and the head pointer.
        // Don't forget to increase the count of the number of
        // elements in the set
        Node<T>* toAdd = new Node<T>(elem, head);
        head = toAdd;
        numElements++;
    }

    return canAdd;
}

// Returns the intersection of this set and aSet
template <class T>
void LinkedSet<T>::intersection(const SetInterface<T> &aSet, SetInterface<T> &interSet)
{
}

// Checks if an object is an element to the set
template <class T>
bool LinkedSet<T>::isElement(const T &elem) const
{
    // If we can get a pointer to the element, then it is an
    // element of the set. If not, then we get the nullptr back
    return nullptr != getPointerTo(elem);
}

// Returns the the intersection of this set and aSet
template <class T>
bool LinkedSet<T>::isSubset(const SetInterface<T> &aSet)
{
    return false;
}

// Removes the object from the set, if it is present
template <class T>
bool LinkedSet<T>::remove(const T &elem)
{
    // Find the node that holds the element that we're trying to remove
    Node<T> *nodePtr = getPointerTo(elem);

    // Did we find it?
    bool canRemove = (nodePtr != nullptr);

    // If we found it, replace it with the first node and then delete the
    // first node
    if (canRemove)
    {
        // Copy the object at the first node to the node that's going
        // to be deleted
        nodePtr->setItem(head->getItem());

        // Create a temporary node to hold the first node and advance the head
        // to the next node
        Node<T>* deleteThisNodePtr = head;
        head = head->getNext();

        // Release the memory pointed to by the head back to the system
        deleteThisNodePtr->setNext(nullptr);
        delete deleteThisNodePtr;
        deleteThisNodePtr = nullptr;

        // Don't forget to decrease the number of elements in the set
        numElements--;
    }

    return canRemove;
}

// Returns the union of this set and aSet
template <class T>
void LinkedSet<T>::unionSet(const SetInterface<T> &aSet, SetInterface<T> &unionSet)
{
}

// Returns all of the elements in the set as a vector
template <class T>
std::vector<T> LinkedSet<T>::vector() const
{
    return std::vector<T>();
}

template<class T>
Node<T>* LinkedSet<T>::getPointerTo(const T &elem) const
{
    Node<T>* currNodePtr = head;

    while (currNodePtr != nullptr)
    {
        if (currNodePtr->getItem() == elem)
        {
            return currNodePtr;
        }
        else
        {
            currNodePtr = currNodePtr->getNext();
        }
    }

    return currNodePtr;
}

template <class friendT>
std::ostream &operator<<(std::ostream &strm, const LinkedSet<friendT> &obj)
{
    // Enter the elements to the osftream object (strm) so that the set will be
    // printed in the following format:
    // {elem1, elem2, ..., elemN}
    // where each elemI is an element in the elements array
    strm << "{";
    Node<friendT>* currNodePtr = obj.head;
    int count = 0;

    // Traverse each node until the second to last node is reached so that
    // there isn't a trailing comma before the closing '}'
    while (count < (obj.numElements - 1))
    {
        strm << currNodePtr->getItem() << ", ";
        currNodePtr = currNodePtr->getNext();
        count++;
    }

    // Add the closing '}'
    strm << currNodePtr->getItem() << "}";
    return strm;
}
