#include <iostream>
#include <vector>
#include "Cell.h"
#include "Grid.h"

using namespace std;

int main()
{
    Grid grid;

    cout << "Testing the Grid class\n\n";

    cout << "The default number of columns and rows:\n"
         << "---------------------------------------\n";

    cout << "getNumCols(): returns " << grid.getNumCols()
         << "; should return 1\n"
         << "getNumRows(): returns " << grid.getNumRows()
         << "; should return 1\n\n";

    cout << "Resize the grid:\n"
         << "----------------\n";

    cout << "The original grid is 1x1 and looks like\n\n" << grid
         << "\n\nwhen no cells have been visited\n\n";

    grid.resize(3, 3);

    cout << "resize(3, 3):\n" << "getNumCols(): returns " << grid.getNumCols()
         << "; should return 3\n";

    cout << "getNumRows(): returns " << grid.getNumRows()
         << "; should return 3\n\n";

    cout << "The grid is now 3x3 and now looks like\n\n";
    cout << grid << endl;

    grid.resize(15, 5);
    cout << "resize(15, 5):\n" << "getNumCols(): returns " << grid.getNumCols()
         << "; should return 15\n";

    cout << "getNumRows(): returns " << grid.getNumRows()
         << "; should return 5\n\n";

    cout << "The grid is now 15x5 and now looks like\n\n";
    cout << grid << endl << endl;

    cout << "Getting cells within the grid:\n"
         << "------------------------------\n";

    Cell gridCell = grid.getCellAt(2, 3);
    cout << "getCellAt(2, 3):\n"
         << "gridCell.getXPosition(): returns " << gridCell.getXPosition()
         << "; should return 2\n";

    cout << "gridCell.getYPosition(): returns " << gridCell.getYPosition()
         << "; should return 3\n\n";

    cout << "Change the state of some of the grid cells:\n"
         << "-------------------------------------------\n";

    cout << "Set cell at (2, 3) to OCCUPIED\n"
         << "setCell(gridCell)\n\n";

    cout << "The grid should now have an occupied cell at (2, 3)\n\n";

    gridCell = cell::State::OCCUPIED;
    grid.setCell(gridCell);

    cout << "Set cell at (2, 3) to UNOCCUPIED\n"
         << "setCell(gridCell)\n\n";

    cout << "The grid should now have an unoccupied cell at (10, 0)\n\n";
    gridCell.setPosition(10, 0);
    gridCell = cell::State::UNOCCUPIED;
    grid.setCell(gridCell);

    cout << grid << "\n";
}
