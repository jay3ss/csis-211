#include "catch/catch.hpp"
#include "LinkedList.h"

// Test the axioms for the ADT list

// 1. (new List()).isEmpty() = true
TEST_CASE("Test behavior of newly a created list", "[LinkedList]")
{
    LinkedList<int> list;
    SECTION("A newly created list is empty")
    {
        REQUIRE(list.isEmpty());
    }

    // 2. (new List()).length() = 0
    SECTION("A newly created list has length of 0")
    {
        REQUIRE(list.length() == 0);
    }

    // 6. (new List()).remove(i) = false
    SECTION("A newly created list cannot have entries removed")
    {
        REQUIRE_FALSE(list.remove(1));
    }

    // 8. (new List()).entry(i) = error
    int anEntry = 3;
    SECTION("A newly created list cannot return entries")
    {
        REQUIRE_THROWS(list.entry(anEntry));
    }

    // 12. (new List()).replace(i, x) = error
    SECTION("A newly created list cannot replace entries")
    {
        REQUIRE_THROWS(list.replace(3, anEntry)); // #12
    }
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
    list.remove(1);

    REQUIRE(list.length() == (length - 1));
}

// 5. (aList.insert(i, item)).isEmpty() = false
TEST_CASE("A list with entries is not empty", "[LinkedList]")
{
    LinkedList<int> list;
    list.insert(1, 3);
    REQUIRE_FALSE(list.isEmpty());
}


TEST_CASE("Test behavior of adding and removing entries", "[LinkedList]")
{
    LinkedList<int> list;

    // Populate the list with entries
    for (int i = 1; i < 7; i++)
    {
        list.insert(i, i * i);
    }

    // 7. (aList.insert(i, x)).remove(i) = aList
    SECTION("When a new entry is inserted into the list and then removed, the original list is obtained")
    {
        bool isSame = true;
        list.remove(6);

        // Check that every entry is the same & in the same order
        int entry;
        for (int i = 1; i < 6; i++)
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
    SECTION("Entry x inserted into the ith position of a list, retrieving the ith item will result in x")
    {
        int position = 2;
        int entry = position * position;

        REQUIRE(entry == list.entry(position));
    }

    // 10. aList.entry(i) = (aList.insert(i, x)).entry(i + 1)
    SECTION("Adding an entry increases each following entry's position by one")
    {
        int insertionPoint = 1;
        list.insert(insertionPoint, -15);

        // Check that the position of each entry after the insertion point has been
        // increased by one
        bool isSame = true;
        int entryToCheck;
        int listEntry;
        for (int position = insertionPoint + 1; position < 6; position++)
        {
            // The entry is off by one, so adjust for it
            entryToCheck = (position - 1) * (position - 1);
            listEntry = list.entry(position);
            if (listEntry != entryToCheck)
            {
                isSame = false;
                break;
            }
        }

        REQUIRE(isSame);
        // Clean up from this section
        list.remove(insertionPoint);
    }

    // 11. aList.entry(i + 1) = (aList.remove(i)).entry(i)
    SECTION("Removing an entry decreases each following entry's position by one")
    {
        int removalPoint = 2;
        list.remove(removalPoint);

        // Check that the position of each entry after the removal point has been
        // decreased by one
        bool isSame = true;
        int entry, listEntry;
        for (int position = 1; position < 5; position++)
        {
            if (position >= 2)
            {
                // The entry is off by one, so adjust for it
                entry = (position + 1) * (position + 1);
            }
            else
            {
                entry = position * position;
            }

            listEntry = list.entry(position);
            if (list.entry(position) != entry)
            {
                isSame = false;
                break;
            }
        }

        REQUIRE(isSame);

        // Clean up from this section
        list.insert(removalPoint, removalPoint * removalPoint);
    }

    // 13. (aList.replace(i, x)).entry(i) = x
    SECTION("Replacing an entry with a new entry x, returns the new entry x")
    {
        int newEntry = 4;
        int position = 3;

        list.replace(position, newEntry);
        REQUIRE(newEntry == list.entry(position));
    }
}
