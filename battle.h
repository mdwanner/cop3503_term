#ifndef BATTLE.H
#define BATTLE.H
#include "Pokemon.h"
using namespace std;

class Battle {
	
public:
	// public ones
	Battle(Character &player, Pokemon &enemy); // select the first pokemon from your party to fight, for wild battle scenarios
	Battle(Character &player, Character &opponent); // for Trainer vs. Trainer scenarios
	void attack(bool turn,Character &thePlayer, Character &theEnemyPlayer);
	void attack(bool turn, Character &thePlayer, Pokemon &wildPokemon);
	Pokemon switchPokemon(Character &trainer);
	Pokemon switchPokemon(int num, Character &trainer);
};

//Marco: Same getInt function as in gameEngine.h. (May not be needed since it's a duplicate).
int getInt();

#endif
