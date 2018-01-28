#include "BattleshipAI.h"

// This constructor takes in a pointer to an instance of GameMaster and it will also create a new Grid
// the AI will populate with its own ships.
BattleshipAI::BattleshipAI(GameMaster^ g)
{
	gm = g;
	grid = new Grid();
}

void BattleshipAI::Start()
{
	setupGrid(); // Setup the AI's grid

	while (true)
	{
		if (gm->AIsTurn() && !gm->attackInProgress())
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
		row = rand() % 9;
		col = rand() % 9;
		// Make a pair with the random numbers
		pair<int, int> slot = make_pair(row, col);

		// Get a vector of integer pairs of where the ship goes
		vector<pair<int, int>> slots = findSlots(rand() % 1, shipType, slot);
		if (!anyOverlaps(slots))
		{
			gm->updateShip(false, shipType, slots); // Set the ship on the AI's grid that the GameMaster keeps track of
			grid->setShip(shipType, slots); // Update the AI's grid so it knows where it's own ships are
			shipType++; // Increment the shipType so that we can place the next ship on the grid
			Thread::Sleep(500); // Need to let the thread sleep so that the AI doesn't rapidly call rand()
		}
		Thread::Sleep(500);
	}
}

void BattleshipAI::attack()
{
	// Request a lock to prevent other thread from doing anything
	Monitor::Enter(gm);

	// Use rand to generate attack on a random point on the player's grid
	srand(time(NULL)); // Seed the rand with the current time
	pair<int, int> slotToAttack = make_pair(rand() % 9, rand() % 9);
	while (grid->isSlotMarked(slotToAttack))
	{
		// Since the slot was previously attacked, let's pick a different slot to attack
		slotToAttack = make_pair(rand() % 9, rand() % 9);
	}

	// Convert the point to a String so we can pass it to GameMaster
	String^ s = "" + (Char)('A' + slotToAttack.first) + (Char)('1' + slotToAttack.second);


	// Attack the point
	gm->setAttack(s);

	// Release the lock
	Monitor::Exit(gm);
	Thread::Sleep(1000);
	
	if (gm->getAttackResult())
	{
		// Need to attack the adjacent slots during the following turns until the ship has been sunk
	}
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
		int leftSide = noOfPointsToFind / 2; // number of the points to find to the right of the given point
		if (p.second - leftSide < 0)
		{
			leftSide = leftSide + (p.second - leftSide); // adjust the number of points to find on the left side so we don't go off the grid
		}
		int rightSide = noOfPointsToFind - leftSide; // Number of points to find to the left of the given point

		// Make sure that there's enough points on the right side so that we don't go off the grid, otherwise adjust both sides
		if (p.second + rightSide > 9)
		{
			int adjustment = rightSide - ((p.second + rightSide) - 9); // The number of points that go off grid
			rightSide -= adjustment; // Adjust how many points to find on the right side of the given point
			leftSide += adjustment; // Adjust how many points to find on the left side of the given point
		}

		// Find all of the points on the right side and add them to the vector
		for (int i = rightSide; i > 0; i--)
		{
			pair<int, int> point = make_pair(p.first, p.second - i);
			points.push_back(point);
		}

		// Add the given point to the vector
		points.push_back(p);

		// Find all of the points on the left side and add them to the vector
		for (int i = 1; i <= leftSide; i++)
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
			int adjustment = below - ((p.first + below) - 9); // The number of points that go off grid
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