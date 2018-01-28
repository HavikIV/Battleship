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
		void setShip(int shipType, vector<pair<int, int>> loc); // Set a ship on the grid
		bool attackSlot(pair<int, int> slot); // Attack the slot and mark it either as a hit or miss
		bool slotOccupied(pair<int, int> slot); // Confirm whether or not the given slot is already occupied
		void markSlot(pair<int, int> slot, bool success); // Mark the slot whether or not the attack on it was a success or not
		bool isSlotMarked(pair<int, int> slot); // Checks to see if the given slot has already been marked by an attach
		vector<int> getShipHPs(); // Returns a vector of the current health levels of the ships
		//vector<vector<int>> grid; // vector that will act as a grid

	private:
		vector<Ship> battleships; // vector of ships on the grid
		vector<vector<int>> grid; // vector that will act as a grid
};
#endif // !GRID_H
