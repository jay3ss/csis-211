#include <iostream>
#include <string>
#include <vector>
#include "LinkedSet.h"

using namespace std;

int main()
{
    LinkedSet<int> intLS;

    cout << "Testing the Linked-based Set:\n"
        << "=============================\n\n"
        << "The initial set is empty.\n";

    cout << "isEmpty(): returns " << intLS.isEmpty()
        << "; should be 1 (true)\n\n";

    cout << "cout << intLs: "
        << intLS << "; should be {}\n\n";

    cout << "Add 5 elements to the set:\n"
        << "--------------------------\n";

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

    cout << "Try to add an element to the set that is an element already:\n"
        << "------------------------------------------------------------\n";

    cout << "add(3): returns " << intLS.add(3)
        << "; should be 0 (false)\n\n";

    cout << "Remove an element from the set:\n"
        << "-------------------------------\n";

    cout << "remove(2): returns " << intLS.remove(2)
        << "; should return 1 (true)\n\n";

    cout << "isElement(2): returns " << intLS.isElement(2)
        << "; should return 0 (false)\n\n";

    cout << "intLS = " << intLS << "\n\n";

    cout << "Create a vector from intLS:\n"
        << "---------------------------\n";
    vector<int> vect1 = intLS.vector();

    cout << "size() == vect1.size(): returns " << (intLS.size() == vect1.size())
        << "; should return 1 (true)\n\n";

    cout << "Create a new set that is a subset and add 2 back to intLS:\n"
        << "----------------------------------------------------------\n";
    intLS.add(2);  // add 2 back to the set

    LinkedSet<int> set2;
    for (int i = 0; i < 3; i++)
    {
        set2.add(i);
    }

    cout << "isSubset(set2): returns " << intLS.isSubset(set2)
        << "; should return 1 (true)\n\n";

    cout << "Create a new set that is not a subset:\n"
        << "--------------------------------------\n";

    LinkedSet<int> set3;
    set3.add(54);
    set3.add(14);
    set3.add(0);

    cout << "set3 = " << set3 << "\n\n";

    cout << "isSubset(set3): returns " << intLS.isSubset(set3)
        << "; should return 0 (false)\n\n";

    cout << "remove(0): returns " << intLS.remove(0)
        << "; should return 1 (true)\n\n";

    cout << "remove(15): returns " << intLS.remove(15)
        << "; should return 0 (false)\n\n";

    cout << "Create a union between two sets:\n"
        << "--------------------------------\n";
    LinkedSet<int> unionSet;
    intLS.unionSet(set3, unionSet);

    cout << "unionSet(set3, unionSet): results in"
        << "\nunionSet containing " << unionSet
        << "; should contain {0, 1, 2, 3, 4, 14, 54}\n"
        << "(not necessarily in the same order)\n\n";

    cout << "A union of two sets is the superset of those two sets:\n"
        << "unionSet.isSubset(set3): returns " << unionSet.isSubset(set3)
        << "; should be 1 (true)\n"
        << "unionSet.isSubset(intLS): returns " << unionSet.isSubset(intLS)
        << "; should be 1 (true)\n\n";

    cout << "Create an intersection between two sets:\n"
        << "----------------------------------------\n";
    LinkedSet<int> interSet;
    intLS.intersection(set2, interSet);

    cout << "intersection(set2, interSet): results in\n"
        << "interSet containing " << interSet
        << "; should contain {1, 2}\n\n";

    cout << "The intersection of two sets is a subset of both sets:\n"
        << "isSubset(interSet): returns " << intLS.isSubset(interSet)
        << "; should be 1 (true)\n";

    cout << "set2.isSubset(intLS): returns " << set2.isSubset(interSet)
        << "; should be 1 (true)\n\n";

    LinkedSet<int> diffSet;
    intLS.difference(set2, diffSet);

    cout << "intersection(set2, diffSet): results in\n"
        << "diffSet containing " << diffSet
        << "; should contain {3, 4}\n\n";

    cout << "The difference of two sets is a subset of only the first set:\n"
        << "isSubset(diffSet): returns " << intLS.isSubset(diffSet)
        << "; should be 1 (true)\n";

    cout << "set2.isSubset(intLS): returns " << set2.isSubset(diffSet)
        << "; should be 0 (false)\n\n";

    cout << "Create a copy of intLS:\n"
        << "-----------------------\n\n";
    LinkedSet<int> copySet(intLS);

    cout << "Two sets are equivalent if and only if they are subsets of each other:\n";

    cout << "isSubset(copySet): returns " << intLS.isSubset(copySet)
        << "; should return 1 (true)\n";
    cout << "copy.isSubset(intLS): returns " << copySet.isSubset(intLS)
        << "; should return 1 (true)\n\n";

    cout << "Test the overloaded operators:\n"
        << "==============================\n\n";

    cout << "Instantiate a set and assign another set's contents to it:\n\n"
        << "eqSet = intLS. The two sets should be equivalent (subsets of each other)\n";

    LinkedSet<int> eqSet;
    eqSet = intLS;

    cout << "isSubset(eqSet): returns " << intLS.isSubset(eqSet)
        << "; should return 1 (true)\n";
    cout << "eqSet.isSubset(intLS): returns " << eqSet.isSubset(intLS)
        << "; should return 1 (true)\n\n";

    cout << "Perform a union using the '+' operator:\n\n"
        << "uSet = set2 + set3\n";

    LinkedSet<int> uSet;
    uSet = set2 + set3;

    cout << "A union of two sets is the superset of those two sets:\n"
        << "unionSet.isSubset(set2): returns " << uSet.isSubset(set2)
        << "; should be 1 (true)\n"
        << "unionSet.isSubset(set3): returns " << uSet.isSubset(set3)
        << "; should be 1 (true)\n\n";

    return 0;
}
