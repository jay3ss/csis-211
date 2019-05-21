#include "LinkedList.h"

/** Destructor */
template <class T>
LinkedList<T>::~LinkedList()
{}

/** Sees if the list is empty */
template<class T>
bool LinkedList<T>::isEmpty() const
{
    return false;
}

/** Get the number of entries in the list. */
template<class T>
int LinkedList<T>::length() const
{
    return -1;
}

/** Insert an entry at a given position in the list. */
template<class T>
bool LinkedList<T>::insert(int position, T &newEntry)
{
    return false;
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
void LinkedList<T>::replace(int position, T &newEntery)
{}
