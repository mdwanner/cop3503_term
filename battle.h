#ifndef BATTLE.H
#define BATTLE.H
using namespace std;

class Battle {
	// private methods and fields
	Pokemon owned; // Player's pokemon that is in play
	Pokemon enemy; // Enemy pokemon in play
	
public:
	// public ones
	Battle(Character player, Pokemon enemy); // select the first pokemon from your party to fight, for wild battle scenarios
	Battle(Character player, Character opponent); // for Trainer vs. Trainer scenarios
	void attack(bool turn);
	void switchPokemon(int chosenPokemon);
};

//Marco: Same getInt function as in gameEngine.h. (May not be needed since it's a duplicate).
int getInt();

#endif