#include "Grid.h"

Grid::Grid()
{
	grid.resize(10, vector<int>(10)); // Make a 10x10 grid
	// Lets create ships that will be added to the grid either by the A.I. or the player
	for (int i = 1; i <= 5; i++)
	{
		Ship ship = Ship(i); // create the ship
		battleships.push_back(ship); // Add the created ship to the vector of battleships
	}
}

// Set the ship's location on the grid
void Grid::setShip(Ship ship, vector<vector<int, int>> loc)
{
	ship.setLocation(loc);
}

// Perform an attack on the selected slot
void Grid::attackSlot(pair<int, int> slot)
{
	// Check if any of the battleships are occupying the selected slot

	// Display a hit if a ship is found, else display a miss
}
