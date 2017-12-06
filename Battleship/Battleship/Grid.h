#pragma once
#ifndef GRID_H
#define GRID_H

// This class will be used to create a 10x10 grids that will represent an ocean
// in which each of the ships in te fleet of battleships will be placed either horizontally
// horizontally in a row or vertically in a column of the grid.

#include <vector>
#include "Ship.h"

using namespace std;

class Grid
{
	public:
		Grid(); // default constructor, creates a 10x10 grid
		void setShip(Ship ship, vector<vector<int, int>> loc); // Set a ship on the grid
		void attackSlot(pair<int, int> slot); // Attack the slot and mark it either as a hit or miss

	private:
		vector<Ship> battleships; // vector of ships on the grid
		vector<vector<int>> grid; // vector that will act as a grid
};
#endif // !GRID_H
