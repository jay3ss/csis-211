#ifndef _JOSHS_SELECTION_SORT_
#define _JOSHS_SELECTION_SORT_
/** Finds the largest item in an array.
@pre The size of the array is >= 1.
@post The arguments are unchanged.
@param theArray The given array.
@param size The number of elements in theArray.
@return The index of the largest entry in the array. */
template<class ItemType>
int findIndexofLargest(const ItemType theArray[], int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
    {
        if (theArray[index] < theArray[i])
        {
            index = i;
        }
    }
    return index;
}
/** Sorts the items in an array into ascending order.
@pre None.
@post The array is sorted into ascending order; the size of the array
is unchanged.
@param theArray The array to sort.
@param n The size of theArray. */
template<class ItemType>
void selectionSort(ItemType theArray[], int n)
{
    int indexOfLargest;
    ItemType tempItem;
    for (int i = n - 1; i > 0; i--)
    {
        indexOfLargest = findIndexofLargest(theArray, i + 1);
        tempItem = theArray[indexOfLargest];
        theArray[indexOfLargest] = theArray[i];
        theArray[i] = tempItem;
    }
}

#endif // _JOSHS_SELECTION_SORT_
