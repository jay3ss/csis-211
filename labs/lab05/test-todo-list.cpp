#include <string>
#include "catch/catch.hpp"
#include "TodoItem.h"
#include "TodoList.h"


TEST_CASE("Test behavior of newly a created list", "[TodoList]")
{
    TodoList todo;

    SECTION("The list has length of zero")
    {
        REQUIRE(todo.length() == 0);
    }

    SECTION("Cannot remove items from an empty list")
    {
        REQUIRE_FALSE(todo.remove(5));
    }

    SECTION("Cannot move items in an empty list")
    {
        REQUIRE_FALSE(todo.move(5, 10));
    }

    TodoItem item;
    item.item("Testing");
    SECTION("Adding an item increases the list's length by one")
    {
        int origLength = todo.length();
        REQUIRE(todo.add(item));
        REQUIRE((origLength + 1) == todo.length());
    }

    SECTION("The item was removed successfully")
    {
        REQUIRE(todo.add(item));
        REQUIRE(todo.remove(1));
        REQUIRE(todo.length() == 0);
    }
}

TEST_CASE("Working with a populated todo list", "[TodoList]")
{
    TodoList todo;
    TodoItem item;
    int numToAdd = 5;
    for (int position = 1; position <= numToAdd; position++)
    {
        item.item("Item #" + std::to_string(position));
        todo.add(item);
    }

    SECTION("The correct number of items were added")
    {
        REQUIRE(numToAdd == todo.length());
    }

    SECTION("The correct number of items are removed")
    {
        todo.remove(1);
        todo.remove(2);
        REQUIRE((numToAdd - 2) == todo.length());
    }

    SECTION("An item is moved to the correct place")
    {
        TodoItem item1("Item #1");
        TodoItem item3("Item #3");
        TodoItem temp;

        // Move item 3 to the 1 position
        REQUIRE(todo.move(3, 1));

        // Check that item 3 moved to position 1
        temp = todo.item(1);
        REQUIRE(temp == item3);

        // Check that item 1 moved to position 2
        temp = todo.item(2);
        REQUIRE(temp == item1);
    }

    SECTION("The list can change an item's status")
    {
        // Default status for an item is INPROGRESS, so change it
        todo.markAs(1, item::status::COMPLETE);

        // Get the item and that the item's status has changed
        TodoItem temp = todo.item(1);
        REQUIRE(item::status::COMPLETE == temp.status());
    }
}
