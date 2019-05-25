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
    strm << obj.item_ << " (" << item::statusToString(obj.status_) << ")";
    return strm;
}

/** Overloaded == */
bool TodoItem::operator==(const TodoItem &right)
{
    return (status_ == right.status_) &&
           (item_ == right.item_);
}

namespace item
{
    std::string statusToString(item::status status)
    {
        std::string statusString;
        switch (status)
        {
        case item::status::INPROGRESS:
            statusString = "inprogress";
            break;

        default:
            statusString = "complete";
            break;
        }

        return statusString;
    }
}

/** Overloaded != */
bool TodoItem::operator!=(const TodoItem &right)
{
    return !(*this == right);
}
