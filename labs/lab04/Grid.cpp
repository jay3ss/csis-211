#include "Grid.h"

void Grid::init()
{
    resize(numCols, numRows);
}

void Grid::resize(int c, int r)
{
    numCols = c;
    numRows = r;

    std::vector<std::vector<Cell>> newCellsVect;
    for (int i = 0; i < numCols; i++)
    {
        std::vector<Cell> row;
        for (int j = 0; j < numRows; j++)
        {
            Cell cell;
            cell.setPosition(i, j);
            row.push_back(cell);
        }
        newCellsVect.push_back(row);
    }
    cells = newCellsVect;
}

void Grid::setCell(Cell c)
{
    cells[c.getXPosition()][c.getYPosition()] = c.getState();
}

std::ostream &operator<<(std::ostream &strm, const Grid &obj)
{
    for (int i = 0; i < obj.numRows; i++)
    {
        for (int j = 0; j < obj.numCols; j++)
        {
            strm << obj.cells[j][i];
        }
        strm << std::endl;
    }

    return strm;
}
