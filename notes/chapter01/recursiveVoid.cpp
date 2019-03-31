#include <iostream>
#include <string>

using namespace std;

// Function prototype
void writeBackward(string);

int main()
{
    string input;

    cout << "Enter a string to write backwards: ";
    getline(cin, input);

    writeBackward(input);

    return 0;
}

void writeBackward(string str)
{
    // cout << str << endl;
    int length = str.size();
    if (length > 0)
    {
        // Write the last character
        cout << str.substr(length - 1, 1);

        // Write the rest of the string backward
        writeBackward(str.substr(0, length - 1));
    }
}