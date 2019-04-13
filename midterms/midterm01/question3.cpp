#include <vector>

template <class T>
void combineTwoBags(ArrayBag<T> &bag1, ArrayBag<T> &bag1, ArrayBag<T> &newBag);

int main()
{
    return 0;
}

template <class T>
void combineTwoBags(ArrayBag<T> &bag1, ArrayBag<T> &bag1, ArrayBag<T> &newBag)
{
    std::vector<T> tempVector1 = bag1.toVector();
    std::vector<T> tempVector2 = bag2.toVector();

    int tempVector1Size = (int)tempVector1.size();
    int tempVector2Size = (int)tempVector2.size();

    for (int i = 0; i < tempVector1Size; i++)
    {
        newBag.add(tempVector1[i]);
    }

    for (int i = 0; i < tempVector2Size; i++)
    {
        newBag.add(tempVector2[i]);
    }
}