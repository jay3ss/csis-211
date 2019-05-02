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

     cout << "Add 5 elements to the set:\n";

     for (int i = 0; i < 5; i++)
     {
          intLS.add(i);
     }
     cout << "size(): returns " << intLS.size()
          << "; should be 5\n\n";

     cout << "isElement(3): returns " << intLS.isElement(3)
          << "; should be 1 (true)\n\n";

     cout << "isElement(10): returns " << intLS.isElement(10)
          << "; should be 0 (false)\n\n";

     cout << "intLS = " << intLS << "\n\n";

     cout << "Try to add an element to the set that is an element already:\n";

     cout << "add(3): returns " << intLS.add(3)
          << "; should be 0 (false)\n\n";

     cout << "Remove an element from the set:\n";

     cout << "remove(2): returns " << intLS.remove(2)
          << "; should return 1 (true)\n\n";

     cout << "isElement(2): returns " << intLS.isElement(2)
          << "; should return 0 (false)\n\n";

     cout << "intLS = " << intLS << "\n\n";

     cout << "Create a vector from intLS:\n";
     vector<int> vect1 = intLS.vector();

     cout << "size() == vect1.size(): returns " << (intLS.size() == vect1.size())
          << "; should return 1 (true)\n\n";

     //     cout << "Create a new set that is a subset:\n";

     //     ArraySet<string> set2;
     //     for (int i = 0; i < 3; i++)
     //     {
     //         set2.add(elements[i]);
     //     }

     //     cout << "isSubset(set2): returns " << intLS.isSubset(set2)
     //          << "; should return 1 (true)\n\n";

     //     cout << "Create a new set that is not a subset:\n";
     //     ArraySet<string> set3(2);
     //     set3.add("Not");
     //     set3.add("subset");

     //     cout << "isSubset(set3): returns " << intLS.isSubset(set3)
     //          << "; should return 0 (false)\n\n";

     //     cout << "remove(\"is\"): returns " << intLS.remove("is")
     //          << "; should return 1 (true)\n\n";

     //     cout << "remove(\"C++\"): returns " << intLS.remove("C++")
     //          << "; should return 0 (false)\n\n";

     //     cout << "Create a union between two sets:\n";
     //     ArraySet<string> unionSet(10);  // more than enough room for the union
     //     intLS.unionSet(set2, unionSet);

     //     cout << "unionSet(set2, unionSet): results in unionSet containing "
     //          << unionSet << "; should contain {This, is, a, set, test}\n\n";

     //     cout << "Create an intersection between two sets:\n";
     //     ArraySet<string> interSet(10); // more than enough room for the union
     //     intLS.intersection(set2, interSet);

     //     cout << "intersection(set2, interSet): results in interSet containing "
     //          << interSet << "; should contain {This, a}\n\n";

     //     cout << "The intersection of two sets is a subset of both sets:\n"
     //          << "isSubset(interSet): returns " << intLS.isSubset(interSet)
     //          << "; should be 1 (true)\n\n";

     //     cout << "A union of two sets is the superset of those two sets:\n"
     //          << "unionSet.isSubset(set2): returns " << unionSet.isSubset(set2)
     //          << "; should be 1 (true)";

     return 0;
}
