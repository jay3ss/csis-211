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
    return items_.insert(last + 1, anItem);
}

/** Returns a todo list item. */
TodoItem TodoList::item(int position)
{
    return items_.entry(position);
}

/** Inserts an item to the desired position in the todo list. */
bool TodoList::insert(int position, const TodoItem &anItem)
{
    return items_.insert(position, anItem);
}

/** Returns the integer number of items in the todo list. */
int TodoList::length()
{
    return items_.length();
}

/** Removes an item from the todo list. */
bool TodoList::remove(int position)
{
    return items_.remove(position);
}

/** Moves an existing item to a new position in the list. */
bool TodoList::move(int from, int to)
{
    bool notEmpty = !items_.isEmpty();
    bool isMoved = false;
    if (notEmpty)
    {
        // 1. Get the item from the "from" position
        TodoItem theItem = items_.entry(from);
        // 2. Remove the item from the "from" position
        bool isRemoved = items_.remove(from);
        if(isRemoved)
        {
            // 3. Insert the item into the "to" position
            isMoved = items_.insert(to, theItem);
        }
    }

    // Only returns true when both are true
    return notEmpty & isMoved;

}

/** Marks item as either in progress or complete. */
void TodoList::markAs(int position, item::status s)
{
    TodoItem theItem = item(position);
    theItem.status(s);
    items_.replace(position, theItem);
}
