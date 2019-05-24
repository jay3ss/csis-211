#include "TodoList.h"

TodoList::TodoList()
{
}

TodoList::~TodoList()
{
}

/** Adds an item to the end of the todo list. */
bool TodoList::add(const TodoItem &anItem)
{
    int last = items_.length();
    // Insert the todo list item just after the last item
    items_.insert(last + 1, anItem);
}

/** Returns a todo list item. */
TodoItem TodoList::item(int position)
{
    return items_.entry(position);
}

/** Inserts an item to the desired position in the todo list. */
bool TodoList::insert(int position, const TodoItem &anItem)
{
}

/** Returns the integer number of items in the todo list. */
int TodoList::length()
{
    return items_.length();
}

/** Removes an item from the todo list. */
bool TodoList::remove(int position)
{
}

/** Moves an existing item to a new position in the list. */
bool TodoList::move(int from, int to)
{
}

/** Marks item as either in progress or complete. */
void TodoList::markAs(int position, item::status s)
{
}
