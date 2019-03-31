#include <iostream>
#include <string>

using namespace std;

// Function prototype
void writeBack(string);

int main()
{
    string input;

    cout << "Enter a string to write backwards: ";
    getline(cin, input);

    // cout << input.substr(1, input.size() - 1);
    writeBack(input);

    return 0;
}

void writeBack(string str)
{
    // cout << str << endl;
    int length = str.size();
    if (length == 0)
    {
        return;
    }
    else
    {
        // Write the last character
        cout << str.substr(0, 1);

        // Write the rest of the string backward
        writeBack(str.substr(1, length - 1));
    }
}