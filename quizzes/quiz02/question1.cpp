// Consider an ADT list of integers.Write a pseudocode function that computes
// the sum of the integers in the list aList.The definition of your function
// should be independent of the list’s implementation.
#include <iostream>

using namespace std;

template<class T>
class List
{
public:
    bool isEmpty();
    int getLength();
    bool insert(int i, T newEntry);
    bool remove(int i);
    void clear();
    T getEntry(int i);
    void setEntry(int i, T newEntry);
};

int listsum(List<int> list);

int main()
{

    return 0;
}

int listsum(List<int> aList)
{
    if (!list.isEmpty())
    {
        int count = 1;
        for (position = 1 through aList.getLength())
        {
            sum += aList.getEntry(position);
        }
    }

    return sum;
}

// int listsum(aList)
// {
//     if (!list.isEmpty())
//     {
//         for (position = 1 through aList.getLength())
//         {
//             sum += aList.getEntry(position);
//         }
//     }

//     return sum;
// }
