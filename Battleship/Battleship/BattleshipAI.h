#pragma once
#ifndef BATTLESHIPAI_H
#define BATTLESHIPAI_H

#include "Grid.h"
#include "GameMaster.h"
#include <stdlib.h> // Need for srand and rand
#include <time.h> // Need for time

using namespace std;

public ref class BattleshipAI
{
	public:
		BattleshipAI(GameMaster^ g); // initialize the grid
		void Start();
		void setupGrid(); // setup the grid by placing all of the AI's ships based on its data from previous games
		void attack();	// perform an attack based on it's data from previous games
		void exitThread(); // Time to kill the thread so we will change the looping boolean to false so the while loop ends

	private:
		Grid* grid;
		GameMaster^ gm; // Pointer to an instance of GameMaster that will be provided
		bool anyOverlaps(vector<pair<int, int>> slots); // Check to see if there will be an overlap when trying to place a ship at the given point
		vector<pair<int, int>> findSlots(bool orientation, int shipType, pair<int, int> p); // Finds the slots that the ship of the given type will occupy based on the given point on the grid
		bool keepThreadAlive = true;
};

#endif // !BATTLESHIPAI_H

