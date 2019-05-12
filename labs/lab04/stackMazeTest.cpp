#include <iostream>
#include "Grid.h"
#include "Maze.h"

using namespace std;

char stateToChar(cell::State state);

int main()
{
    // Maze maze(3, 3);
    Maze maze(42, 37);

    Grid grid = maze.getGrid();
    cout << "The maze is\n\n";

    cout << maze << "\n\n";

    maze.setStart(3, 5);
    maze.setEnd(39, 22);

    // const int *start = maze.getStart();
    // const int *end = maze.getEnd();
    Cell startCell = maze.getStart();
    Cell endCell = maze.getEnd();

    cout << "Starting coordinate is (" << startCell.getXPosition() << ", " << startCell.getYPosition() << ")\n";
    cout << "Ending coordinate is (" << endCell.getXPosition() << ", " << endCell.getYPosition() << ")\n\n";

    // Grid grid = maze.getGrid();
    grid = maze.getGrid();
    // Cell c = grid.getCellAt(start[0], start[1]);

    cout << "Now the maze looks like\n\n" << maze << endl;

    cout << "Test creating a maze with a random start and end point:\n"
         << "-------------------------------------------------------\n\n";

    Maze randMaze(10, 15, true);

    cout << randMaze << endl;

    cout << "Generated using the seed " << maze.getSeed() << "\n\n";

    cout << "Get a random neighbor:\n"
         << "----------------------\n\n";

    // const int* randStart = randMaze.getStart();
    Cell randStart = randMaze.getStart();
    // Cell randStartCell = randMaze.getCellAt(randStart[0], randStart[1]);
    Cell randNeighborCell = randMaze.getRandomNeighbor(randStart);
    // Cell randNeighborCell = randMaze.getRandomNeighbor(randStartCell);

    cout << "Get random neighbor of starting cell at ("
         << randStart.getXPosition() << ", " << randStart.getYPosition() << ")\n";

    cout << "randMaze.getRandomNeighbor(randStartCell):\n"
         << "Neighbor's coordinates are ("
         << randNeighborCell.getXPosition() << ", "
         << randNeighborCell.getYPosition() << ")\n\n";

    cell::State randState = randMaze.getRandomState();

    cout << "Getting a random state: " << stateToChar(randState) << endl;

    cout << "Generate a maze:\n"
         << "----------------\n\n";

    Maze newMaze(15, 15, true);

    newMaze.generate();

    cout << "Here's the newly generated maze" << "\n\n"
         << newMaze;
}


char stateToChar(cell::State state)
{
    char c;
    switch (state)
    {
    case cell::State::OCCUPIED:
        c = '#';
        break;
    default:
        c = ' ';
        break;
    }
    return c;
}
