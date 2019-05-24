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
}

/** Returns a todo list item. */
TodoItem TodoList::item(int position)
{
}

/** Inserts an item to the desired position in the todo list. */
bool TodoList::insert(int position, const TodoItem &anItem)
{
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
