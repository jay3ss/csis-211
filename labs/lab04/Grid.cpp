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
            Cell cell;
            cell.setPosition(i, j);
            row.push_back(cell);
        }
        cells.push_back(row);
    }
}

std::ostream &operator<<(std::ostream &strm, const Grid &obj)
{
    for (auto &row : obj.vector())
    {
        for (auto &cell : row)
        {
            std::cout << cell;
        }
        std::cout << std::endl;
    }
}
