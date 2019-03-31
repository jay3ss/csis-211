#include <iostream>
#include "Rectangle.h"

int main()
{
    // Using the setData member method to set the
    // length and width of the rectangle
    std::cout << "Using the setData member method to set the data\n";
    Rectangle rectangle1;
    rectangle1.setData(5, 10);
    rectangle1.showData();

    std::cout << "\n";

    // Using the constructor to set the length
    // and width of the rectangle
    std::cout << "Using the constructor to set the data\n";
    Rectangle rectangle2(15, 100);
    rectangle2.showData();

    return 0;
}