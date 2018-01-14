#include "Ship.h"
#include <vector>

// Default constructor which will create a destroyer with health and size of 2
Ship::Ship()
{
	health = 2;
	size = 2;
}

// Custom constructor which will create a ship with the provided shipType # ( 1 = carrier, 2 = battleship, 3 = cruiser, 4 = submarine, 5 = destroyer)
Ship::Ship(int shipType)
{
	switch (shipType)
	{
	case 1: // Carrier
		health = 5;
		break;
	case 2: // Battleship
		health = 4;
		break;
	case 3: // Cruiser
	case 4: // Submarine
		health = 3;
		break;
	default: // Destroyer
		health = 2;
		break;
	}
	size = health;
}

// Since the ship has been hit, need to decrement it's health by one
void Ship::dealDmg()
{
	health--; // decrement health by 1
}

// Check to see if the ship has been sunk from the attack
bool Ship::isSunking()
{
	dealDmg(); // The ship has been hit, deal the damage
	if (health == 0)
		return true; // Since the ship's health is 0, it has been sunk
	return false;
}

// Set the ships location on the grid
void Ship::setLocation(vector<pair<int, int>> loc)
{
	location = loc;
}

// Return the ship's location
vector<pair<int, int>> Ship::getLocation()
{
	return location;
}

bool Ship::isOnSlot(pair<int, int> p)
{
	// Iterate through the vector to see if any of the pairs match to the given pair
	for each (pair<int, int> x in location)
	{
		if (x == p)
		{
			dealDmg();
			return true;
		}
	}

	return false;
}

int Ship::getShipSize()
{
	return size;
}
