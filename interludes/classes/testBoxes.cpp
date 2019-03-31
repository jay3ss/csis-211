#include <iostream>
#include <string>
#include "MagicBox.h"
#include "PlainBox.h"

using namespace std;

// Function prototypes
void placeInBox(PlainBox<string> &theBox, string theItem);

int main()
{
    string specialItem = "Riches beyond compare!";
    string otheritem = "Hammer";

    PlainBox<string> myPlainBox;
    placeInBox(myPlainBox, specialItem);

    MagicBox<string> myMagicBox;
    placeInBox(myMagicBox, otheritem);
    placeInBox(myMagicBox, specialItem);

    cout << myMagicBox.getItem() << endl;

    return 0;
}

void placeInBox(PlainBox<string> &theBox, string theItem)
{
    theBox.setItem(theItem);
}