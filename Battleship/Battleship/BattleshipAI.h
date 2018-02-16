#pragma once
#ifndef BATTLESHIPAI_H
#define BATTLESHIPAI_H

#include "Grid.h"
#include "GameMaster.h"
#include <stdlib.h> // Need for srand and rand
#include <time.h> // Need for time
#include <fstream> // File IO
#include <msclr\marshal_cppstd.h> // Convert String^ to std::string
#include <algorithm> // Need it for sorting

using namespace std;

public ref class BattleshipAI
{
	public:
		BattleshipAI(GameMaster^ g); // initialize the grid
		void Start();
		void setupGrid(); // setup the grid by placing all of the AI's ships using random selection
		void attack();	// perform an attack using random selection; should only be called when there is no data available
		void exitThread(); // Time to kill the thread so we will change the looping boolean to false so the while loop ends
		void saveAttackData(); // Save the attacks that the AI has made this round to a file, so it can include them in its analysis next round
		void loadAttackData(); // Reads the file containing the attacks made in previous rounds
		void savePlayerAttackData(vector<vector<pair<int, int>>> pData);
		void loadPlayerAttackData(); // Reads the file containing the attacks made by the player in previous rounds
		void smartAttack(); // perform an attack based on the AI's data from previous games
		void smartGridSetup(); // setup the grid by placing all of the AI's ships based on AI's analysis of the Player's attack data from previous games

	private:
		// Properties:
		Grid* grid;
		GameMaster^ gm; // Pointer to an instance of GameMaster that will be provided
		bool keepThreadAlive = true;
		vector<vector<pair<int, int>>>* aiAttackData; // store previous attack data as a 2D vector of pair of integers; number of hits and total number of games
		vector<vector<pair<int, int>>>* pAttackData; // store previous player attack data as a 2D vector of pair of integers; number of hits and total number of games
		vector<pair<int, int>>* slotList;

		// Private helper functions:
		bool anyOverlaps(vector<pair<int, int>> slots); // Check to see if there will be an overlap when trying to place a ship at the given point
		vector<pair<int, int>> findSlots(bool orientation, int shipType, pair<int, int> p); // Finds the slots that the ship of the given type will occupy based on the given point on the grid
		vector<pair<int, int>> getSlotlist(); // Returns a vector of integer pairs representing slot locations in order of most hits to least hits
		pair<int, int> getSlotInQuadrant(int Quadrant); // This helper function will search within the given quadrant to find the first slot with the least chance of being attacked by the player
		float getOverallPercentage(vector<pair<int, int>> possiblePlacement); // This helper function will calculate the overall percentage of being attacked by averaging the hit chances
		bool slotWithinPlacement(vector<pair<int, int>> placement, pair<int, int> slot); // This helper function will check whether or not the given slot is within the given placement
};

#endif // !BATTLESHIPAI_H

