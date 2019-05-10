#ifndef _CELL_H
#define _CELL_H

#include <array>
#include <iostream>

namespace cell
{
    enum class State { UNVISITED, OCCUPIED, UNOCCUPIED, NONE };
}

class Cell
{
public:
    // Constructor
    Cell(cell::State s = cell::State::UNVISITED, int x = 0, int y = 0) :
        state(s), xPosition(0), yPosition(0) {}
        // { initializeNeighbors(); }

    // Accessors
    int getXPosition() const { return xPosition; }
    int getYPosition() const { return yPosition; }
    cell::State getState() const { return state; }
    // std::array <cell::State, 4> getNeighbors() const { return neighbors; }

    // Mutators
    void setPosition(int x, int y) { xPosition = x; yPosition = y; }
    void setState(const cell::State s) { state = s; }
    // void setNeighbors(const std::array<cell::State, 4> n);

    friend std::ostream &operator<<(std::ostream &strm, const Cell &obj);

private:
    // static const int NUM_NEIGHBORS = 4;
    int xPosition;
    int yPosition;
    cell::State state;
    // std::array<cell::State, 4> neighbors;

    // void initializeNeighbors();
};

#endif // _CELL_H
