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

// Overloaded operators
/** Overloaded << operator */
std::ostream &operator<<(std::ostream &strm, const TodoItem &obj)
{
    std::string statusString;
    switch (obj.status_)
    {
    case item::status::INPROGRESS:
        statusString = "inprogress";
        break;

    default:
        statusString = "complete";
        break;
    }
    strm << obj.item_ << " (" << statusString << ")";
    return strm;
}

/** Overloaded == */
bool TodoItem::operator==(const TodoItem &right)
{
    return (status_ == right.status_) &&
           (item_ == right.item_);
}

/** Overloaded != */
bool TodoItem::operator!=(const TodoItem &right)
{
    return !(*this == right);
}
