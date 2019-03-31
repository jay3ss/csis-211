// Joshua Saunders
// CS/IS 211
// Lab 1
// Due March 31
//
// Prompt:
//
// Create a recursive program what will test three recursive functions. It
// would have a menu like:
// 
// 1. Recursive Factorial
// 2. Towers of Hanoi
// 3. Recursive summation
// 4. Exit
// 
// Enter selection: 3
// 
// Enter number: 4
// 
// Sum is 10
// 
// The Recursive Factorial and Towers of Hanoi are in the book and the lecture
// notes. The recursive summation will take an integer and sum value from 1 to
// the integer. For instance, for the integer of 4, the answer would be:
// 1 + 2 + 3 + 4 = 10
// 
// Don’t enter a number if the selection is 0 for quit.
#include <iostream>
#include <string>
#include "liblaboratory.h"

int main()
{
    Selection selection;

    int number;
    int result;

    do
    {
        displayMenu();
        std::cout << "\n\n";
        selection = getSelection();

        switch (selection)
        {
            case Selection::FACTORIAL:
                factorialSubmenu();
                break;
            case Selection::HANOI:
                hanoiSubmenu();
                break;
            case Selection::SUMMATION:
                summationSubmenu();
                break;
            case Selection::EXIT:
                exitMessage();
                break;
            default:
                invalidInputMessage();
                break;
        }
    // Keep looping until the user selects EXIT
    } while (!isExit(selection));

    return 0;
} // end main