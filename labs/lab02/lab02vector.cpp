#include <iostream>
#include "VectorInterface.h"


int main()
{
    const int NUM_ELEMENTS = 3;
    VectorInterface<int> v1(NUM_ELEMENTS);
    VectorInterface<int> v2(NUM_ELEMENTS);
    // VectorInterface<int> v3;

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        v1[i] = i;
        v2[i] = i * i;
    }

    std::cout << v1;
    std::cout << v2;

    return 0;
}