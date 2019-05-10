#include <iostream>
#include <vector>
#include "Cell.h"
#include "Grid.h"

using namespace std;

int main()
{
    Grid grid(3, 3);

    cout << "Testing the Grid class\n\n";

    cout << "The default number of columns and rows:\n"
         << "---------------------------------------\n";

    cout << "getNumCols(): returns " << grid.getNumCols()
         << "; should return 1\n"
         << "getNumRows(): returns " << grid.getNumRows()
         << "; should return 1\n\n";

    std::vector<std::vector<Cell>> cells = grid.vector();

    cout << grid;

    grid.resize(15, 15);

    cout << grid;
}
