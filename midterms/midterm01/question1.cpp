// Midterm 1 - Question 1
// Imagine that you have just left a store with a bag of groceries. You are
// concerned that the fragile items will not survive the trip home, so when
// you reach your car, you place those items into their own bag. If Bag is a
// class of bags, write C++ statements that remove all the items from storeBag
// and place them into one of two new bags, as follows: Place all occurrences of
// bread and eggs into fragileBag, and all other items into groceryBag. When
// you are done, storeBag should be empty. Assume that grocery items are
// represented by strings.
#include <string>
#include <vector>
#include "Bag.h"
int main()
{
    Bag<std::string> storeBag;

// Assuming that storeBag is already instantiated and filled with items
Bag<std::string> fragileBag;
Bag<std::string> groceryBag;


std::vector<std::string> storeBagVector = storeBag.toVector();
int numItems = (int)storeBagVector.size();
std::string bagItem;
for (int i = 0; i < numItems; i++)
{
    bagItem = storeBagVector[i];
    if (bagItem == "bread" || bagItem == "eggs")
    {
        fragileBag.add(bagItem);
    }
    else
    {
        groceryBag.add(bagItem);
    }
}


        return 0;
}

