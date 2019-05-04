
#include <iostream>
#include <string>
#include <vector>
#include "ArraySet.h"

using namespace std;

int main()
{
    ArraySet<double> arrSet;

    cout << "arrSet's maximum number of elements is 3 (default).\n"
         << "Therefore, if we add three elements we should not\n"
         << "be able to add a fourth element. Let's test that out.\n\n";

    cout << "arrSet.size() = " << arrSet.size() << "\n";
    cout << "arrSet.add(3.14) = "
         << (arrSet.add(3.14) ? " 3.14" : " false");

    cout << "\n";

    cout << "arrSet.size() = " << arrSet.size() << "\n";
    cout << "arrSet.add(6.28) = "
         << (arrSet.add(6.28) ? " 6.28" : " false");

    cout << "\n";

    cout << "arrSet.size() = " << arrSet.size() << "\n";
    cout << "arrSet.add(1.23) = "
         << (arrSet.add(1.23) ? " 1.23" : " false");

    cout << "\n";

    cout << "arrSet.size() = " << arrSet.size() << "\n";
    cout << "arrSet.add(2.46) = "
         << (arrSet.add(2.46) ? " 2.46" : " false");

    cout << "\n\n";

    cout << "Now, let's test the addition of duplicate elements\n\n";

    ArraySet<int> intArrSet(10);

    cout << "intArrSet.size() = " << intArrSet.size() << "\n";
    cout << "intArrSet.add(314) = "
         << (intArrSet.add(314) ? " 314" : " false");

    cout << "\n";

    cout << "intArrSet.add(314) = "
         << (intArrSet.add(314) ? " 314" : " false");
    
    cout << "\n\n";

    cout << "Let's check the removal of elements from a set\n\n";

    cout << "arrSet.size() = " << arrSet.size() << "\n";
    cout << "arrSet.remove(6.28) = "
         << (arrSet.remove(6.28) ? " true" : " false");

    cout << "\n";

    cout << "arrSet.size() = " << arrSet.size() << "\n";

    cout << "\n\n";

    cout << "Let's check that we can get a vector from the set\n\n";

    std::vector<double> arrSetVect = arrSet.vector();
    bool sameSize = arrSet.size() == arrSetVect.size();

    cout << "The vector and set are" << (sameSize ? " " : "n't ")
         << "the same size (" << arrSetVect.size() << ")\n\n";
    
    cout << "Let's print out value of the vector and set\n";
    cout << "arrSet = " << arrSet << " and\n";
    cout << "arrSetVect = <";

    for (auto const &elem : arrSetVect)
    {
        cout << elem << ", ";
    }
    cout << ">\n";

    ArraySet<double> supArrSet(5);
    supArrSet.add(3.14);
    supArrSet.add(6.28);
    supArrSet.add(1.23);
    supArrSet.add(2.46);
    supArrSet.add(123.3);

    cout << "\nLet's check if one set is a subset of another set\n\n";

    cout << "supArrSet = " << supArrSet << " and\n"
         << "arrSet = " << arrSet << "\n"
         << "which means that arrSet is a subset of supArrSet.\n"
         << "Let's make sure that we get that from the code.\n\n";
    bool isSubset = supArrSet.isSubset(arrSet);
    cout << "supArrSet.isSubset(arrSet) = " << (isSubset ? "true\n" : "false\n");

    ArraySet<int> notSubSet(2);
    notSubSet.add(51);
    notSubSet.add(-3);

    isSubset = intArrSet.isSubset(notSubSet);

    cout << "\nThis one is NOT a subset so it should return false\n\n";
    cout << "intSubSet = " << intArrSet << " and \n";
    cout << "notSubSet = " << notSubSet << "\n";
    cout << "arrSet.isSubset(notSubSet) = " << (isSubset ? "true\n" : "false\n");

    cout << "\nNow it's time to perform a union\n";

    ArraySet<string> strSet1(5);
    strSet1.add("This");
    strSet1.add("is");
    strSet1.add("only");
    strSet1.add("a");
    strSet1.add("test");

    ArraySet<string> strSet2(8);
    strSet2.add("No");
    strSet2.add("it");
    strSet2.add("is");
    strSet2.add("not");
    strSet2.add("Don't");
    strSet2.add("listen");
    strSet2.add("to");
    strSet2.add("him");

    ArraySet<string> unionSet(12);
    strSet1.unionSet(strSet2, unionSet);

    cout << "strSet1 = " << strSet1 << " and\n";
    cout << "strSet2 = " << strSet2 << " and\n";
    cout << "unionSet = " << unionSet << "\n";

    ArraySet<string> interSet;
    strSet1.intersection(strSet2, interSet);

    cout << "\nLet's test the intersection method. The intersection between\n"
        << "strSet1 and strSet2 should be {is}\n\n";

    cout << "strSet1.intersection(strSet2, interSet) = " << interSet << "\n";

    cout << "\nLet's test the intersection between two sets of doubles\n";
    arrSet.add(2.46);
    ArraySet<double> dblSetInt(15);
    supArrSet.intersection(arrSet, dblSetInt);

    cout << "\nsupArrSet = " << supArrSet << "\n";
    cout << "\narrSet = " << arrSet << "\n";
    cout << "\ndblSetInt = " << dblSetInt << "\n";

    // cout << interSet;

    return 0;
}