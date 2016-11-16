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

class Pokemon { // No subclasses, just one basic attack, at least for now.
private:
	int pokedex;
	string type;
	static const string pokeMen[11][4]; //this is an array containing the names of all the pokemen in indexes 0-2, and type in index 3. Eventually it will be [150][4]
	string name; //this is which pokemon it is, e.g. Squirtle.
	int health; // health cap
	int currentHealth;
	int attack;
	int defense; //chance to dodge out of 100%. higher for lower health pokemon. Does not increase with level.
	int level; //currently no level cap, i'll fix that.
	int experience; //experience per level starts at 50 and increases by 10 per level.
public:
	Pokemon(int level); //creates randomized pokemon with stats/evolution based on level
    	string getName();
    	string getType();
    	int getHealth();
    	int getCurrentHealth();
    	int getAttack();
    	int getDefense();
    	int getLevel();
    	int getExperience();
    	void giveExperience(int exp); //handles leveling up, but doesn't print anything right now
    	void changeCurrentHealth(int healthChange); //healthChange is how much to ADD to currentHealth
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
