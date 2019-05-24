#include "TodoItem.h"

TodoItem::TodoItem(std::string i, item::status s) : item_(i), status_(s)
{
}

TodoItem::~TodoItem()
{
}

/** Returns the item */
std::string TodoItem::item()
{
    return item_;
}

/** Sets the item */
void TodoItem::item(std::string i)
{
    item_ = i;
}

/** Returns the status of the todo item */
item::status TodoItem::status()
{
    return status_;
}

/** Sets the status of the todo item */
void TodoItem::status(item::status s)
{
    status_ = s;
}
