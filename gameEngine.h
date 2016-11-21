#ifndef GAMEENGINE.H
#define GAMEENGINE.H
#include <iostream>
#include <string>
#include "battle.cpp"
#define MAP_SIZE 100
#define SWAMP 4
#define FOREST 3
#define DESERT 1

using namespace std;

/*
NOTE: main() function should hold a loop that keeps us on the menu
until the game is exited
*/
class GameEngine {

private:
	int[MAP_SIZE][MAP_SIZE] newmap;
	Character mainCharacter;
	void go(string dir);
	void foundTrainer(void);
	void foundWildPokemon(void);
	void foundTown(void);
	void foundItem(void);
	void createMap();
public:
	//public ones
	GameEngine(void); // Constructor, sequence to create character and choose initial pokemon
	void viewPokedex(void);
	void viewBag(void); // calls accessors of player Character to see inventory counts
	void viewTeam(void);
	void help(void) // get game guidance and tips
	// save game function if time allows
	// End game function to be added?
};

class Town {
	// private methods and fields
	int location[2]; // size-two array, store the x and y indices of town's location on map (a 2x2 matrix)
	// add private functions for buyItems() to use in its function definition
public:
	// public methods and fields
	Town(void); // Initialize a new town, include its location on map
	void battleGym(void); // includes a call to the Battle class
	healPokemon(Pokemon party[6]);
	buyItems(void); // open store interface
};

//Marco: I made an int function to make sure responses are taken as ints.
int getInt() {
	int response;
	string input = " ";
	while (true) {
		getline(cin, input);
		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> response)
			break;
		cout << "Invalid choice, please try again: ";
	}
	return response;
}

#endif
