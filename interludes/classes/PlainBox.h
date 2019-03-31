/** @file PlainBox.h **/

#ifndef _PLAIN_BOX_H
#define _PLAIN_BOX_H

template<class ItemType>

// Declaration for the class PlainBox
class PlainBox
{
private:
    // Data field
    ItemType item;
public:
    // Default constructor
    PlainBox();

    // Parameterized constructor
    PlainBox(const ItemType& theItem);

    // Method to change the value of the data field
    virtual void setItem(const ItemType& theItem);

    // Method to get the value of the data field
    virtual ItemType getItem() const;
};

#include "PlainBox.cpp" // Include the implementation file
#endif // _PLAIN_BOX_H
