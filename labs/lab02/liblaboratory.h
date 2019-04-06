// Joshua Saunders
// CS/IS 211
// Lab 1
// Due March 31
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
void factorialSubmenu();
void hanoiSubmenu();
void summationSubmenu();
void exitMessage();
void invalidInputMessage();

// Convenience functions
Selection intToSelection(int);
bool isExit(Selection);
bool isZero(int);

#endif // LIB_LABORATORY_H