#include <iostream>
#include <string>
#include "TodoItem.h"
#include "TodoList.h"

using namespace std;

int main()
{
    TodoList todo;

    cout << "Welcome to the Todo List App\n\n"
         << "The list is currently empty. "
         << "How many items would you like to add? ";

    int numItemsToAdd;
    cin >> numItemsToAdd;
    cin.ignore();

    TodoItem item;
    item::status status;
    string str;
    int choice;
    for (int position = 1; position <= numItemsToAdd; position++)
    {
        cout << "\n\nWhat is the item? ";
        getline(cin, str);
        item.item(str);
        cout << "What is the item's status?\n1. Inprogress\n2. Complete\n\n";
        cin >> choice;
        cin.ignore();

        // Default is INPROGRESS
        if (choice == 2)
        {
            item.status(item::status::COMPLETE);
        }
        todo.add(item);
    }

    cout << endl << todo;
}
