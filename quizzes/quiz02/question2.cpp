// Write a recursive function that will compute the sum of the first n integers
// in an array of at least n integers. Hint: Begin with the n th integer.
#include <iostream>

using namespace std;

int recursivesum(int arr[], int n);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 15};

    int sum = recursivesum(arr, 6);

    cout << "The sum of the array is " << sum << endl;
    return 0;
}

int recursivesum(int arr[], int n)
{
    if (n - 1 == 0)
    {
        return arr[n - 1];
    }
    else
    {
        return arr[n - 1] + recursivesum(arr, n - 1);
    }
}
