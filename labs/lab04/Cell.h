#ifndef _CELL_H
#define _CELL_H

#include <array>
#include <iostream>

namespace cell
{
    enum class State { UNVISITED, OCCUPIED, UNOCCUPIED, NONE, START, END };
}

class Cell
{
public:
    // Constructor
    Cell(cell::State s = cell::State::UNVISITED, int x = 0, int y = 0) :
        state(s), xPosition(0), yPosition(0) {}

    // Accessors
    int getXPosition() const { return xPosition; }
    int getYPosition() const { return yPosition; }
    cell::State getState() const { return state; }

    // Check state of cell
    bool isEndd() const { return state == cell::State::END; }
    bool isNone() const { return state == cell::State::NONE; }
    bool isOccupied() const { return state == cell::State::OCCUPIED; }
    bool isStart() const { return state == cell::State::START; }
    bool isUnoccupied() const { return state == cell::State::UNOCCUPIED; }
    bool isUnvisited() const { return state == cell::State::UNVISITED; }

    // Mutators
    void setPosition(int x, int y) { xPosition = x; yPosition = y; }
    void setState(const cell::State s) { state = s; }

    // Overloaded operators
    void operator=(const Cell &right);
    friend std::ostream &operator<<(std::ostream &strm, const Cell &obj);

private:
    int xPosition;
    int yPosition;
    cell::State state;
};

#endif // _CELL_H
