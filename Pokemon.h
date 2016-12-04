#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <string>

using namespace std;

class Pokemon { // No subclasses, just one basic attack, at least for now.

	friend class Character; // Matt: So bag contents can modify pokemon health

private:
	int pokedex;
	string type;
	string name; //this is which pokemon it is, e.g. Squirtle.
	int health; // health cap
	int currentHealth;
	int attack;
	int dodge; //chance to dodge out of 100%. higher for lower health pokemon. Does not increase with level.
	int level; //currently no level cap, i'll fix that.
	int experience; //experience per level starts at 50 and increases by 10 per level.
	int choice; //DONT FORGET TO DECLARE YOUR VARIABLES. 
	static string pokeMen[151][4];//this is an array containing the names of all the pokemen in indexes 0-2, and type in index 3. Eventually it will be [150][4]
public:
	Pokemon();
	Pokemon(int); //creates randomized pokemon with stats/evolution based on level
	Pokemon(int, int);
	string getName();
	string getType();
	string getPokedexEntry(int, int);
	int getHealth();
	int getCurrentHealth();
	int getAttack();
	int getDodge();
	int getLevel();
	int getExperience();
	void giveExperience(int); //handles leveling up, but doesn't print anything right now
	void changeCurrentHealth(int); //healthChange is how much to ADD to currentHealth
};

class Character {

	friend class Explore;
	friend class Battle;						//From joey, needed in explore function, wanted to limit access to 
												//all other classes
private:
	
	string name;
	int gender;
	Pokemon party[6];
	Pokemon currentPokemon;						//Marco: The current pokemon the player holds.
	
	int money;
	int pokeBalls;
	int potions;

	int xPosition;								//From joey, needed in explore function
	int yPosition;
	
	int badges;									// increment this as gyms beaten 
public:
	Character();
	Character(std::string);						// create accessors for the items
	Character(std::string, int);
	string getName();
	Pokemon getPokemon(int);				// takes number 0-5 of desired Pokemon in party
	Pokemon *getParty();
	Pokemon getCurrentPokemon();				//Marco: for getting the currentPokemon the player has.
	Pokemon setCurrentPokemon(int);			//Marco: for setting up the currentPokemon. 
	void setCurrentPokemon(Pokemon);
	

	void usePotion(Pokemon*);
	void usePokeBall();
	bool spendMoney(int);
	void forfeitCash(int);
	void addPotion();
	void addPokeBall();
	void addMoney(int);
	int getPotionCount();
	int getPokeBallCount();
	int getMoney();
	void setPos();
	void addPokemon(Pokemon);
	int getBadges();
};

#endif
