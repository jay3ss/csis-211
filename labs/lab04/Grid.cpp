#include "Grid.h"

void Grid::init()
{
    resize(numCols, numRows);
}

void Grid::resize(int c, int r)
{
    numCols = c;
    numRows = r;
    for (int i = 0; i < numCols; i++)
    {
        std::vector<Cell> row;
        for (int j = 0; j < numRows; j++)
        {
            // Cell cell;
            // row.push_back(cell);
            row.push_back(Cell());
        }
        cells.push_back(row);
    }
}
