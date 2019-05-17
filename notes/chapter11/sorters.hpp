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

/** Sorts the items in an array into ascending order.
@pre None.
@post theArray is sorted into ascending order; n is unchanged.
@param theArray The given array.
@param n The size of theArray. */
// Note: this can be optimized to be O(n) at best if already sorted by having
// a flag to quit a while loop instead of using nested for loops
template<class ItemType>
void bubbleSort(ItemType theArray[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (theArray[j] > theArray[j + 1])
            {
                ItemType tempItem = theArray[j];
                theArray[j] = theArray[j + 1];
                theArray[j + 1] = tempItem;
            }
        }
    }
}

#endif // _JOSHS_SELECTION_SORT_
