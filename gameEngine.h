#ifndef GAMEENGINE.H
#define GAMEENGINE.H
#include <iostream>
#include <string>
#include "battle.cpp"

using namespace std;

/*
NOTE: main() function should hold a loop that keeps us on the menu
until the game is exited
*/
class GameEngine {

private:
	int[][] map;
	Character mainCharacter;
	void go(string dir);
	void foundTrainer(void);
	void foundWildPokemon(void);
	void foundTown(void);
	void foundItem(void);
	int[][] createMap();
public:
	//public ones
	GameEngine(void); // Constructor, sequence to create character and choose initial pokemon
	void explore(void);
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

class Pokemon { // Should we have subclasses of each Pokemon we implement?
	// private
	int pokedex;
	string type; // string?
	int health; // health cap
	int currentHealth;
	int attack;
	int defense;
	int level;
	int experience;
	/*
	If we are just using one basic attack to keep things simpler for us, then
	we don't need the following two things
	*/
	string ability[4]; // moves currently known
	string abilityIndex[10]; // types of moves that can be learned by this pokemon
public:
	// public
	// need accessors and modifiers
};

class Character {
	// private
	string name;
	Pokemon party[6];
	int badges = 0; // increment this as gyms beaten
public:
	// public
	// create accessors for the items
	Character(string name);
	Character(string name, int gender);
	string getName(void);
	Pokemon getPokemon(int num); // takes number 1-6 of desired Pokemon in party
	int getBadges(void);
};


#endif
