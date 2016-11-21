#include "pa_group.h"

int main()
{
	GameEngine game = new GameEngine();
	cout << "\tWhat do you want to do?\n\t\t1) Explore\n\t\t2) Pokedex\n\t\t3) Pokemon\n\t\t4) Bag\n\t\t5) Quit\n\n\tchoice: ";
	int choice = getInt();
	while (choice != 5) {
		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		}
		cout << "\tWhat do you want to do?\n\t\t1) Explore\n\t\t2) Pokedex\n\t\t3) Pokemon\n\t\t4) Bag\n\t\t5) Quit\n\n\tchoice: ";
		choice = getInt();
	}
	cout << "Goodbye!" << endl;
}

// GameEngine: related functions and map assets
{

	GameEngine::GameEngine()
	{
		int genderChoice;
		string nameChoice;

		cout << "You wake up dazed and confused with bright white walls burning your eyes." << endl;
		cout << "You see a large green figure in a white lab coat staring down at you. 'Hello!' it says." << endl;
		cout << "Yes, the big green alligator is talking to you.";
		cout << "'My name is professor Albert. Yes, I am an alligator, no your not dreaming, yes I am gald you woke up." << endl;
		cout << " I found you passed out in Turlington. What is your name?' " << endl;
		cout << "Your name: ";
		nameChoice = getString();
		cout << "'Thats a great name. It is nice to meet you " << mainCharacter.getName() << ". " << endl;
		cout << "I'm sorry I have to ask this but my eyesight is not the best, but what is your gender?'" << endl;
		cout << "Your gender (1. Female, 2. Male): ";
		genderChoice = getInt();

		mainCharacter = new Character(nameChoice, genderChoice);

		cout << "'Thats great! I'm happy to meet you. I just wish it was under better circumstances. " << endl;
		cout << "Like I said, I found you passed out in th middle of Turlington so I brought you back to my lab to patch you up." << endl;
		cout << "Turns out I can heal you and Pokemon! Do you remeber what happened?'" << endl;
		string ans = getString();

		if (ans.compare("No") == 0 || ans.compare("NO") == 0 || ans.compare("no") == 0)
		{
			cout << "Okay, then I will fill you in. ";
		}
		else if (ans.compare("YES") == 0 || ans.compare("Yes") == 0 || ans.compare("yes") == 0)
		{
			cout << "Then what happened? " << endl;
			getString();
			cout << "Yeah, thats not right, let me give you the real story.";
		}
		else
		{
			cout << "Yeah, you've got a concussion so I will just fill you in. ";
		}


		/** The map will hold ints and the ints will represent as fallows:
		* 0: wall		Example output: Its a 40 foot tall concrete wall with barbwire on top. aka Trump's wall
		* 2: tree/cactus	Example output: There is a tree north of you... go north... you hit a tree
		* 3: forest 		Example output: You are in a forest
		* 1: desert		Example output: You are in a desert
		* 4: swamp		Example output: ...
		* 5: town		Example output: You have found (blank) town
		*/

		createMap();

	}

	void GameEngine::createMap()
	{
		for (int i = 0; i < MAP_SIZE / 2; i++) {
			for (int j = 0; j < MAP_SIZE / 2; j++) {
				newmap[i][j] = SWAMP;
			}
		}

		for (int i = 0; i < MAP_SIZE / 2; i++) {
			for (int j = 50; j < MAP_SIZE; j++) {
				newmap[i][j] = FOREST;
			}
		}

		for (int i = 50; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE / 2; j++) {
				newmap[i][j] = SWAMP;
			}
		}

		for (int i = 50; i < MAP_SIZE; i++) {
			for (int j = 50; j < MAP_SIZE; j++) {
				newmap[i][j] = DESERT;
			}
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				newmap[i + 39][j + 39] = FOREST;
			}
		}


		for (int i = 0; i < 100; i++)
		{
			newmap[0][i] = 0;
			newmap[99][i] = 0;
			newmap[i][0] = 0;
			newmap[i][99] = 0;
		}

		//top = north, left = east
		//town 1, smallest
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//top left corner of town is at corordinate (15,15)
				newmap[i + 15][j + 15] = 5;
			}
		}

		//town 2, smaller
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//top left corner of town is at corordinate (57,57)? i guess, idk, maybe it should be moved
				newmap[i + 57][j + 57] = 5;
			}
		}

		//town 3, same size as 2
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//top left corner of town is at corordinate (79,20)? i guess, idk, maybe it should be moved
				newmap[i + 79][j + 20] = 5;
			}
		}

		//town 4, big town
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				//top left corner of town is at corordinate (10,60)? i guess, idk, maybe it should be moved
				newmap[i + 10][j + 60] = 5;
			}
		}

		//need to fill in a lot more here
	}

};


// Pokemon assets
{

	/*
	I have everything under control as far as generating randomized pokemon with varying stats based on level, and leveling them up based on xp given through battle. There is still a lot to do but here is something i have so far...
	*/

	// this array contains all of the names and types for each pokemon. the evelution will be chosen during construction based on level.
	// gonna be adding all 150 I suppose since it's pretty easy to add names/types.
	string pokeMen[11][4] = { { "Bulbasaur", "Ivysaur", "Venusaur", "grass" },{ "Charmander", "Charmeleon", "Charizard", "fire" },{ "Squirtle", "Wartortle", "Blastoise", "water" },{ "Caterpie", "Metapod", "Butterfree", "bug" },
	{ "Weedle", "Kakuna", "Beedrill", "bug" },{ "Pidgey", "Pidgeotto", "Pidgeot", "flying" },{ "Rattata", "Raticate", "Raticate", "normal" },{ "Spearow", "Fearow", "Fearow", "flying" },{ "Ekans", "Arbok", "Arbok", "poison" },
	{ "Pikachu", "Raichu", "Raichu", "electric" },{ "Sandshrew", "Sandslash", "Sandslash", "ground" } };

	Pokemon::Pokemon(int level) {

		//names are chosen based on level, so a level one will be squirtle, etc. i haven't yet implemented evelution for EXISTING pokemon on level up.
		choice = rand() % 10;
		if (level <= 33) {
			this->name = pokeMen[choice][0];
		}
		else if (level <= 66) {
			this->name = pokeMen[choice][1];
		}
		else {
			this->name = pokeMen[choice][2];
		}
		this->type = pokeMen[choice][3];
		this->experience = 0;
		this->level = level;

		//these numbers are obviously subject to change. also we will likely not use rand() in final version since it will create the same pokemon each time the game is run, but that may be useful for debugging
		this->health = (level - 1) * 20 + (rand() % 151 + 50);
		this->currentHealth = health;
		this->attack = (level - 1) * 3 + (rand() % 15 + 8);

		//defense is a value from 0-25 and is higher for lower health pokemon. i envisioned it being a chance to dodge (out of 100%) to help buff lower health pokemon.
		this->defense = int((1.0 / (health - ((level - 1) * 20))) * 1000 + (rand() % 10 - 5));

	}

	int Pokemon::getHealth() {
		return health;
	}

	int Pokemon::getAttack() {
		return attack;
	}

	int Pokemon::getDefense() {
		return defense;
	}

	int Pokemon::getCurrentHealth() {
		return currentHealth;
	}

	int Pokemon::getLevel() {
		return level;
	}

	int Pokemon::getExperience() {
		return experience;
	}

	string Pokemon::getName() {
		return name;
	}

	string Pokemon::getType() {
		return type;
	}

	//not sure if this should print anything or not, depends on battles, also, note that this INCREASES health by healthChange.
	void Pokemon::changeCurrentHealth(int healthChange) {
		if ((currentHealth + healthChange) < health) {
			currentHealth += healthChange;
		}
		else {
			currentHealth = health;
		}
		if (currentHealth < 0) {
			currentHealth = 0;
		}
	}

	//this should probably print out some messages when level up happens.
	void Pokemon::giveExperience(int exp) {
		if ((experience + exp) < (50 + (10 * level))) {
			experience = experience + exp;
		}
		else {
			experience = 0;
			level += 1;
			health += 20;
			currentHealth += 20;
			attack += 3;
		}
	}

};


// Battle assets
{
	
	void attack(bool turn) {
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
				damage = (mypokemon.attack * 0.5 + mypokemon.level * 0.2) / (enemy.defense * 0.3);
				//The typeMultiplier represents a double array of gen 1 pokemon type chart multipliers.
				//the pokemon.typenumber
				damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			}
			else {
				//enemy pokemon attacks
				damage = (enemypokemon.attack * 0.5 + enemypokemon.level * 0.2) / (mypokemon.defense * 0.3);
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
					if (bagChoice == 1) {
						//can't use pokeballs here.
						cout << "You can't catch their pokemon!\n";
					}
					if (bagChoice == 2) {
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
		else if (enemypokemon.health <= 0) {
			cout << "You won the battle!\n";
		}
	}
	
};


// Character assets
{

// TODO: !!!

};

string getString()
{
	std::string item;
	bool validInput = false;

	do
	{
		std::cin >> item;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			validInput = false;
		}
		else
		{
			validInput = true;
		}

	} while (!validInput);

	return item;
}

int getInt()
{
	int item;
	bool validInput = false;

	do
	{
		std::cin >> item;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			item = 0;
			validInput = false;
			std::cout << "Invalid Input, try again" << std::endl;
		}
		else
		{
			validInput = true;
		}

	} while (!validInput);

	return item;
}