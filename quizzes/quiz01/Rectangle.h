// Declaration of the Rectangle class
// Joshua Saunders
// GCC CS/IS 211
// Quiz 1
// March 29, 2019
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
private:
    double length;  // holds the length of the Rectangle
    double width;   // holds the width of the Rectangle
public:
    Rectangle(const double l = 0, const double w = 0) : 
        length(l), width(w) {} // end constructor

    // To calculate mathematical properties of a rectangle
    double area() const;        // calculates the area of the Rectangle
    double perimeter() const;   // calculates the perimeter of the Rectangle

    // Accessors
    double getLength() const;
    double getWidth() const;

    // Mutators
    void setLength(const double);
    void setWidth(const double);
    void setData(const double, const double);

    // Prints the properties of the Rectangle: length, width, area, perimeter
    // to the screen
    void showData();
}; // end Rectangle

#endif // RECTANGLE_H