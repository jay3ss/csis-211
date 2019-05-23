#ifndef _LIST_INTERFACE_H_
#define _LIST_INTERFACE_H_

template<class T>
class ListInterface
{
public:
	/** Destructor */
	virtual ~ListInterface(){};

	/** Sees if the list is empty
	@return True if the list is empty, otherwise false. */
	virtual bool isEmpty() const = 0;

	/** Get the number of entries in the list.
	 @return The integer number of entries in the list. */
	virtual int length() const = 0;

	/** Insert an entry at a given position in the list.
	@post A new entry will be in the list in the given position if
		1 <= position <= length(). All entries after the insertion point will
		be moved back by one.
	@param position The position that the new entry will have.
	@param newEntry	The entry to be inserted.
	@return True if the entery can be inserted, false otherwise. */
	virtual bool insert(int position, const T &newEntry) = 0;

	/** Remove the entry at a given position.
	@post The entry at the given position will no longer exist at that position
		if 1 <= position <= length and all entries after the removal point will
		be moved forward by one.
	@param position	The position of the item to be removed.
	@return If there is entry at the given position exists it will be removed
		and the function will return true. If there is no entry at the given
		position then false will be returned. */
	virtual bool remove(int position) = 0;

	/** Remove all entries from the list.
	@post The list will be empty. */
	virtual void clear() = 0;

	/** Get the entry at a given position.
	@pre An entry should be at the given position (i.e.,
		1 <= position <= length())
	@return The entry at the given position. */
	virtual T entry(int position) const = 0;

	/** Replace the entry at the given position.
	@pre 1 <= position <= length()
	@post The previous entry will be replaced with the new entry.
	@param position The position in the list of the entry to be replaced.
	@param newEntry The replacement entry */
	virtual void replace(int position, const T &newEntery) = 0;
};

#endif // _LIST_INTERFACE_H_
