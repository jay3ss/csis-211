#include <iostream>
#include <string>
#include "PlainBox.h"

using namespace std;

int main()
{
    PlainBox<double> pb1(3.14);
    PlainBox<string> pb2("hey-o!");

    cout << "The contents of mb1 are " << pb1.getItem() << endl;
    cout << "The contents of mb2 are " << pb2.getItem() << endl;

    return 0;
}