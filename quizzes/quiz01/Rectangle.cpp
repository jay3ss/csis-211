// Implementation file of the Rectangle class
// Joshua Saunders
// GCC CS/IS 211
// Quiz 1
// March 29, 2019
#include <iostream>     // for std::cout
#include "Rectangle.h"

// Displays the current object's data: length, width, area, perimeter
// to the screen
// @pre: None
// @post: Object's data displayed on screen
// @param: None
// @return: None
// 
// Example output: (length = 5, width = 10)
// Length:         5
// Width:          10
// Area:           50
// Perimeter:      30
void Rectangle::showData()
{
    std::cout << "Length:\t\t" << getLength()
              << "\nWidth:\t\t" << getWidth()
              << "\nArea:\t\t" << area()
              << "\nPerimeter:\t" << perimeter() << "\n";
} // end showData

// Sets the object's length and width
// @pre: len >= 0, wid >= 0
// @post: Object's data displayed on screen
// @param: len >= 0, wid >= 0
// @return: None
void Rectangle::setData(const double len, const double wid)
{
    length = len;
    width = wid;
} // end setData

// Calculates the object's area using the formula:
// Area = Length * Width
// @pre: None
// @post: None
// @param: None
// @return: double, the object's area
double Rectangle::area() const
{
    return length * width;
} // end area

// Calculates the object's perimeter using the formula:
// Perimeter = 2 * Length + 2 * Width
//           = 2 * (Length + Width)
// @pre: None
// @post: None
// @param: None
// @return: double, the object's perimeter
double Rectangle::perimeter() const
{
    return 2 * (length + width);
} // end perimeter

// Returns the object's width
// @pre: None
// @post: None
// @param: None
// @return: double, the object's length
double Rectangle::getLength() const
{
    return length;
} // end getLength

// Returns the object's width
// @pre: None
// @post: None
// @param: None
// @return: double, the object's width
double Rectangle::getWidth() const
{
    return width;
} // end getWidth

// Sets the object's len
// @pre: len >= 0
// @post: None
// @param: len, a non-negative double
// @return: None
void Rectangle::setLength(const double len)
{
    length = len;
} // end setLength

// Sets the object's width
// @pre: wid >= 0
// @post: None
// @param: wid, a non-negative double
// @return: None
void Rectangle::setWidth(const double wid)
{
    width = wid;
} // end setWidth