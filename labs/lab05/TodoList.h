#ifndef _TODO_LIST_H_
#define _TODO_LIST_H_

#include <iostream>
#include "LinkedList.h"
#include "TodoItem.h"

class TodoList
{
private:
    LinkedList<TodoItem> items_;
public:
    /** Constructor */
    TodoList();

    /** Constructor */
    ~TodoList();

    /** Adds an item to the end of the todo list.
    @post The item will be added to the end of the list.
    @param anItem The item to insert.
    @return True if item was inserted, false otherwise. */
    bool add(const TodoItem &anItem);

    /** Returns a todo list item.
    @param position The position of the item to retrieve.
    @return The todo list item. */
    TodoItem item(int position);

    /** Inserts an item to the desired position in the todo list.
    @post If 1 <= position <= length() + 1, the item will be inserted into the
        list and the position of the items after it will be increased by one.
    @param position The desired position of the todo item.
    @param anItem The item to insert.
    @return True if item was inserted, false otherwise. */
    bool insert(int position, const TodoItem &anItem);

    /** Returns the integer number of items in the todo list.
    @return The integer number of items in the list. */
    int length();

    /** Removes an item from the todo list.
    @post If 1 <= position <= length(), the item will be removed from the list
        and the position of the items after it will be decreased by one.
    @param position The position of the todo item to be removed.
    @return True if item was removed, false otherwise. */
    bool remove(int position);

    /** Moves an existing item to a new position in the list.
    @post If 1 <= from <= length() and 1 <= to <= length(), the item will be
        moved from the its original position to the new position. Items after
        the move positions may have their positions adjusted as well.
    @param from The position of the todo list item to move.
    @param to The position move the todo list item to.
    @return True if the move was successful, false otherwise. */
    bool move(int from, int to);

    /** Marks item as either in progress or complete.
    @post The item will have its status updated.
    @param position The position of the item to mark as either in progress or
        complete.
    @param s The new status of the item. */
    void markAs(int position, item::status s);
};

#endif // _TODO_LIST_H_
