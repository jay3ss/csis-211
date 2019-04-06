#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isId(string s);
bool isLetter(string s);
bool isLetter(char c);


int main()
{
    string strToCheck;
    getline(cin, strToCheck);
    
    // Check if is a valid letter
    string validLetter = strToCheck + " is a valid C++ letter";
    string notValidLetter = strToCheck + " is not a valid C++ letter";

    cout << (isLetter(strToCheck) ? validLetter : notValidLetter) << "\n";

    // Check if is a valid identifier
    string validId = strToCheck + " is a valid C++ identifier";
    string notValidId = strToCheck + " is not a valid C++ identifier";

    cout << (isId(strToCheck) ? validId : notValidId);

    return 0;
}


bool isId(string s)
{
    if(s.length() == 1)
    {
        return isLetter(s);
    }
    // Check the last character
    else if (s.back() || isdigit(s.back()))
    {
        return isId(s.substr(0, s.length() - 1));
    }
}

bool isLetter(string s)
{
    return isalpha(s[0]) || s == "_";
}

bool isLetter(char c)
{
    return isalpha(c) || c == '_';
}