#include "battle.h"
#include <iostream>

using namespace std;
// define functions in header (main() NOT located here)

void attack(bool turn){
	int dodgechance;
	int damage;
	if (turn == 0)
		dodgechance = mypokemon.dodge;
	else
		dodgechance = enemypokemon.dodge;
	int dodgeroll = rand() % 100;
	if (dodgeroll >= dodgechance) {
		//attack
		cout << "attack was successful!\n";
		if (turn == 0) {
			//Note: attacks have yet to be balanced.
			//mypokemon attacks
			damage = (mypokemon.attack * 0.5 + mypokemon.level * 0.2)/(enemy.defense * 0.3);
			//The typeMultiplier represents a double array of gen 1 pokemon type chart multipliers.
			//the pokemon.typenumber
			damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
		}
		else {
			//enemy pokemon attacks
			damage = (enemypokemon.attack * 0.5 + enemypokemon.level * 0.2)/(mypokemon.defense * 0.3);
			damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
		}
	}
	else
		//attack missed.
		cout << " The attack missed!\n";
	if (mypokemon.health <= 0) {
		//forces a switch of pokemon if pokemon faints.
		cout << "Your pokemon has fainted!";
		//todo: make a loop that checks the next healthy pokemon.
		switchPokemon();
	}
	if (enemypokemon.health <= 0) {
		cout << "enemy pokemon has fainted!";
		//todo: make a loop that checks the next healthy pokemon (and maybe battle type).
		switchPokemon();
	}
};

void switchPokemon{
	//for both user choice and forced pokemon switch.
};

Battle::Battle(Character player, Pokemon enemy) {
	int action = 0;
	//turn decides who attacks: 0 = you, 1 = enemy.
	bool turn = 0;
	while (action != 4 || (enemypokemon.health>0 && mypokemon.health>0)) {
		cout << "\nYou encountered a wild pokemon, what would you like to do?" << endl;
		cout << "\t1) FIGHT\t2) BAG\n\t3) POKEMON\t4) RUN\n\n\tchoice: ";
		action = getInt();
		switch (action) {
		case 1:
			attack(0);
			turn = 1;
			break;
		case 2:
			//open bag
			int bagChoice = 0;
			while (bagChoice > 3 || bagChoice < 1) {
				cout << "You have: \t1) " << mainCharacter.numofPokeballs << " pokeballs\n\t2) " << mainCharacter.numofPotions << " health potions";
				cout << "\n\t3)RETURN\nWhat will you use?\n\t\tchoice: ";
				bagChoice = getInt();
				if (bagChoice == 1) {
					//use Pokeball
				}
				if (bagChoice == 2) {
					//use health potion
					mypokemon.changeCurrentHealth(potion);
				}
			}
			break;
		case 3:
			int pokeswitch = 0;
			//conflict: how can I retrieve the pokemon name?
			while (pokeswitch > 7 || pokeswitch < 1) {
				cout << "Which pokemon would you like to switch to?";
				cout << "\n\t1)" << mainCharacter.getPokemon(1);
				cout << "\t2)" << mainCharacter.getPokemon(2);
				cout << "\n\t3)" << mainCharacter.getPokemon(3);
				cout << "\t4)" << mainCharacter.getPokemon(4);
				cout << "\n\t5)" << mainCharacter.getPokemon(5);
				cout << "\t6)" << mainCharacter.getPokemon(6);
				cout << "\n\t\t7) Exit\n\n\tchoice: ";
				pokeswitch = getInt();
				switch (pokeswitch) {
				case 1:
					switchPokemon(1);
					break;
				case 2:
					switchPokemon(2);
					break;
				case 3:
					switchPokemon(3);
					break;
				case 4:
					switchPokemon(4);
					break;
				case 5:
					switchPokemon(5);
					break;
				case 6:
					switchPokemon(6);
					break;
				}
				if (pokeswitch > 7 || pokeswitch < 1)
					cout << "Invalid pokemon choice, please try again.\n";
			}
			if (pokeswitch != 7) turn = 1;
		}
		if (turn == 1) {
			cout << "enemy pokemon attacks!";
			attack(1);			
			turn = 0;
		}
	}
	if (mypokemon.health <= 0) {
		cout << "You have lost the battle!\n";
	}
	else
	cout << "you ran away!";
}
//Battle for a character essentially does the same thing but you cannot run away nor catch.
Battle::Battle(Character player, Character opponent) {
	int action = 0;
	//turn decides who attacks: 0 = you, 1 = enemy.
	bool turn = 0;
	while (enemypokemon.health>0 && mypokemon.health>0) {
		cout << "\nYou encountered a wild pokemon, what would you like to do?" << endl;
		cout << "\t1) FIGHT\t2) BAG\n\t3) POKEMON\n\n\tchoice: ";
		action = getInt();
		switch (action) {
		case 1:
			attack(0);
			turn = 1;
			break;
		case 2:
			//open bag
			int bagChoice = 0;
			while (bagChoice > 3 || bagChoice < 1) {
				cout << "You have: \t1) " << mainCharacter.numofPokeballs << " pokeballs\n\t2) " << mainCharacter.numofPotions << " health potions";
				cout << "\n\t3)RETURN\nWhat will you use?\n\n\tchoice: ";
				bagChoice = getInt();
				if (bagChoice == 1){
					//can't use pokeballs here.
					cout << "You can't catch their pokemon!\n";
				}
				if (bagChoice == 2){
					//use health potion
					mypokemon.changeCurrentHealth(potion);
				}
			}
			break;
		case 3:
			int pokeswitch = 0;
			while (pokeswitch > 7 || pokeswitch < 1) {
				cout << "Which pokemon would you like to switch to?";
				cout << "\n\t1)" << mainCharacter.getPokemon(1);
				cout << "\t2)" << mainCharacter.getPokemon(2);
				cout << "\n\t3)" << mainCharacter.getPokemon(3);
				cout << "\t4)" << mainCharacter.getPokemon(4);
				cout << "\n\t5)" << mainCharacter.getPokemon(5);
				cout << "\t6)" << mainCharacter.getPokemon(6);
				cout << "\n\t\t7) Exit\n\n\tchoice: ";
				pokeswitch = getInt();
				switch (pokeswitch) {
				case 1:
					switchPokemon(1);
					break;
				case 2:
					switchPokemon(2);
					break;
				case 3:
					switchPokemon(3);
					break;
				case 4:
					switchPokemon(4);
					break;
				case 5:
					switchPokemon(5);
					break;
				case 6:
					switchPokemon(6);
					break;
				}
				if (pokeswitch > 7 || pokeswitch < 1)
					cout << "Invalid pokemon choice, please try again.\n";
			}
			if (pokeswitch != 7) turn = 1;
		}
		if (turn == 1) {
			cout << "enemy pokemon attacks!";
			attack(1);
			turn = 0;
		}
	}
	if (mypokemon.health <= 0) {
		cout << "You have lost the battle!\n";
	}
	else if(enemypokemon.health <= 0) {
		cout << "You won the battle!\n";
	}
}

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