#include <iostream>
#include "selectionsort.cpp"

using namespace std;

int main()
{
    int theArray[] = {29, 10, 14, 37, 13};
    const int size = 5;
    selectionSort<int>(theArray, size);

    for (int i = 0; i < size - 1; i++)
    {
        cout << theArray[i] << ", ";
    }
    cout << theArray[size - 1];
}
