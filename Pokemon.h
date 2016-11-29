#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>

using namespace std;

class Pokemon { // No subclasses, just one basic attack, at least for now.
private:
	int pokedex;
	string type;
	static const string pokeMen[11][4]; //this is an array containing the names of all the pokemen in indexes 0-2, and type in index 3. Eventually it will be [150][4]
	string name; //this is which pokemon it is, e.g. Squirtle.
	int health; // health cap
	int currentHealth;
	int attack;
	int defense;
	int dodge; //chance to dodge out of 100%. higher for lower health pokemon. Does not increase with level.
	int level; //currently no level cap, i'll fix that.
	int experience; //experience per level starts at 50 and increases by 10 per level.
public:
	Pokemon(int level); //creates randomized pokemon with stats/evolution based on level
	Pokemon(int level, string name); //overloaded constructor to create starters/other specific pocheymancheys.
	string getName();
	string getType();
	int getHealth();
	int getCurrentHealth();
	int getAttack();
	int getDodge();
	int getDefense();
	int getLevel();
	int getExperience();
	void giveExperience(int); //handles leveling up, but doesn't print anything right now
	void changeCurrentHealth(int); //healthChange is how much to ADD to currentHealth
};

class Character {

	friend class Explore;						//From joey, needed in explore function, wanted to limit access to 
												//all other classes
private:
	string name;
	Pokemon party[6];
	Pokemon currentPokemon;						//Marco: The current pokemon the player holds.
	int xPosition;								//From joey, needed in explore function
	int yPosition;
	int badges;									// increment this as gyms beaten 
public:
	Character(std::string);						// create accessors for the items
	Character(std::string, int);
	string getName();
	Pokemon getPokemon(int);				// takes number 1-6 of desired Pokemon in party
	Pokemon getCurrentPokemon();				//Marco: for getting the currentPokemon the player has.
	Pokemon setCurrentPokemon(int);			//Marco: for setting up the currentPokemon. 
												//might help to use getPokemon(numChange) in it to set the current Pokemon.
	int getBadges();
};

#endif
