// Test the MagicBox class
#include <iostream>
#include <string>
#include "MagicBox.h"

using namespace std;

int main()
{
    MagicBox<double> mb1(3.14);
    MagicBox<double> mb2 = mb1.getItem();

    cout << "The contents of mb1 are " << mb1.getItem() << endl;
    cout << "The contents of mb2 are " << mb2.getItem() << endl;
    return 0;
}