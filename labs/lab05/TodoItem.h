#ifndef _TODO_ITEM_H_
#define _TODO_ITEM_H_

namespace item
{
    enum class status { COMPLETE, INPROGRESS };
}

class TodoItem
{
private:
    item::status status_;
public:
    TodoItem();
    ~TodoItem();
};

#endif // _TODO_ITEM_H_
