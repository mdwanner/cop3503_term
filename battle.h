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
int getInt() {
	//This method makes sure that the response is an int. 
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