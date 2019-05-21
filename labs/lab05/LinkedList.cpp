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
void LinkedList<T>::replace(int position, const T &newEntery)
{}
