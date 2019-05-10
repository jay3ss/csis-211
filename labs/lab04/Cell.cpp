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
        strm << "#";
        break;
    case cell::UNOCCUPIED:
        strm << " ";
        break;
    case cell::UNVISITED:
        strm << "?";
        break;
    default:
        strm << "";
        break;
    }

    return strm;
}
