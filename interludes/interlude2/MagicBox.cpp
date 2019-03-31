#include "MagicBox.h"

template <class ItemType>
MagicBox<ItemType>::MagicBox()
{
    PlainBox<ItemType>();
    firstItemStored = false;
}

template <class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType& theItem)
{
    firstItemStored = false;
    MagicBox<ItemType>::setItem(theItem);
}

template <class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& theItem)
{
    if(!firstItemStored)
    {
        PlainBox<ItemType>::setItem(theItem);
        firstItemStored = true;
    }
}