#include "Cell.h"

// Initializes every cell with the UNVISITED state
void Cell::initializeNeighbors()
{
    for (auto &n: neighbors)
    {
        n = cell::State::UNVISITED;
    }
}

// Set the neighboring cells
void Cell::setNeighbors(std::array<cell::State, 4> n)
{
    neighbors = n;
}

// Overloaded ostream operator
std::ostream &operator<<(std::ostream &strm, const Cell &obj)
{
    switch (obj.state)
    {
    case cell::OCCUPIED:
        strm << "OCCUPIED";
        break;
    case cell::UNOCCUPIED:
        strm << "UNOCCUPIED";
        break;
    case cell::UNVISITED:
        strm << "UNVISITED";
        break;
    default:
        strm << "NONE";
        break;
    }

    return strm;
}
