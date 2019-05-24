#ifndef _TODO_LIST_H_
#define _TODO_LIST_H_

#include "TodoItem.h"
#include "LinkedList.h"

class TodoList
{
private:
    LinkedList<TodoItem> items;
public:
    /** Constructor */
    TodoList();

    /** Constructor */
    ~TodoList();

    /** Adds an item to the end of the todo list */
    bool add();

    /** Inserts an item to the desired position in the todo list */
    bool insert();

    /** Removes an item from the todo list */
    bool remove();

    /** Moves an existing item to a new position in the list */
    bool move();

    /** Marks item as either in progress or complete */
    bool markAs();
};

#endif // _TODO_LIST_H_
