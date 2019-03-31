#include <iostream>
#include <string>
#include "liblaboratory.h"

/** Computes the factorial of the positive integer n.
 @pre   n: must be greater than or equal to 1.
 @param n: the number to 
 @post  None.
 @return  The factorial of n; n is unchanged. */
int factorial(int n)
{
    if (n == 1)
        return 1;
    else
        // n > 0, so n-1 >= 0. Thus, factorial(n-1) returns (n-1)!
        return n * factorial(n - 1); // n * (n-1)! is n!
} // end factorial

/** Computes the solution to the Towers of Hanoi problem. Prints the
    necessary steps to solve the problem given three towers and a given
    amount of disks.
 @pre   count: must be greater than or equal to 1.
 @param count: the number of disks
        source: source tower
        destination: destination tower
        spare: spare tower
 @post  None.
 @return The factorial of n; n is unchanged. */
int hanoi(int count, char source, char destination, char spare)
{
    if (count == 1)
    {
        std::cout << "Move top disk from pole " << source
                  << " to pole " << destination << std::endl;
    }
    else
    {
        hanoi(count - 1, source, spare, destination); // A
        hanoi(1, source, destination, spare);         // B
        hanoi(count - 1, spare, destination, source); // C
    }
} // end hanoi

/** Computes the summation of a sequence of positive integers from 1 to n.
 @pre   n: must be greater than or equal to 1.
 @param n: the number to add up to.
 @post  None.
 @return  The summation of a sequence of nonnegative integers from 1 to n;
          n is unchanged. */
int summation(int n)
{
    if (n == 1)
        return 1;
    else
        return n + summation(n - 1);
} // end summation

// Menu-related functions
/** Displays a menu for the user of the form:
1. Recursive Factorial
2. Towers of Hanoi
3. Recursive summation
4. Exit

 @pre  None.
 @param None
 @post  None.
 @return  None. */
void displayMenu()
{
    std::string menu = "\
Please make a choice from the following selection:\n\n\
1. Recursive Factorial\n\
2. Towers of Hanoi\n\
3. Recursive Summation\n\
4. Exit";

    std::cout << menu;
} // end displayMenu

/** Displays a menu for the user of the form:
1. Recursive Factorial
2. Towers of Hanoi
3. Recursive summation
4. Exit

 @pre  None.
 @param None
 @post  None.
 @return  None. */
Selection getSelection()
{
    int selection;
    std::cout << "Enter a selection: ";
    std::cin >> selection;
    return intToSelection(selection);
} // end getSelection

/** Displays asub menu for the factorial function and then runs
    the factorial function

 @pre  None.
 @param None
 @post  None.
 @return  None. */
void factorialSubmenu()
{
    int number;
    int result;
    std::cout << "\nRECURSIVE FACTORIAL"
              << "\n-------------------"
              << "\nEnter a number: ";
    std::cin >> number;
    // If number isn't zero, then find the factorial of number.
    // Otherwise, do nothing.
    if (!isZero(number))
    {
        result = factorial(number);
        std::cout << "\nThe result of factorial(" << number << ") is "
                  << result << "\n\n";
    }

} // end factorialSubmenu

/** Displays a submenu for the hanoi function and then runs
    the hanoi function

 @pre  None.
 @param None
 @post  None.
 @return  None. */
void hanoiSubmenu()
{
    int number;
    int result;
    // The towers for Towers of Hanoi
    char source = 'A';
    char destination = 'B';
    char spare = 'C';
    std::cout << "\nTOWERS OF HANOI"
              << "\n---------------"
              << "\nEnter a number: ";
    std::cin >> number;
    if (!isZero(number))
    {
        std::cout << "The solution for Towers of Hanoi with "
                  << number << " tower(s) is\n\n";
        hanoi(number, source, destination, spare);
        std::cout << "\n";
    }

} // end hanoiSubmenu

/** Displays a submenu for the summation function and then runs
    the summation function

 @pre  None.
 @param None
 @post  None.
 @return  None. */
void summationSubmenu()
{
    int number;
    int result;
    std::cout << "\nSUMMATION"
              << "\n---------"
              << "\nEnter a number: ";
    std::cin >> number;
    if (!isZero(number))
    {
        result = summation(number);
        std::cout << "\nThe result of summation(" << number << ") is "
                  << result << "\n\n";
    }

} // end summationSubmenu

/** Displays an exit message:

 @pre  None.
 @param None
 @post  None.
 @return  None. */
void exitMessage()
{
    std::cout << "\nYou have chosen EXIT\n"
              << "Goodbye!\n";

} // end exitMessage

/** Displays a message indicating an invalid input

 @pre  None.
 @param None
 @post  None.
 @return  None. */
void invalidInputMessage()
{
    std::cout << "Invalid selection. Please try again.\n\n";

} // end invalidInputMessage

// Convenience functions
/** Converts an integer to a Selection type.
 @pre  number must be an integer between (inclusive of) 1 and 4
 @param number: the number from the menu
 @post  None.
 @return  A Selection type corresponding to the number. */
Selection intToSelection(int number)
{
    return static_cast<Selection>(number);
} // end intToSelection

/** Checks if the selection is exit.
 @pre  None
 @param selection: user selection
 @post  None.
 @return  True if is EXIT, false if not. */
 bool isExit(Selection selection)
 {
     return selection == Selection::EXIT;
 } // end isExit

 /** Checks if an integer is zero.
 @pre  None
 @param selection: user selection
 @post  None.
 @return  True if is EXIT, false if not. */
 bool isZero(int num)
 {
     return num == 0;
 } // end isZero