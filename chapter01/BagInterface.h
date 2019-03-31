/** @file: BagInterface.h **/
#ifndef _BAG_INTERFACE_H
#define _BAG_INTERFACE_H

#include <vector>
template<class ItemType>
class BagInterface
{
public:
    // Gets the current number of entries in the bag
    // @return The integer number of entries currently in the bag
    virtual int getCurrentSize() const = 0;

    // Sees if the bag is empty
    // @return true if the bag is empty, false if it isn't
    virtual bool isEmpty() const = 0;

    // Adds a new entry to the bag
    // @post If successful, newEntry is stored in the bag and
    //       the count of items in the bag has increased by 1
    // @param The object to be added as a new entry
    // @return True if addition was successful, false if not
    virtual bool add(const ItemType& newEntry) const = 0;

    // Removes one occurrence of a given entry from the bag if
    // possible
    // @post If successful, anEntry has been removed from the bag and
    //       the count of items in the bag has been decreased by 1
    // @param anEntry The entry to be removed
    // @return True if removal was successful, or false if not
    virtual bool remove(const ItemType& anEntry) const = 0;

    // Removes all entries from the bag
    // @post Bag contains no items, and the count of items is 0
    virtual void clear = 0;

    // Counts the number of times a given entry appears in the bag
    // @param anEntry The entry to be counted
    // @return The number of times anEntry appears in the bag
    virtual int getFrequencyOf(const ItemType& anEntry) const = 0;

    // Tests whether the bag contains a given entry
    // @param anEntry The entry to locate
    // @return True if bag contains anEntry, or false otherwise
    virtual bool contains(const ItemType& anEntry) const = 0;

    // Empties and then fills a given vector with all entries that
    // are in the bag
    // @return A vector containing all the entries in the bag
    virtual vector<ItemType> toVector() const = 0;
};

#endif // _BAG_INTERFACE_H