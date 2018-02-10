#pragma once
#ifndef BATTLESHIPAI_H
#define BATTLESHIPAI_H

#include "Grid.h"
#include "GameMaster.h"
#include <stdlib.h> // Need for srand and rand
#include <time.h> // Need for time
#include <fstream> // File IO
#include <msclr\marshal_cppstd.h> // Convert String^ to std::string

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
		void loadPlayerAttackData(); // Reads the file containing the attacks made by the player in previous rounds
		void smartAttack(); // perform an attack based on the AI's data from previous games
		void smartGridSetup(); // setup the grid by placing all of the AI's ships based on AI's analysis of the Player's attack data from previous games

	private:
		Grid* grid;
		GameMaster^ gm; // Pointer to an instance of GameMaster that will be provided
		bool anyOverlaps(vector<pair<int, int>> slots); // Check to see if there will be an overlap when trying to place a ship at the given point
		vector<pair<int, int>> findSlots(bool orientation, int shipType, pair<int, int> p); // Finds the slots that the ship of the given type will occupy based on the given point on the grid
		bool keepThreadAlive = true;
		vector<vector<pair<int, int>>>* aiAttackData; // store previous attack data as a 2D vector of pair of integers; number of hits and total number of games
		vector<vector<pair<int, int>>>* pAttackData; // store previous player attack data as a 2D vector of pair of integers; number of hits and total number of games
};

#endif // !BATTLESHIPAI_H

