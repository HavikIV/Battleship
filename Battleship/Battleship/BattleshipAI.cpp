#include "BattleshipAI.h"

// custom method of sorting for vector<pair<pair<int, int>, float>> lists in descending order
struct descendingOrder
{
	inline bool operator() (const pair<pair<int, int>, float> &a, const pair<pair<int, int>, float> &b)
	{
		return a.second > b.second;
	}
};

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
	loadPlayerAttackData();

	if (pAttackData == NULL || pAttackData->size() == 0)
	{
		setupGrid(); // Setup the AI's grid by randomly selecting slots
	}
	else
	{
		smartGridSetup(); // Setup the AI's grid based on the player's attack data
	}

	while (keepThreadAlive)
	{
		if (!gm->attackInProgress(false))
		{
			if (pAttackData == NULL || pAttackData->size() == 0)
			{
				// Since no previous data exists, let's attack randomly
				attack();
			}
			else
			{
				// Time to attack using the previous attack data
				smartAttack();
			}
		}
	}

	// Before exiting the thread, lets both players attack data
	saveAttackData(); // Save the AI's attack data from this round
	savePlayerAttackData(gm->getPlayerAttackData()); // Save the player's attack data
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
	while (gm->attackInProgress(false) && keepThreadAlive)
	{
		Thread::Sleep(100);
	}
	//Thread::Sleep(1500);
	
	Monitor::Enter(gm);
	if (gm->getAttackResult(false) && keepThreadAlive)
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
					if (attackAbove)
					{
						attackAbove = false;
					}
					if (slotToAttack.first < startingPoint.first)
					{
						slotToAttack.first = startingPoint.first; // Making sure that we don't end up attacking the starting point multiple times
					}
					if (slotToAttack.first < 9)
					{
						slotToAttack.first += 1; // Move down a row
					}
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
					if (!attackRightSide)
					{
						// Since the current attack on the right is a miss, lets confirm that we can attack the left side
						attackHorizontally = (startingPoint.second == 0) ? false : true; // If the starting point is in the first column, we can't go any further to the left
					}
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
		if (aiAttackData == NULL || aiAttackData->size() == 0)
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

void BattleshipAI::savePlayerAttackData(vector<vector<pair<int, int>>> pData)
{
	try
	{
		if (pAttackData == NULL)
			pAttackData = new vector<vector<pair<int, int>>>(); // Create a new 2D vector of integer pairs

		String^ contentToWrite;
		if (pAttackData->size() != 0)
		{
			// Update the pAttackData with the pData
			for (vector<vector<pair<int, int>>>::iterator d_it = pData.begin(), it = pAttackData->begin(); d_it != pData.end(); d_it++, it++)
			{
				for (vector<pair<int, int>>::iterator d_pit = d_it->begin(), pit = it->begin(); d_pit != d_it->end(); d_pit++, pit++)
				{
					pit->first += d_pit->first; // Increases the number of hits on this slot
					pit->second += 1; // Increment the number of rounds played
				}
			}

			// Now that the player attack data has been updated, lets write it to file
			// Before writing everything to file, convert it into a string; Using String^ instead of string as the compiler defaults "blah" to be String^ objects
			contentToWrite = "{\n";
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
		}
		else
		{
			// Since there isn't any previous player attack data, just write the pData to the file
			contentToWrite = "{\n";
			int row = 0;
			// Serialize the attack data into a Json String so we can write it to a file
			for (vector<vector<pair<int, int>>>::iterator it = pData.begin(); it != pData.end(); it++)
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
		}

		// Convert the String^ to string for it to be compatible with fstream's << operator
		string content = msclr::interop::marshal_as<string>(contentToWrite);
		// Write to file
		fstream fs;
		fs.open("pData.txt", fstream::out); // Open file for writing
		fs << content; // write to file
		fs.close(); // close file
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

void BattleshipAI::smartAttack()
{
	
	if (slotList == NULL)
	{
		// Let's get a list of slots in order of most hits to least hits
		auto p = getSlotlist();
		slotList = new vector<pair<int, int>>(); // Create a new vector to hold integer pairs
		for (auto it = p.begin(); it != p.end(); it++) // Iterate through the list p and add it to the slotList property
			slotList->push_back(*it);
	}

	// Perform an attack using the first slot in the list
	Monitor::Enter(gm); // Request a lock

	// Let's convert it into a String before passing it on to GameMaster
	String^ s = "" + (Char)('A' + slotList->front().first) + (Char)('1' + slotList->front().second);
	if (slotList->front().second == 9)
		s = s[0] + "10";
	
	gm->setAttack(false, s); // Pass the attack to GameMaster

	Monitor::Exit(gm); // Release the lock

	// This thread should sleep until the attacks have been processed
	while (gm->attackInProgress(false) && keepThreadAlive)
	{
		Thread::Sleep(100);
	}

	Monitor::Enter(gm); // request lock
	if (gm->getAttackResult(false) && keepThreadAlive)
	{
		// Since the attack was a hit, the AI needs to attack adjacent slots until the ship has been destroyed
		auto startingPoint = slotList->front(); // save the starting point
		auto slotToAttack = slotList->front();
		slotList->erase(slotList->begin()); // Let's remove the slot at the beginning of the list

		bool attackHorizontally = true;
		bool attackRightSide = true;
		bool attackAbove = true;
		bool keepLooping = !gm->isShipSinking(startingPoint);

		Monitor::Exit(gm); // Release lock
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
					if (attackAbove)
					{
						attackAbove = false;
					}
					if (slotToAttack.first < startingPoint.first)
					{
						slotToAttack.first = startingPoint.first; // Making sure that we don't end up attacking the starting point multiple times
					}
					if (slotToAttack.first < 9)
					{
						slotToAttack.first += 1; // Move down a row
					}
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
					if (!attackRightSide)
					{
						// Since the current attack on the right is a miss, lets confirm that we can attack the left side
						attackHorizontally = (startingPoint.second == 0) ? false : true; // If the starting point is in the first column, we can't go any further to the left
					}
				}
				else
				{
					attackHorizontally = gm->getAttackResult(false);
				}

			}
			else
			{
				if (attackAbove)
					attackAbove = gm->getAttackResult(false);
			}

			// Update the looping condition before the lock is released
			keepLooping = !gm->isShipSinking(startingPoint);

			// Find the attacked slot in slotList so we can remove it
			for (auto it = slotList->begin(); it != slotList->end(); it++)
			{
				if (*it == slotToAttack)
				{
					// Found the slot in the list, so let's remove it
					slotList->erase(it);
					break; // Time to break out of the for loop
				}
			}

			Monitor::Exit(gm); // Release the lock
		}
		Thread::Sleep(50);
	}
	else
	{
		Monitor::Exit(gm); // release lock
		slotList->erase(slotList->begin()); // Let's remove the slot at the beginning of the list
	}
}

void BattleshipAI::smartGridSetup()
{
	// Vector to store the possible locations to place the selected ship along with it's overall chance of being attacked
	vector<pair<vector<pair<int, int>>, float>> locations = vector<pair<vector<pair<int, int>>, float>>();
	vector<int> shipTypes = { 1, 2, 3, 4, 5 }; // Ship types that need to be placed still

	srand(time(NULL)); // Seed the rand with the current time

	while (shipTypes.size() != 0)
	{
		int randomSelection = rand() % shipTypes.size();
		int shipType = shipTypes[randomSelection]; // randomly select a shipType to place
		int shipSize = 5;
		if (shipType == 2)
		{
			shipSize = 4;
		}
		else if (shipType == 3 || shipType == 4)
		{
			shipSize = 3;
		}
		else if (shipType == 5)
		{
			shipSize = 2;
		}

		for (int i = 1; i < 5; i++)
		{
			auto slot = getSlotInQuadrant(i); // ATTENTION: Need to prevent an already picked slot from being returned
			int maxShift = shipSize / 2;
			int leftShift = maxShift + ((slot.second - maxShift < 0) ? (slot.second - maxShift) : 0); // how many slots the slot can be shifted to the left
			int rightShift = maxShift - ((slot.second + maxShift > 9) ? ((slot.second + maxShift) - 9) : 0); // how many slots the slot can be shift to the right
			int shiftUp = maxShift + ((slot.first - maxShift < 0) ? (slot.first - maxShift) : 0);
			int shiftDown = maxShift - ((slot.first + maxShift > 9) ? ((slot.first + maxShift) - 9) : 0);

			// Starting horizontal placement
			auto loc = findSlots(true, shipType, slot);
			if (!anyOverlaps(loc))
			{
				// Add the possible ship placement into the locations vector along with its overall percentage of being attacked
				locations.push_back(make_pair(loc, getOverallPercentage(loc)));
			}

			if (slot.second != 0 && slot.second != 9)
			{
				// Add the possible ship placements after the slot is shifted to the left in the placement
				for (int shift = 1; shift <= leftShift; shift++)
				{
					if (slot.second + shift <= 9)
					{
						loc = findSlots(true, shipType, make_pair(slot.first, slot.second + shift));
						if (!anyOverlaps(loc) && slotWithinPlacement(loc, slot))
						{
							locations.push_back(make_pair(loc, getOverallPercentage(loc)));
						}
					}
				}
				// Add the possible ship placements after the slot is shifted to the right in the placement
				for (int shift = rightShift; shift != 0; shift--)
				{
					if (slot.second - shift >= 0)
					{
						loc = findSlots(true, shipType, make_pair(slot.first, slot.second - shift));
						if (!anyOverlaps(loc) && slotWithinPlacement(loc, slot))
						{
							locations.push_back(make_pair(loc, getOverallPercentage(loc)));
						}
					}
				}
			}

			// Starting vertical placement
			loc = findSlots(false, shipType, slot);
			if (!anyOverlaps(loc))
			{
				// Add the possible ship placement into the locations vector along with its overall percentage of being attacked
				locations.push_back(make_pair(loc, getOverallPercentage(loc)));
			}

			if (slot.second != 0 && slot.second != 9)
			{
				// Add the possible ship placements after the slot is shifted up in the placement
				for (int shift = 1; shift <= shiftUp; shift++)
				{
					if (slot.first + shift <= 9)
					{
						loc = findSlots(false, shipType, make_pair(slot.first + shift, slot.second));
						if (!anyOverlaps(loc) && slotWithinPlacement(loc, slot))
						{
							locations.push_back(make_pair(loc, getOverallPercentage(loc)));
						}
					}
				}
				// Add the possible ship placements after the slot is shifted down in the placement
				for (int shift = shiftDown; shift != 0; shift--)
				{
					if (slot.first - shift >= 0)
					{
						loc = findSlots(false, shipType, make_pair(slot.first - shift, slot.second));
						if (!anyOverlaps(loc) && slotWithinPlacement(loc, slot))
						{
							locations.push_back(make_pair(loc, getOverallPercentage(loc)));
						}
					}
				}
			}
		}

		// Now that all possible ship placements in all 4 quadrants have been found
		// let's find the placement has the lowest chance of being attacked by iterating through the locations vector
		vector<pair<int, int>> bestPlacementSoFar = locations.begin()->first; // Starting with the first placement
		float currentPercentage = locations.begin()->second;

		// Iterate through the locations vector to find the best placement for the selected ship
		for (auto placement : locations)
		{
			if (placement.second < currentPercentage)
			{
				currentPercentage = placement.second;
				bestPlacementSoFar = placement.first;
			}
		}

		// Place the ship on the grid
		gm->updateShip(false, shipType, bestPlacementSoFar); // Update GameMaster's copy of AI's grid
		grid->setShip(shipType, bestPlacementSoFar); // Place the ship on AI's grid

		// Remove the selected shipType from the types vector
		shipTypes.erase(shipTypes.begin() + randomSelection);
		locations.clear(); // Empty the locations vector for the next iteration of the while loop
		Thread::Sleep(500); // Give some time for time to change
	}

}

vector<pair<int, int>> BattleshipAI::getSlotlist()
{
	vector<pair<pair<int, int>, float>> v;

	int r = 0, c = 0;
	for (auto it = pAttackData->begin(); it != pAttackData->end(); it++, r++)
	{
		c = 0;
		for (auto i = it->begin(); i != it->end(); i++, c++)
		{
			auto pair = make_pair(make_pair(r, c), (i->first / (float)i->second));
			v.push_back(pair);
		}
	}

	// let's sort the vector by the float value in descending order
	sort(v.begin(), v.end(), descendingOrder());

	// Let's randomize the slots that have an equal chance of being attacked
	randomizeEquals(v);

	// Now that the slots have been order in descending order we can add the pairs of integers to a vector that will be returned to the caller
	vector<pair<int, int>> slots; // vector of integer pairs representing a slot's location on the grid
	for (auto it = v.begin(); it != v.end(); it++)
	{
		slots.push_back(it->first);
	}

	return slots;
}

void BattleshipAI::randomizeEquals(vector<pair<pair<int, int>, float>> v)
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		if (it->second == (it + 1)->second)
		{
			swap(it, (it + 1)); // Lets swap the two elements as they have an equal chance of being attacked
		}
	}
}

// This helper function will search within the given quadrant in pAttackData to find the slot with the least chance of being attacked by the player.
pair<int, int> BattleshipAI::getSlotInQuadrant(int Quadrant)
{
	int startingRow = 0, startingColumn = 0; // Search within the first quadrant
	if (Quadrant == 2) // Need to search within the second quadrant
	{
		startingColumn = 5;
	}
	else if (Quadrant == 3) // Need to search within the third quadrant
	{
		startingRow = 5;
	}
	else if (Quadrant == 4) // Need to search within the fourth quadrant
	{
		startingRow = startingColumn = 5; 
	}

	pair<int, int> slot(startingRow, startingColumn); // The first slot in the given quadrant
	float currentChance = pAttackData->at(startingRow).at(startingColumn).first / (float)pAttackData->at(startingRow).at(startingColumn).second; // current slot's attacked chance

	// Time to iterate through the quadrant to find the first occurrence slot with the least chance of being attacked
	for (int r = 1; r < 5; r++)
	{
		for (int c = 1; c < 5; c++)
		{
			// Calculate the current slot's chance of being attacked
			float tempChance = pAttackData->at(r).at(c).first / (float)pAttackData->at(r).at(c).second;
			if (tempChance < currentChance && !grid->slotOccupied(make_pair(r, c))) // compare the two percentages
			{
				// Since this slot has a lower chance than the previous selected slot, lets change the selection to it
				currentChance = tempChance;
				slot.first = r;
				slot.second = c;
			}
		}
	}

	return slot; // Return the slot with the lowest chance of being attacked in the given quadrant
}

float BattleshipAI::getOverallPercentage(vector<pair<int, int>> possiblePlacement)
{
	float total = 0.0f;
	for (auto slot : possiblePlacement)
	{
		total += pAttackData->at(slot.first).at(slot.second).first / (float)pAttackData->at(slot.first).at(slot.second).second;
	}
	return total / possiblePlacement.size();
}

bool BattleshipAI::slotWithinPlacement(vector<pair<int, int>> placement, pair<int, int> slot)
{
	for (auto pair : placement)
	{
		if (pair == slot)
		{
			return true;
		}
	}
	return false;
}
