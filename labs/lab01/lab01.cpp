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
    int selection;
    Choice choice;

    int number;
    int result;

    // The towers for Towers of Hanoi
    char source = 'A';
    char destination = 'B';
    char spare = 'C';

    do
    {
        displayMenu();
        std::cout << "\n\n";
        choice = getSelection();

        switch (choice)
        {
            case Choice::FACTORIAL:
                std::cout << "\nRECURSIVE FACTORIAL"
                          << "\n-------------------"
                          << "\nEnter a number: ";
                std::cin >> number;
                result = factorial(number);
                std::cout << "\nThe result of factorial(" << number << ") is "
                          << result << "\n\n";
                break;
            case Choice::HANOI:
                std::cout << "\nTOWERS OF HANOI"
                          << "\n---------------"
                          << "\nEnter a number: ";
                std::cin >> number;
                std::cout << "The solution for Towers of Hanoi with "
                          << number << " tower(s) is\n\n";
                hanoi(number, source, destination, spare);
                std::cout << "\n";
                break;
            case Choice::SUMMATION:
                std::cout << "\nSUMMATION"
                          << "\n---------"
                          << "\nEnter a number: ";
                std::cin >> number;
                result = summation(number);
                std::cout << "\nThe result of summation(" << number << ") is "
                          << result << "\n\n";
                break;
            case Choice::EXIT:
                std::cout << "\nYou have chosen EXIT\n"
                          << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n\n";
                break;
        }
    } while (choice != Choice::EXIT);
    
    return 0;
} // end main