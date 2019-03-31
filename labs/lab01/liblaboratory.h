#ifndef LIB_LABORATORY_H
#define LIB_LABORATORY_H

// enum for user input the choices available
enum class Choice
{
    FACTORIAL = 1,
    HANOI,
    SUMMATION,
    EXIT
};

int factorial(int);
int summation(int);
int hanoi(int count, char source, char destination, char spare);

// Menu-related functions
void displayMenu();
Choice intToChoice(int);

#endif // LIB_LABORATORY_H