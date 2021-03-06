#ifndef _TODO_ITEM_H_
#define _TODO_ITEM_H_

#include <iostream>
#include <string>

namespace item
{
    enum class status { COMPLETE, INPROGRESS };
}

class TodoItem
{
private:
    std::string item_;      // Text of what to do
    item::status status_;   // Current status of the time
public:
    /** Constructor */
    TodoItem(std::string i = "", item::status = item::status::INPROGRESS);

    /** Destructor */
    ~TodoItem();

    /** Returns the item
    @return The item */
    std::string item();

    /** Sets the item
    @post The item will be set to the value passed in
    @param i The new item */
    void item(std::string i);

    /** Returns the status of the todo item
    @return The status of the item */
    item::status status();

    /** Sets the status of the todo item
    @param s The new status of the item */
    void status(item::status s);

    // Overloaded operators
    /** Overloaded << operator
    @param strm ostream object
    @obj TodoItem object to be inserted
    @return ostream object */
    friend std::ostream &operator<<(std::ostream &strm, const TodoItem &obj);

    /** Overloaded == operator*/
    bool operator==(const TodoItem &right) const;

    /** Overloaded != operator*/
    bool operator!=(const TodoItem &right) const;
};

#endif // _TODO_ITEM_H_
