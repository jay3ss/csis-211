#include "Cell.h"

// Initializes every cell with the UNVISITED state
// void Cell::initializeNeighbors()
// {
//     for (auto &n: neighbors)
//     {
//         n = cell::State::UNVISITED;
//     }
// }

// Set the neighboring cells
// void Cell::setNeighbors(std::array<cell::State, 4> n)
// {
//     neighbors = n;
// }

// Overloaded ostream operator
std::ostream &operator<<(std::ostream &strm, const Cell &obj)
{
    switch (obj.state)
    {
    case cell::State::OCCUPIED:
        strm << "#";
        break;
    case cell::State::UNOCCUPIED:
        strm << " ";
        break;
    case cell::State::UNVISITED:
        strm << "?";
        break;
    default:
        strm << "";
        break;
    }

    return strm;
}

// Overloaded '=' operator
void Cell::operator=(const Cell &right)
{
    state = right.state;
}
