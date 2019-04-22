#include <iostream>
#include "VectorInterface.h"


int main()
{
    const int NUM_ELEMENTS = 3;
    VectorInterface<int> v1(NUM_ELEMENTS);
    VectorInterface<int> v2(NUM_ELEMENTS);

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        v1[i] = i;
        v2[i] = i * i;
    }

    std::cout << "v1 = " << v1 << "\n";
    std::cout << "v2 = " << v2 << "\n";

    VectorInterface<int> v3(NUM_ELEMENTS);
    v3 = v1 + v2;
    std::cout << "v3 = v1 + v2 = " << v3 << "\n";

    v3 = v1 - v2;
    std::cout << "v3 = v1 - v2 = " << v3 << "\n";

    v3 = v1 * v2;
    std::cout << "v3 = v1 * v2 = " << v3 << "\n";

    double v1Norm = v1.norm();
    std::cout << "Norm of v3 = " << v1Norm << "\n";
    
    double v2Norm = v2.norm();
    std::cout << "Norm of v3 = " << v2Norm << "\n";

    double v3Norm = v3.norm();
    std::cout << "Norm of v3 = " << v3Norm << "\n";

    return 0;
}