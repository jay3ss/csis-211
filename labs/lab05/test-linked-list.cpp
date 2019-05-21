#include "catch/catch.hpp"
#include "LinkedList.h"

// Test the axioms for the ADT list

// 1. (new List()).isEmpty() = true
TEST_CASE("A newly created list is empty", "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE(list.isEmpty());
}

// 2. (new List()).length() = 0
TEST_CASE("A newly created list has length of 0", "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE(list.length() == 0);
}

// 6. (new List()).remove(i) = false
TEST_CASE("A newly created list cannot have entries removed", "[LinkedList]")
{
    LinkedList<int> list;
    REQUIRE_FALSE(list.remove(1));
}

// 8. (new List()).entry(i) = error
TEST_CASE("A newly created list cannot return entries", "[LinkedList]")
{
    LinkedList<int> list;
    int anEntry = 3;
    REQUIRE_THROWS(list.entry(anEntry));
}

// 12. (new List()).replace(i, x) = error
TEST_CASE("A newly created list cannot replace entries", "[LinkedList]")
{
    LinkedList<int> list;
    int anEntry = 3;
    REQUIRE_THROWS(list.replace(3, anEntry)); // #12
}

// 3. aList.length() = (aList.insert(i, x)).length() - 1
TEST_CASE("Adding an entry increases the list's length by one", "[LinkedList]")
{
    LinkedList<int> list;
    int oldLength = list.length();
    list.insert(1, 5);
    REQUIRE((oldLength + 1) == list.length());
}

// 4. aList.length() = (aList.remove(i)).length() + 1
TEST_CASE("Removing an entry decreases the list's length by one", "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(1, 3);
    int length = list.length();

    REQUIRE(list.length() == (length - 1));
}

// 5. (aList.insert(i, item)).isEmpty() = false
TEST_CASE("A list with entries is not empty", "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(1, 3);
    REQUIRE_FALSE(list.isEmpty());
}

// 7. (aList.insert(i, x)).remove(i) = aList
TEST_CASE("When a new entry is inserted into the list and then removed, the original list is obtained", "[LinkedList]")
{
    LinkedList<int> list;

    // Populate the list with entries
    for (int i = 1; i < 6; i++)
    {
        list.insert(i, i * i);
    }

    bool isSame = true;
    list.remove(5);

    // Check that every entry is the same & in the same order
    int entry;
    for (int i = 1; i < 5; i++)
    {
        entry = list.entry(i);
        // We've found an entry that doesn't match, quit the loop
        if (entry != i * i)
        {
            isSame = false;
            break;
        }
    }

    REQUIRE(isSame);
}

// 9. (aList.insert(i, x)).entry(i) = x
TEST_CASE("Entry x inserted into the ith position of a list, retrieving the i th item will result in x", "[LinkedList]")
{
    LinkedList<int> list;

    // Populate the list with entries
    for (int i = 1; i < 6; i++)
    {
        list.insert(i, i * i);
    }

    int position = 2;
    int entry = position * position;

    REQUIRE(entry == list.entry(position));
}

// 10. aList.entry(i) = (aList.insert(i, x)).entry(i + 1)
TEST_CASE("Adding an entry increases each following entry's position by one", "[LinkedList]")
{
    LinkedList<int> list;

    // Populate the list with entries
    for (int i = 1; i < 6; i++)
    {
        list.insert(i, i * i);
    }

    int insertionPoint = 1;
    list.insert(insertionPoint, -15);

    // Check that the position of each entry after the insertion point has been
    // increased by one
    bool isSame = true;
    int entry;
    for (int position = insertionPoint + 1; position < 6; position++)
    {
        // The entry is off by one, so adjust for it
        entry = (position - 1) * (position - 1);
        if (list.entry(position) != entry)
        {
            isSame = false;
            break;
        }
    }

    REQUIRE(isSame);
}

// 11. aList.entry(i + 1) = (aList.remove(i)).entry(i)
TEST_CASE("Removing an entry decreases each following entry's position by one", "[LinkedList]")
{
    LinkedList<int> list;

    // Populate the list with entries
    for (int i = 1; i < 6; i++)
    {
        list.insert(i, i * i);
    }

    int removalPoint = 2;
    list.remove(removalPoint);

    // Check that the position of each entry after the removal point has been
    // decreased by one
    bool isSame = true;
    int entry;
    for (int position = removalPoint; position < 6; position++)
    {
        // The entry is off by one, so adjust for it
        entry = (position + 1) * (position + 1);
        if (list.entry(position) != entry)
        {
            isSame = false;
            break;
        }
    }

    REQUIRE(isSame);
}

// 13. (aList.replace(i, x)).entry(i) = x
TEST_CASE("Replacing an entry with a new entry x, returns the new entry x", "[LinkedList]")
{
    LinkedList<int> list;

    // Populate the list with entries
    for (int i = 1; i < 6; i++)
    {
        list.insert(i, i * i);
    }

    int newEntry = 4;
    int position = 3;

    list.replace(position, newEntry);

    int replacement = list.entry(position);
    bool isSame = newEntry == replacement;

    REQUIRE(isSame);
}
