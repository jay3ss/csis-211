#ifndef LIB_LABORATORY_H
#define LIB_LABORATORY_H

// enum for user input the choices available
enum class Selection
{
    FACTORIAL = 1,
    HANOI,
    SUMMATION,
    EXIT
};

// Recursive functions
int factorial(int);                 // calculates factorial
int summation(int);                 // calculates summation
int hanoi(int, char, char, char);   // solves Towers of Hanoi problem

// Menu-related functions
void displayMenu();
Selection getSelection();

// Convenience functions
Selection intToSelection(int);
bool isExit(Selection);

#endif // LIB_LABORATORY_H