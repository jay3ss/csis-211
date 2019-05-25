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
