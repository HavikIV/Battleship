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
	for (vector<Ship>::iterator it = battleships.begin(); it != battleships.end(); it++)
	{
		if (it->isOnSlot(slot))
		{
			it->dealDmg(); // Since the attack was successful, need to deal damage to the ship
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

void Grid::markSlot(pair<int, int> slot, bool success)
{
	grid[slot.first][slot.second] = (success == true) ? 1 : -1; // Hit = 1, Miss = -1
}

bool Grid::isSlotMarked(pair<int, int> slot)
{
	return (grid[slot.first][slot.second] != 0) ? true : false;
}

vector<int> Grid::getShipHPs()
{
	vector<int> hp;
	for (vector<Ship>::iterator it = battleships.begin(); it < battleships.end(); it++)
	{
		hp.push_back(it->getShipHP());
	}
	return hp;
}

bool Grid::isAttackedShipSunk(pair<int, int> slot)
{
	// Find the Ship that is occupying the given slot
	for (vector<Ship>::iterator it = battleships.begin(); it != battleships.end(); it++)
	{
		if (it->isOnSlot(slot))
			return it->isSinking(); // Found the ship so check if it has been sunk with the latest attack
	}

	// Since no Ship was found, return false
	return false; // Though should never reach here
}

vector<vector<pair<int, int>>> Grid::attackData()
{
	vector<vector<pair<int, int>>> p;

	for (vector<vector<int>>::iterator it = grid.begin(); it != grid.end(); it++)
	{
		vector<pair<int, int>> temp;
		for (vector<int>::iterator j = it->begin(); j != it->end(); j++)
		{
			temp.push_back(make_pair((*j == 0) ? 0 : 1, 1));
		}
		p.push_back(temp);
	}

	return p;
}

void Grid::attackData(vector<vector<pair<int, int>>>* data)
{
	vector<vector<pair<int, int>>>::iterator d_it = data->begin();

	for (vector<vector<int>>::iterator it = grid.begin(); it != grid.end(); it++, d_it++)
	{
		vector<pair<int, int>>::iterator i = d_it->begin();
		for (vector<int>::iterator j = it->begin(); j != it->end(); j++, i++)
		{
			i->first += (*j == 1) ? 1 : 0;
			i->second += 1;
		}
	}
}