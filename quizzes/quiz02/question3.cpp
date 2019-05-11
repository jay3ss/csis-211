// Given two integers, start and end , where end is greater than start, write a
// recursive C++ function that returns the sum of the integers from start
// through end , inclusive.
#include <iostream>

using namespace std;

int recursivesum(int start, int end);

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 15};

    int start = 4, end = 6;
    int sum = recursivesum(start, end);

    cout << "The sum of " << start << " through " << end << " is " << sum << endl;
    return 0;
}

// Returns th
int recursivesum(int start, int end)
{
    if (end - start == 0)
    {
        return end;
    }
    else
    {
        return start + recursivesum(start + 1, end);
    }
}
