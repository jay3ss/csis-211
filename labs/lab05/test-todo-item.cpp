#include <string>
#include "catch/catch.hpp"
#include "TodoItem.h"

TEST_CASE("Test default behavior", "[TodoItem]")
{
    TodoItem item;

    SECTION("Default item is emtpy string")
    {
        REQUIRE(item.item() == "");
    }

    SECTION("Default status is INPROGRESS")
    {
        REQUIRE(item.status() == item::status::INPROGRESS);
    }
}

TEST_CASE("Can set and get item and status", "[TodoItem]")
{
    TodoItem item;

    SECTION("The item has changed")
    {
        std::string newString = "Testing change";
        item.item(newString);
        REQUIRE(item.item() == newString);
    }

    SECTION("The status has changed")
    {
        item::status newStatus = item::status::COMPLETE;
        item.status(newStatus);
        REQUIRE(item.status() == newStatus);
    }
}

TEST_CASE("Can compare TodoItem instances", "[TodoItem]")
{
    TodoItem item1("item #1");
    TodoItem item2("item #2");

    SECTION("The two items should be different")
    {
        REQUIRE(item1 != item2);
    }

    item1.item("item #2");

    SECTION("The two items should be the same")
    {
        REQUIRE(item1 == item2);
    }
}
