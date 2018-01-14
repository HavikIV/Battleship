#include "Grid.h"
#include "Ship.h"
#include <vector>

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
void Grid::setShip(int shipType, vector<pair<int, int>> loc)
{
	battleships[shipType - 1].setLocation(loc);
}

// Perform an attack on the selected slot
bool Grid::attackSlot(pair<int, int> slot)
{
	// Check if any of the battleships are occupying the selected slot
	for each (Ship s in battleships)
	{
		if (s.isOnSlot(slot))
		{
			return true;
		}
	}

	return false;
}

// Confirm whether or not given slot on grid is occupied by a ship already by iterating through the vector of ships.
bool Grid::slotOccupied(pair<int, int> slot)
{
	for each (Ship ship in battleships)
	{
		if (ship.isOnSlot(slot))
		{
			return true;
		}
	}
	return false;
}
