#include "BattleshipAI.h"

// This constructor takes in a pointer to an instance of GameMaster and it will also create a new Grid
// the AI will populate with its own ships.
BattleshipAI::BattleshipAI(GameMaster^ g)
{
	gm = g;
	grid = new Grid();
	aiAttackData = new vector<vector<pair<int, int>>>();
}

void BattleshipAI::Start()
{
	loadAttackData(); // load attack data if it exists
	setupGrid(); // Setup the AI's grid

	while (keepThreadAlive)
	{
		if (!gm->attackInProgress(false))
		{
			attack();
		}
	}
}

void BattleshipAI::setupGrid()
{
	int row, col;
	int shipType = 1;

	// Lets setup the grid by using rand to select random slots and orientation of ships
	srand(time(NULL)); // Seed the rand with the current time

	// Let's place all of the ships randomly on the grid
	while (shipType != 6)
	{
		// Generate random numbers between 0 and 9 for the row and column of the random slot
		row = rand() % 10;
		col = rand() % 10;
		// Make a pair with the random numbers
		pair<int, int> slot = make_pair(row, col);

		// Get a vector of integer pairs of where the ship goes
		vector<pair<int, int>> slots = findSlots(rand() % 2, shipType, slot);
		if (!anyOverlaps(slots))
		{
			gm->updateShip(false, shipType, slots); // Set the ship on the AI's grid that the GameMaster keeps track of
			grid->setShip(shipType, slots); // Update the AI's grid so it knows where it's own ships are
			shipType++; // Increment the shipType so that we can place the next ship on the grid
			Thread::Sleep(500); // Need to let the thread sleep so that the AI doesn't rapidly call rand()
		}
		gm->setAIGrid(grid);
		Thread::Sleep(500);
	}
}

void BattleshipAI::attack()
{
	// Request a lock to prevent other thread from doing anything
	Monitor::Enter(gm);

	// Use rand to generate attack on a random point on the player's grid
	srand(time(NULL)); // Seed the rand with the current time
	pair<int, int> slotToAttack = make_pair(rand() % 10, rand() % 10);
	while (grid->isSlotMarked(slotToAttack))
	{
		// Since the slot was previously attacked, let's pick a different slot to attack
		slotToAttack = make_pair(rand() % 10, rand() % 10);
	}

	// Convert the point to a String so we can pass it to GameMaster
	String^ s = "" + (Char)('A' + slotToAttack.first) + (Char)('1' + slotToAttack.second);
	if (slotToAttack.second == 9)
		s = s[0] + "10";


	// Attack the point
	gm->setAttack(false, s);

	// Release the lock
	Monitor::Exit(gm);

	// This thread should sleep until the attacks have been processed
	while (gm->attackInProgress(false))
	{
		Thread::Sleep(100);
	}
	//Thread::Sleep(1500);
	
	Monitor::Enter(gm);
	if (gm->getAttackResult(false))
	{
		// Need to attack the adjacent slots during the following turns until the ship has been sunk
		pair<int, int> startingPoint = slotToAttack; // Copy of the slot that was successfully attacked
		bool attackHorizontally = true;
		//bool attackVertically = false;
		bool attackRightSide = true;
		bool attackAbove = true;
		bool keepLooping = !gm->isShipSinking(startingPoint);

		Monitor::Exit(gm); // Release the lock that was acquired outside the if statement

		while (keepLooping && keepThreadAlive)
		{
			// Let's start attacking slots that are horizontally adjacent to the starting point; Start by attacking to the right
			if (attackHorizontally)
			{
				// check if we can move to the right
				if (slotToAttack.second < 9 && attackRightSide)
				{
					slotToAttack.second += 1; // Move one column to the right
				}
				else
				{
					// Move in the opposite direction from the starting point
					if (slotToAttack.second > startingPoint.second)
					{
						slotToAttack.second = startingPoint.second; // So we don't attack the startingPoint again
					}
					slotToAttack.second -= 1; // Move one column to the left
					attackRightSide = false;
				}
			}
			else
			{
				// Time to attack slots that are vertically adjacent to the startingPoint
				if (slotToAttack.second != startingPoint.second)
					slotToAttack.second = startingPoint.second; // Make sure that we are attacking slots in the right column

				if (attackAbove && slotToAttack.first > 0)
				{
					slotToAttack.first -= 1; // Move up a row
				}
				else
				{
					if (slotToAttack.first < startingPoint.first)
					{
						slotToAttack.first = startingPoint.first; // Making sure that we don't end up attacking the starting point multiple times
					}
					slotToAttack.first += 1; // Move down a row
					attackAbove = false;
				}
			}

			Monitor::Enter(gm); // Request a lock before informing the GameMaster what slot to attack for the AI
			
			s = "" + (Char)('A' + slotToAttack.first) + (Char)('1' + slotToAttack.second);
			if (slotToAttack.second == 9)
				s = s[0] + "10";
			gm->setAttack(false, s);

			Monitor::Exit(gm); // Release the lock

			//Thread::Sleep(1500); // Give the GameMaster enough time to process the attack before checking the result
			while (gm->attackInProgress(false) && keepThreadAlive)
			{
			Thread::Sleep(100);
			}
			Monitor::Enter(gm); // Request a lock so the AI can check the result
			
			if (attackHorizontally)
			{
				if (attackRightSide)
				{
					attackRightSide = gm->getAttackResult(false);
					attackHorizontally = (startingPoint.second == 0) ? false : true; // If the starting point is in the first column, we can't go any further to the left
				}
				else
				{
					attackHorizontally = gm->getAttackResult(false);
					//attackVertically = !attackHorizontally;
				}

			}
			else
			{
				if (attackAbove)
					attackAbove = gm->getAttackResult(false);
			}

			// Update the looping condition before the lock is released
			keepLooping = !gm->isShipSinking(startingPoint);
			Monitor::Exit(gm); // Release the lock

			//Thread::Sleep(500);
		}
		Thread::Sleep(50);
	}
	else
		Monitor::Exit(gm);
}

void BattleshipAI::exitThread()
{
	keepThreadAlive = false;
}

// This function takes in a vector of integer pairs that represent slots on the grid that will be occupied by a ship.
// It will check to see if any of the slots in the given vector are previously occupied or not. By default the function
// will return false and it only returns true if any of the given slots is occupied.
bool BattleshipAI::anyOverlaps(vector<pair<int, int>> slots)
{
	// Iterate through the vector to check if the given slot are already occupied
	for each (pair<int, int> slot in slots)
	{
		if (grid->slotOccupied(slot))
		{
			return true;
		}
	}
	return false;
}

// This function takes in the type of ship that is being placed, the point on the grid that is going to be occupied, and boolean to determine the orientation.
// By default the orientation is going to be horizontal unless false is passed to the function. With the given 3 inputs the function will find the adjacent
// points to the given point that will also be occupied by the given ship type and it will return the points as vector of integer pairs.
vector<pair<int, int>> BattleshipAI::findSlots(bool orientation, int shipType, pair<int, int> p)
{
	int shipSize;
	if (shipType == 1)
		shipSize = 5;
	else if (shipType == 2)
		shipSize = 4;
	else if (shipType == 3 || shipType == 4)
		shipSize = 3;
	else
		shipSize = 2;

	int noOfPointsToFind = shipSize - 1; // The number of points to find
	vector<pair<int, int>> points; // vector to place the found points into

	// Find the horizontally adjacent points to the given point
	if (orientation)
	{
		int leftSide = noOfPointsToFind / 2; // number of the points to find to the left of the given point
		if (p.second - leftSide < 0)
		{
			leftSide = leftSide + (p.second - leftSide); // adjust the number of points to find on the left side so we don't go off the grid
		}
		int rightSide = noOfPointsToFind - leftSide; // Number of points to find to the left of the given point

		// Make sure that there's enough points on the right side so that we don't go off the grid, otherwise adjust both sides
		if (p.second + rightSide > 9)
		{
			int adjustment = (p.second + rightSide) - 9; // The number of points that go off grid
			rightSide -= adjustment; // Adjust how many points to find on the right side of the given point
			leftSide += adjustment; // Adjust how many points to find on the left side of the given point
		}

		// Find all of the points on the left side and add them to the vector
		for (int i = leftSide; i > 0; i--)
		{
			pair<int, int> point = make_pair(p.first, p.second - i);
			points.push_back(point);
		}

		// Add the given point to the vector
		points.push_back(p);

		// Find all of the points on the right side and add them to the vector
		for (int i = 1; i <= rightSide; i++)
		{
			pair<int, int> point = make_pair(p.first, p.second + i);
			points.push_back(point);
		}
	}
	else
	{
		// Find the points that are vertically adjacent to the given point

		int above = noOfPointsToFind / 2; // Number of points to find above the given point
		// Make sure that we don't go off grid
		if (p.first - above < 0)
			above = above + (p.first - above);
		int below = noOfPointsToFind - above; // Number of points to find below the given point
		// Make sure that we don't go off grid when looking for point below the given point, otherwise adjust both above and below
		if (p.first + below > 9)
		{
			int adjustment = (p.first + below) - 9; // The number of points that go off grid
			below -= adjustment; // Adjust how many points to find below the given point
			above += adjustment; // Adjust how many points to find above the given point
		}

		// Find all of the points above and add them to the vector
		for (int i = above; i > 0; i--)
		{
			pair<int, int> point = make_pair(p.first - i, p.second);
			points.push_back(point);
		}

		// Add the given point to the vector
		points.push_back(p);

		// Find all of the points below and add them to the vector
		for (int i = 1; i <= below; i++)
		{
			pair<int, int> point = make_pair(p.first + i, p.second);
			points.push_back(point);
		}
	}

	return points; // Return the vector of points that were found
}

void BattleshipAI::saveAttackData()
{
	try
	{
		vector<vector<pair<int, int>>> p;
		// Fill up the attack data
		if (aiAttackData == NULL)
		{
			p = grid->attackData();
			aiAttackData = &p;
		}
		else
			grid->attackData(aiAttackData);

		String^ contentToWrite = "{\n";
		int row = 0;
		// Serialize the attack data into a Json String so we can write it to a file
		for (vector<vector<pair<int, int>>>::iterator it = aiAttackData->begin(); it != aiAttackData->end(); it++)
		{
			contentToWrite += "\t{ " + row + ":";
			for (vector<pair<int, int>>::iterator j = it->begin(); j != it->end(); j++)
			{
				contentToWrite += " {" + j->first + " " + j->second + "}";
			}
			contentToWrite += " }\n"; // add a newline to the string
			row++;
		}
		contentToWrite += "}\n";

		string content = msclr::interop::marshal_as<string>(contentToWrite);
		fstream fs;
		fs.open("data.txt", fstream::out); // Open file for writing
		fs << content; // write to file
		fs.close(); // close file
	}
	catch (Exception^ e)
	{
		Console::Write("An Exception occurred: " + e->ToString());
	}
}

void BattleshipAI::loadAttackData()
{
	try
	{
		//StreamReader^ din = File::OpenText("data.txt"); // Try to open the file containing the attack data
		fstream fs;
		fs.open("data.txt", fstream::in); // Open file for read only

		string content;
		// Keep reading from the file until end of file
		while (fs.peek() != EOF)
		{
			string line;
			getline(fs, line, '\n'); // read a line until a newline and store in the line string variable
			content += line; // append the string to the content variable
		}
		
		fs.close(); // close the file stream as it's no longer needed

		// Deserialize it into a 2D vector of pairs
		if (!content.empty()) // only if the file isn't empty
		{
			// Lets make sure the aiAtttackData vector is empty
			if (aiAttackData != NULL)
				aiAttackData->clear(); // Removes everything from the vector
			int index = 0;
			while (content[index] != ':') // Ignore everything before the first :
			{
				index++;
			}
			for (int i = 0; i < 10; i++)
			{
				vector<pair<int, int>> vp;
				while (content[index] != '\t' && index < content.size())
				{
					if (content[index] == '{')
					{
						// Get the two numbers within the two brackets
						string first; // first number
						string second; // second number
						while (content[++index] != ' ')
						{
							first += content[index];
						}
						while (content[++index] != '}')
						{
							second += content[index];
						}

						// Convert the two strings into integers and make a pair value to store in the vp vector
						vp.push_back(make_pair(stoi(first), stoi(second)));
					}
					index++;
				}
				aiAttackData->push_back(vp);
				while (content[index] != ':' && index < content.size()) // Ignore everything until a : for the next iteration of the for loop
				{
					index++;
				}
			}
		}
	}
	catch (Exception^ e)
	{
		Console::Write("An Exception occurred: " + e->ToString());
	}
}

void BattleshipAI::loadPlayerAttackData()
{
	try
	{
		//StreamReader^ din = File::OpenText("data.txt"); // Try to open the file containing the attack data
		fstream fs;
		fs.open("pData.txt", fstream::in); // Open file for read only

		string content;
		// Keep reading from the file until end of file
		while (fs.peek() != EOF)
		{
			string line;
			getline(fs, line, '\n'); // read a line until a newline and store in the line string variable
			content += line; // append the string to the content variable
		}

		fs.close(); // close the file stream as it's no longer needed

		// Deserialize it into a 2D vector of pairs
		if (!content.empty()) // only if the file isn't empty
		{
			// Lets make sure the aiAtttackData vector is empty
			if (pAttackData != NULL)
				pAttackData->clear(); // Removes everything from the vector
			else
				pAttackData = new vector<vector<pair<int, int>>>(); // Create a new 2D vector of integer pairs
			int index = 0;
			while (content[index] != ':') // Ignore everything before the first :
			{
				index++;
			}
			for (int i = 0; i < 10; i++)
			{
				vector<pair<int, int>> vp;
				while (content[index] != '\t' && index < content.size())
				{
					if (content[index] == '{')
					{
						// Get the two numbers within the two brackets
						string first; // first number
						string second; // second number
						while (content[++index] != ' ')
						{
							first += content[index];
						}
						while (content[++index] != '}')
						{
							second += content[index];
						}

						// Convert the two strings into integers and make a pair value to store in the vp vector
						vp.push_back(make_pair(stoi(first), stoi(second)));
					}
					index++;
				}
				pAttackData->push_back(vp);
				while (content[index] != ':' && index < content.size()) // Ignore everything until a : for the next iteration of the for loop
				{
					index++;
				}
			}
		}
	}
	catch (Exception^ e)
	{
		Console::Write("An Exception occurred: " + e->ToString());
	}
}