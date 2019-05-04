/** Header file for an array-based implementation of the ADT bag.
@file ArrayBag.h */
#ifndef ARRAY_BAG
#define ARRAY_BAG

#include <vector>
#include "BagInterface.h"

template <class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
    static const int DEFAULT_CAPACITY = 6; // Small size to test for a full bag
    ItemType items[DEFAULT_CAPACITY];      // Array of bag items
    int itemCount;                         // Current count of bag items
    int maxItems;                          // Max capacity of the bag
    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain
    // the target.
    int getIndexOf(const ItemType &target) const
    {
        bool found = false;
        int result = -1;
        int searchIndex = 0;
        // If the bag is empty, itemCount is zero, so loop is skipped
        while (!found && (searchIndex < itemCount))
        {
            if (items[searchIndex] == target)
            {
                found = true;
                result = searchIndex;
            }
            else
            {
                searchIndex++;
            } // end if
        }     // end while
        return result;
    }

public:
    ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY) {}
    int getCurrentSize() const { return itemCount; }
    bool isEmpty() const { return itemCount == 0; }
    bool add(const ItemType &newEntry)
    {
        bool hasRoomToAdd = (itemCount < maxItems);
        if (hasRoomToAdd)
        {
            items[itemCount] = newEntry;
            itemCount++;
        } // end if
        return hasRoomToAdd;
    }
    bool remove(const ItemType &anEntry)
    {
        int locatedIndex = getIndexOf(anEntry);
        bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
        if (canRemoveItem)
        {
            itemCount--;
            items[locatedIndex] = items[itemCount];
        } // end if
        return canRemoveItem;
    } // end remove
    void clear() { itemCount = 0; }
    bool contains(const ItemType &anEntry) const
    {
        bool found = false;
        int curIndex = 0; // Current array index
        while (!found && (curIndex < itemCount))
        {
            if (anEntry == items[curIndex])
            {
                found = true;
            }           // end if
            curIndex++; // Increment to next entry
        }               // end while
        return found;
    }
    int getFrequencyOf(const ItemType &anEntry) const
    {
        int frequency = 0;
        int curIndex = 0; // Current array index
        while (curIndex < itemCount)
        {
            if (items[curIndex] == anEntry)
            {
                frequency++;
            }           // end if
            curIndex++; // Increment to next entry
        }               // end while
        return frequency;
    } // end getFrequencyOf
    std::vector<ItemType> toVector() const
    {
        std::vector<ItemType> bagContents;
        for (int i = 0; i < itemCount; i++)
            bagContents.push_back(items[i]);
        return bagContents;
    } // end toVector
}; // end ArrayBag
// #include "ArrayBag.cpp"
#endif