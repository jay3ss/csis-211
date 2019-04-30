#include <iostream>
#include <string>
#include <vector>
#include "LinkedSet.h"

using namespace std;

int main()
{
     LinkedSet<int> intLS;

         cout << "Testing the Linked-based Set:\n"
              << "---------------------------\n\n"
              << "The initial set is empty.\n";

         cout << "size(): returns " << intLS.size()
              << "; should be 0\n\n";

     //     cout << "Add 5 elements to the set:\n";

     //     string elements[] = {"This", "is", "a", "test", "set"};
     //     for (int i = 0; i < 5; i++)
     //     {
     //         set1.add(elements[i]);
     //     }
     //     cout << "size(): returns " << set1.size()
     //          << "; should be 5\n\n";

     //     cout << "isElement(\"This\"): returns " << set1.isElement("This")
     //          << "; should be 1 (true)\n\n";

     //     cout << "isElement(\"C++\"): returns " << set1.isElement("C++")
     //          << "; should be 0 (false)\n\n";

     //     cout << "Create a new set that is a subset:\n";

     //     ArraySet<string> set2;
     //     for (int i = 0; i < 3; i++)
     //     {
     //         set2.add(elements[i]);
     //     }

     //     cout << "isSubset(set2): returns " << set1.isSubset(set2)
     //          << "; should return 1 (true)\n\n";

     //     cout << "Create a new set that is not a subset:\n";
     //     ArraySet<string> set3(2);
     //     set3.add("Not");
     //     set3.add("subset");

     //     cout << "isSubset(set3): returns " << set1.isSubset(set3)
     //          << "; should return 0 (false)\n\n";

     //     cout << "remove(\"is\"): returns " << set1.remove("is")
     //          << "; should return 1 (true)\n\n";

     //     cout << "remove(\"C++\"): returns " << set1.remove("C++")
     //          << "; should return 0 (false)\n\n";

     //     cout << "Create a union between two sets:\n";
     //     ArraySet<string> unionSet(10);  // more than enough room for the union
     //     set1.unionSet(set2, unionSet);

     //     cout << "unionSet(set2, unionSet): results in unionSet containing "
     //          << unionSet << "; should contain {This, is, a, set, test}\n\n";

     //     cout << "Create an intersection between two sets:\n";
     //     ArraySet<string> interSet(10); // more than enough room for the union
     //     set1.intersection(set2, interSet);

     //     cout << "intersection(set2, interSet): results in interSet containing "
     //          << interSet << "; should contain {This, a}\n\n";

     //     cout << "Create a vector from set1:\n";
     //     vector<string> vect1 = set1.vector();

     //     cout << "size() == vect1.size(): returns " << (set1.size() == vect1.size())
     //          << "; should return 1 (true)\n\n";

     //     cout << "The intersection of two sets is a subset of both sets:\n"
     //          << "isSubset(interSet): returns " << set1.isSubset(interSet)
     //          << "; should be 1 (true)\n\n";

     //     cout << "A union of two sets is the superset of those two sets:\n"
     //          << "unionSet.isSubset(set2): returns " << unionSet.isSubset(set2)
     //          << "; should be 1 (true)";

     return 0;
}
