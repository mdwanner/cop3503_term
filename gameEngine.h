#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <iostream>
#include <string>
#include "battle.h"
#include "Pokemon.h"
#include "explore.h"
#define MAP_SIZE 100
#define WALL 1
#define FOREST 2
#define DESERT 3
#define SWAMP 4
#define TOWN 5

using namespace std;

/*
NOTE: main() function should hold a loop that keeps us on the menu
until the game is exited
*/
class GameEngine {

	friend class explore;

private:
	int** newmap;
	Character mainCharacter;
	void go(string dir);
	void foundTrainer();
	void foundWildPokemon();
	void foundTown();
	void foundItem();
	int** createMap();
public:
	//public ones
	GameEngine(); // Constructor, sequence to create character and choose initial pokemon
	void viewPokedex();
	void viewBag(); // calls accessors of player Character to see inventory counts
	void viewTeam();
	void help(); // get game guidance and tips
	// save game function if time allows
	// End game function to be added?
};

class Town {
	// private methods and fields
	int location[2]; // size-two array, store the x and y indices of town's location on map (a 2x2 matrix)
	// add private functions for buyItems() to use in its function definition
public:
	// public methods and fields
	Town(); // Initialize a new town, include its location on map
	void battleGym(); // includes a call to the Battle class
	void healPokemon(Pokemon party[6]);
	void buyItems(); // open store interface
};

//Marco: I made an int function to make sure responses are taken as ints.
int getInt();
string getString();

#endif
