// Joshua Saunders
// CS/IS 211
// Lab 2
// Due April 21
//

#include <iostream>
#include <string>
#include "Set.h"

using namespace std;

int main()
{
    Set<int> intSet;
    Set<string> stringSet;

    cout << (intSet.isEmpty() ? "Empty\n" : "Not empty\n");
    cout << (stringSet.isEmpty() ? "Empty\n" : "Not empty\n");

    int three = 3;
    string threeStr = "3";
    cout << three << (intSet.isIn(three) ? " is in set\n" : " isn't in set\n");
    cout << threeStr << (stringSet.isIn(threeStr) ? " is in set\n" : " isn't in set\n");

    bool addedInt = intSet.add(three);
    bool addedStr = stringSet.add(threeStr);

    cout << three << (addedInt ? " was added\n" : " wasn't added\n");
    cout << threeStr << (addedStr ? " was added\n" : " wasn't added\n");

    return 0;
} // end main