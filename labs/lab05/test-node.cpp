#include "catch/catch.hpp"
#include "Node.h"

TEST_CASE("Test default behavior", "[NodeTest]")
{
    Node<int> node(137);

    SECTION("The next pointer should be the nullptr")
    {
        REQUIRE(node.next() == nullptr);
    }
}

TEST_CASE("Can set and get item and next", "[NodeTest]")
{
    Node<int> node1(137);

    SECTION("Can set and get item")
    {
        int newItem = 223;
        node1.item(newItem);

        REQUIRE(newItem == node1.item());
    }

    SECTION("Can set and get next")
    {
        Node<int> node2(1983);
        node1.next(&node2);

        REQUIRE(&node2 == node1.next());
    }
}
