#include <iostream>

using namespace std;

// Function prototype
void solveTowers(int, char, char, char);

int main()
{
    char source = 'A';
    char destination = 'B';
    char spare = 'C';

    int count;

    cout << "How many disks would you like to solve for? ";
    cin >> count;
    cin.ignore();
    cout << endl;

    solveTowers(count, source, destination, spare);
    return 0;
}

void solveTowers(int count, char source, char destination, char spare)
{
    if (count == 1)
    {
        cout << "Move top disk from pole " << source
             << " to pole " << destination << endl;
    }
    else
    {
        solveTowers(count - 1, source, spare, destination);
        solveTowers(1, source, destination, spare);
        solveTowers(count - 1, spare, destination, source);
    }
}