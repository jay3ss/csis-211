#include "Grid.h"

// Returns a cell at a given position in the grid. If the given position is out
// the bounds of the grid (either: x < 0, x > numCols or y < 0, y > numRows)
// then a cell with the state of NONE is returned
Cell Grid::getCellAt(int x, int y)
{
    if (isOutOfBounds(x, y))
    {
	    Cell c;
        c.setState(cell::State::NONE);
		c.setPosition(x, y);

        return c;
    }

    return cells[x][y];
}

// Checks if a cell is out of bounds
bool Grid::isOutOfBounds(int x, int y)
{
    return (x < 0 || x > numCols || y < 0 || y > numRows);
}

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
    cells[c.getXPosition()][c.getYPosition()] = c;
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
