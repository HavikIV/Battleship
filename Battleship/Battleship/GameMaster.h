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
			while (true)
			{
				if (slotToAttack != "")
				{
					// Request a lock to prevent other threads from modifying the String
					Monitor::Enter(this);

					// Convert the slot into a pair<int, int> object
					int row = slotToAttack[0] - 'A';
					int col;
					if (slotToAttack->Length == 3)
						col = 9;
					else
						col = slotToAttack[1] - '1';
					pair<int, int> attackPair = make_pair(row, col);

					// Attack the point in the grid
					succesfullAttack = playerGrid->attackSlot(attackPair); // Testing by attacking the player own grid

					slotToAttack = "";
					Monitor::Exit(this); // Ensure that the lock is released as we are done
					Thread::Sleep(100);
				}
			}
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

		void setAttack(String^ sta) { slotToAttack = sta; }
		bool getAttackResult() { return succesfullAttack; }
		String^ slotToAttack = "";

	private:
		Label^ output;
		//String^ slotToAttack = "";
		Grid* playerGrid;
		Grid* aiGrid;
		bool succesfullAttack;
};
#endif // !GAMEMASTER_H
