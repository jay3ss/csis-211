#include "Cell.h"

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
    case cell::State::START:
        strm << "*";
        break;
    case cell::State::END:
        strm << "x";
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
