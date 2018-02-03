#pragma once
#ifndef GAMEMASTER_H
#define GAMEMASTER_H

// This class is to create a game master that will be act as the judge/referee that will handle
// doing all of the work determining whether an attack is a miss or hit and also be in charge of
// updating the GUI to reflect the current state of the game.

#include <vector>
#include <Windows.h>

using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Threading;

public ref class GameMaster
{
	public:
		GameMaster() { playerGrid = new Grid(); aiGrid = new Grid(); }
		void Start()
		{
			while (keepThreadAlive)
			{
				if (timeToProcessAttacks())
				{
					// Request a lock to prevent other threads from modifying the String
					Monitor::Enter(this);

					// Convert the attack strings into a pair<int, int> objects
					pair<int, int> pAttackPair = convertAttackString(pSlotToAttack); // The slot that the player is attacking on the AI's grid
					pair<int, int> aiAttackPair = convertAttackString(aiSlotToAttack); // The sot that the AI is attacking on the player's grid

					if (pAttackPair.first < 0 || pAttackPair.first > 9 || pAttackPair.second < 0 || pAttackPair.second > 9)
					{
						// out of range
						sendToPlayer = "Player's attack is out range";
					}
					else if (aiAttackPair.first < 0 || aiAttackPair.first > 9 || aiAttackPair.second < 0 || aiAttackPair.second > 9)
					{
						// Ai's attack is out range
						sendToPlayer = "AI's attack is out of range";
					}

					// Process the player's attack on the AI's grid
					pSuccessfulAttack = aiGrid->attackSlot(pAttackPair);
					playerGrid->markSlot(pAttackPair, pSuccessfulAttack);
					// Only need to process the AI's attack if the player didn't win the ship it's attack just now
					int healthSum = 0;

					for each (int i in healthLevels(false))
					{
						healthSum += i;
					}
					if (healthSum != 0)
					{
						// Process the AI's attack on the player's grid
						aiSuccessfulAttack = playerGrid->attackSlot(aiAttackPair);
						aiGrid->markSlot(aiAttackPair, aiSuccessfulAttack);
					}
					//toggleTurn(); // Toggle the turn

					// Now that the attacks have been processed, we need to clear out the attack strings so that the players can perform another attack
					sendToPlayer = aiSlotToAttack + "-> " + aiSuccessfulAttack; // Save the AI's attack so we can inform the player of it
					pSlotToAttack = "";
					aiSlotToAttack = "";
					Monitor::Exit(this); // Ensure that the lock is released as we are done
					Thread::Sleep(500);
				}
			}
		}
		// This method takes an attack string and converts it into a pair value
		pair<int, int> convertAttackString(String^ attack)
		{
			int row = attack[0] - 'A';
			int col;
			if (attack->Length == 3)
				col = 9;
			else
				col = attack[1] - '1';
			return make_pair(row, col);
		}
		void setPlayerGrid(Grid* grid) { playerGrid = grid; }
		void setAIGrid(Grid* grid) { aiGrid = grid; }
		void updateShip(bool player, int shipType, vector<pair<int, int>> loc)
		{
			if (player)
			{
				playerGrid->setShip(shipType, loc);
			}
			else
				aiGrid->setShip(shipType, loc);
		}

		void setAttack(bool hPlayer, String^ sta) { if (hPlayer) pSlotToAttack = sta; else aiSlotToAttack = sta; }
		bool getAttackResult(bool hPlayer) { return hPlayer ? pSuccessfulAttack :  aiSuccessfulAttack; }
		bool timeToProcessAttacks() { return (pSlotToAttack != "" && aiSlotToAttack != ""); } // Returns true when both the player and the AI have announced an attack so that GameMaster can start to process them
		//void toggleTurn() { isAIsTurn = !isAIsTurn;  } // Toggle the turn
		//bool AIsTurn() { return isAIsTurn; }
		bool attackInProgress(bool hPlayer) { return hPlayer ? (pSlotToAttack != "") : (aiSlotToAttack != ""); } // Check to see if there's already an attack being executed
		bool isShipSunking(pair<int, int> slot) { return playerGrid->isAttackedShipSunk(slot); } // Lets the AI know if it sunk the ship it is attacking
		//void playerIsAttacking() { playersAttack = !playersAttack; } // Give's the player the ability to inform the GameMaster that its attacking now
		vector<int> healthLevels(bool hPlayer) // returns the current health levels of ships of the requested player; T = Human, F = AI
		{
			if (hPlayer)
				return playerGrid->getShipHPs();
			return aiGrid->getShipHPs();
		}
		String^ informPlayer() { return sendToPlayer; };
		void exitThread() { keepThreadAlive = false; } // Time to kill the thread so we will change the loop boolean to false so the while loop ends

	private:
		//Label^ output;
		String^ pSlotToAttack = "";
		String^ aiSlotToAttack = "";
		String^ sendToPlayer = "";
		Grid* playerGrid;
		Grid* aiGrid;
		bool pSuccessfulAttack;
		bool aiSuccessfulAttack;
		bool keepThreadAlive = true;
		//bool isAIsTurn = false;
		//bool playersAttack = false;
};
#endif // !GAMEMASTER_H
