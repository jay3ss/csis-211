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
    Set<double> dblSet(30);

    cout << (intSet.isEmpty() ? "Empty\n" : "Not empty\n");
    cout << (stringSet.isEmpty() ? "Empty\n" : "Not empty\n");
    cout << (dblSet.isEmpty() ? "Empty\n" : "Not empty\n");

    int threeInt = 3;
    string threeStr = "3";
    double threeDbl = 3.0;
    cout << threeInt << (intSet.isIn(threeInt) ? " is in set\n" : " isn't in set\n");
    cout << threeStr << (stringSet.isIn(threeStr) ? " is in set\n" : " isn't in set\n");
    cout << threeDbl << (dblSet.isIn(threeDbl) ? " is in set\n" : " isn't in set\n");

    bool addedInt = intSet.add(threeInt);
    bool addedStr = stringSet.add(threeStr);
    bool addedDbl = dblSet.add(threeDbl);

    cout << threeInt << (addedInt ? " was added\n" : " wasn't added\n");
    cout << threeStr << (addedStr ? " was added\n" : " wasn't added\n");
    cout << threeDbl << (addedDbl ? " was added\n" : " wasn't added\n\n");

    std::cout << "Let's add elements individually\n";
    intSet.add(15);
    intSet.add(26);

    int intArr[] = {3, 3, 6, 5, 4, 3, 2, 1, 3, 4};
    int intArrSize = sizeof(intArr) / sizeof(intArr[0]);
    std::cout << "The number of elements in the array to be added is " << intArrSize << "\n\n";

    std::cout << "intSet before adding more elements\n"
              << intSet << "\n\n";

    std::cout << "The number of objects in intSet is " << intSet.size() << "\n";
    std::cout << "The maximum number of objects in intSet is " << intSet.maxSize() << "\n\n";

    intSet.add(intArr, intArrSize);

    std::cout << "intSet after adding more elements\n"
              << intSet << "\n\n";
    std::cout << "The number of objects in intSet is " << intSet.size() << "\n";
    std::cout << "The maximum number of objects in intSet is " << intSet.maxSize() << "\n\n";

    std::cout << "Let's remove an element (" << threeInt << ")\n";
    if (intSet.isIn(threeInt))
    {
        intSet.remove(threeInt);
    }

    std::cout << "Here's the contents of intSet\n";
    std::cout << intSet << "\n\n";

    return 0;
} // end main