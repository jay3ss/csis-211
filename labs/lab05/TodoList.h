#ifndef _TODO_LIST_H_
#define _TODO_LIST_H_

#include <string>
#include "LinkedList.h"

class TodoList
{
private:
    LinkedList<std::string> list;
public:
    TodoList();
    ~TodoList();
};

#endif // _TODO_LIST_H_
