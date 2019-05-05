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

template<class T>
LinkedSet<T>::LinkedSet(const LinkedSet<T> &aSet)
{
    Node<T> *origChainPtr = aSet.head;

    if (origChainPtr == nullptr)
    {
        head = nullptr;
    }
    else
    {
        // Copy the first node
        head = new Node<T>();
        head->setItem(origChainPtr->getItem());

        // Point to the first node in the new chain
        Node<T> *newChainPtr = head;

        // Advance the original chain pointer
        origChainPtr = origChainPtr->getNext();

        // Copy the remaining nodes
        while (origChainPtr != nullptr)
        {
            // Get the next item from the original chain
            T nextItem = origChainPtr->getItem();

            // Create a new node containing the next item
            Node<T> *newNodePtr = new Node<T>(nextItem);

            // Link new node to end of the new chain
            newChainPtr->setNext(newNodePtr);

            // Advance the pointer to the new last node
            newChainPtr = newChainPtr->getNext();

            // Advance the original chain pointer
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr); // Flag the end of the chain
    }
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
    Node<T>* tempNodePtr = head;

    // The intersection of two sets is a set that only has elements that are common
    // between the two sets. Therefore, only add an element if it is an element of
    // both sets
    while (tempNodePtr != nullptr)
    {
        if (aSet.isElement(tempNodePtr->getItem()))
        {
            interSet.add(tempNodePtr->getItem());
        }
        tempNodePtr = tempNodePtr->getNext();
    }
}

// Checks if an object is an element to the set
template <class T>
bool LinkedSet<T>::isElement(const T &elem) const
{
    // If we can get a pointer to the element, then it is an
    // element of the set. If not, then we get the nullptr back
    return nullptr != getPointerTo(elem);
}

// Checks if the set is empty
template <class T>
bool LinkedSet<T>::isEmpty() const
{
    return 0 == size();
}

// Returns the the intersection of this set and aSet
template <class T>
bool LinkedSet<T>::isSubset(const SetInterface<T> &aSet)
{
    // Get a vector from aSet and check if each element of the vector
    // is also an element of the set. If every element of the vector
    // from aSet is an element of this set, then aSet is a subset of
    // this set. Otherwise, aSet is not a subset of this set
    std::vector<T> aVector = aSet.vector();

    for (auto elem : aVector)
    {
        if (!isElement(elem))
        {
            return false;
        }
    }
    return true;
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
    // Get a vector of all the elements from aSet and add them to the union set
    std::vector<T> aVect = aSet.vector();

    for (auto elem: aVect)
    {
        unionSet.add(elem);
    }

    // Traverse through each node in this set and add them to the union set
    Node<T>* tempNodePtr = head;

    while (tempNodePtr != nullptr)
    {
        unionSet.add(tempNodePtr->getItem());
        tempNodePtr = tempNodePtr->getNext();
    }
}

// Returns all of the elements in the set as a vector
template <class T>
std::vector<T> LinkedSet<T>::vector() const
{
    // Create a vector and a pointer to the head pointer, traverse nodes
    // in the set and push each element to the vector, and then return
    // the vector
    std::vector<T> aVector;
    Node<T>* tempNodePtr = head;

    while (tempNodePtr != nullptr)
    {
        aVector.push_back(tempNodePtr->getItem());
        tempNodePtr = tempNodePtr->getNext();
    }

    return aVector;
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
    while (currNodePtr != nullptr)
    {
        strm << currNodePtr->getItem();
        if (count < (obj.numElements - 1))
        {
            strm << ", ";
        }
        currNodePtr = currNodePtr->getNext();
        count++;
    }

    // Add the closing '}'
    strm << "}";
    return strm;
}
