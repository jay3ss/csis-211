// Midterm 1 - Question 2
//

// Write the recursive C++ function maxArray that returns the largest value in
// an array and adheres to the following pseudocode.
// 
//     if (anArray has only one entry)
//         maxArray(anArray) is the entry in anArray
//     else if (anArray has more than one entry)
//         maxArray(anArray) is the maximum of
//         maxArray(left half of anArray) and maxArray(right half of anArray)
#include <algorithm>
#include <iostream>

// Function prototype
int maxArray(const int anArray, int first, int last);
int main()
{
    const int arr[] = {5,12, 2424, 653};
    int maximum = maxArray(arr, 0, 4);
    // int maximum = std::max(1, 2);

    std::cout << "Max is " << maximum;

    return 0;
}

#include <algorithm>
template<class T>
T maxArray(const T anArray[], int first, int last)
{
    if (first == last)
    {
        return anArray[first];
    }
    else
    {
        int middle = first + (last - first) / 2;
        return std::max(
                maxArray(anArray, first, middle - 1),
                maxArray(anArray, middle + 1, last));
    }
}