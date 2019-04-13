#include <iostream>
#include <string>

bool isLang(std::string str);

int main()
{
    std::string testStr = "DCA";

    std::cout << testStr << " is a part of the language? " << isLang(testStr);
    return 0;
}

bool isLang(std::string str)
{
    if (str.length() == 0)
    {
        return false;
    }
    else if (str == "A" || str == "B")
    {

    }
    else if (str[0] == 'A' || str[0] == 'B' || str[0] == 'C' || str[0] == 'D')
    {
        if (str[0] > str[str.length() - 1])
        {

            return isLang(str.substr(1, str.length() - 1));
        }
    }
    else
    {
        return false;
    }
    
}