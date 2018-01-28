#pragma once
#ifndef SHIP_H
#define SHIP_H

// This class will be used to create the fleet of battleships for both the player and AI

#include <vector>
#include <utility>	// Needed to make pairs of (row, column) to insert into a vector

using namespace std;

class Ship
{
	public:
		Ship();	// default constructor which will create a destroyer with 2 health
		Ship(int shipType); // Custom constructor which creates a ship with the provided shipType # ( 1 = carrier, 2 = battleship, 3 = cruiser, 4 = submarine, 5 = destroyer)
		void dealDmg(); // This method will decrement the ship's health by 1 every time it is called
		bool isSunking(); // This method returns true if the attack sunk the ship (health = 0); dealDmg() is called within this method
		void setLocation(vector<pair<int, int>> loc); // Set the slots the ship is occupying on the grid;
		vector<pair<int, int>> getLocation(); // Returns a vector containing the slot locations that the ship is occupying
		bool isOnSlot(pair<int, int> p); // Check to see if the ship is occupying the given slot on the grid
		int getShipSize(); // Returns the size of the ship
		int getShipHP(); // Returns the ships health level

	private:
		int health;	// variable to store the ship's health
		int size;	// vaiable to store the ship's size
		vector<pair<int, int>> location; // This vector will contain the slots that the ship is occupying on the grid
};

#endif // !SHIP_H


