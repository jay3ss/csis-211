// // Test the *Box classes
#include <iostream>
#include <string>
#include "PlainBox.h"
#include "MagicBox.h"

using namespace std;

void placeInBox(PlainBox<string> *theBox, string theItem);

int main()
{
    string specialItem = "Riches beyond compare!";
    string otherItem = "Hammer";

    PlainBox<string> *myPlainBoxPtr = new PlainBox<string>();
    placeInBox(myPlainBoxPtr, specialItem);

    MagicBox<string> *myMagicBoxPtr = new MagicBox<string>();
    placeInBox(myMagicBoxPtr, otherItem);
    placeInBox(myMagicBoxPtr, specialItem);

    cout << "The contents of mb1 are: " << myMagicBoxPtr->getItem() << endl;

    delete myPlainBoxPtr;
    myPlainBoxPtr = nullptr;
    delete myMagicBoxPtr;
    myMagicBoxPtr = nullptr;

    return 0;
}

void placeInBox(PlainBox<string> *theBox, string theItem)
{
    theBox->setItem(theItem);
}