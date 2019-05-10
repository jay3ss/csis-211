#include <array>
#include <iostream>
#include <string>
#include "Cell.h"

using namespace std;

bool allUnoccupied(array<cell::State, 4>&);
string cellStateToString(cell::State s);

int main()
{
    Cell cell;

    cout << "Testing the Cell class\n\n";

    cout << "The cell's default state should be UNVISITED:\n"
         << "---------------------------------------------\n";

    cout << "getState(): returns " << cellStateToString(cell.getState())
         << "; should return "
         << cellStateToString(cell::State::UNVISITED) << "\n\n";

    // cout << "The cell's neighbors should all have a state of UNVISITED:\n"
    //      << "----------------------------------------------------------\n";

    // array<cell::State, 4> nStates = cell.getNeighbors();

    // cout << "allUnoccupied(nStates): returns " << allUnoccupied(nStates)
    //      << "; should return 1 (true)\n\n";

    cout << "The cell's default position should be (0, 0):\n"
         << "-------------------------------------\n";

    cout << "getXPosition(): returns " << cell.getXPosition()
         << "; should return 0\n";

    cout << "getYPosition(): returns " << cell.getYPosition()
         << "; should return 0\n\n";

    // cout << "Set the neighboring cells:\n"
    //      << "--------------------------\n";

    // array<cell::State, 4> nCells = {
    //     cell::State::UNVISITED,
    //     cell::State::UNOCCUPIED,
    //     cell::State::OCCUPIED,
    //     cell::State::NONE
    // };

    // cell.setNeighbors(nCells);

    // array<cell::State, 4> neighbors = cell.getNeighbors();

    // cout << "The neighboring cells are:\n";

    // for (auto &n: neighbors)
    // {
    //     cout << "- " << cellStateToString(n) << endl;
    // }

    // cout << endl;

    // cout << "The neighboring cells should be:\n";

    // for (auto &n : nCells)
    // {
    //     cout << "- " << cellStateToString(n) << endl;
    // }
}

bool allUnoccupied(array<cell::State, 4> &nStates)
{
    for (auto &n : nStates)
    {
        if (n != cell::State::UNVISITED)
        {
            return false;
        }
    }

    return true;
}

string cellStateToString(cell::State s)
{
    string str;
    switch (s)
    {
    case cell::State::OCCUPIED:
        str = "OCCUPIED";
        break;
    case cell::State::UNOCCUPIED:
        str = "UNOCCUPIED";
        break;
    case cell::State::UNVISITED:
        str = "UNVISITED";
        break;
    default:
        str = "NONE";
        break;
    }

    return str;
}
