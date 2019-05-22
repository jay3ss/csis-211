#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "Node.h"
#include "ListInterface.h"

template<class T>
class LinkedList : public ListInterface<T>
{
public:
	/** Constructor */
	LinkedList();

	/** Copy constructor */
	LinkedList(const LinkedList<T> &list);

    /** Destructor */
    ~LinkedList();

    /** Sees if the list is empty
	@return True if the list is empty, otherwise false. */
	bool isEmpty() const;

	/** Get the number of entries in the list.
	 @return The integer number of entries in the list. */
    int length() const;

    /** Insert an entry at a given position in the list.
	@post A new entry will be in the list in the given position if
		1 <= position <= length() + 1. All entries after the insertion point
		will be increased by one.
	@param position
	@param newEntry
	@return */
    bool insert(int position, const T &newEntry);

    /** Remove the entry at a given position.
	@post The entry at the given position will no longer exist at that position
		if 1 <= position <= length and all entries after the removal point will
		be decreased by one.
	@param position	The position of the item to be removed.
	@return If there is entry at the given position exists it will be removed
		and the function will return true. If there is no entry at the given
		position then false will be returned. */
    bool remove(int position);

    /** Remove all entries from the list.
	@post The list will be empty. */
    void clear();

    /** Get the entry at a given position.
	@pre An entry should be at the given position (i.e.,
		1 <= position <= length())
	@return The entry at the given position. */
    T entry(int position) const;

    /** Replace the entry at the given position.
	@pre 1 <= position <= length()
	@post The previous entry will be replaced with the new entry.
	@param position The position in the list of the entry to be replaced.
	@param newEntry The replacement entry */
    void replace(int position, const T &newEntry);

	// Exception class
	class EmptyList{};
private:
	Node<T>* topPtr_;	// Pointer to the top node
	int numEntries_;	// Number of current entries in the list

	/** Gets the pointer to a node at a desired position
	@param position The position of the desired node
	@return The pointer to the desired node	*/
	Node<T>* getNodeAt(int position) const;
};

#include "LinkedList.cpp"

#endif // _LINKED_LIST_H_
