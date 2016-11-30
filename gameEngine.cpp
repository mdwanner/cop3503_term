#include "gameEngine.h"


// Define functions from header
int main() 
{
	GameEngine game;
	cout << "\tWhat do you want to do now?\n\t\t1) Go exploring\n\t\t2) Veiw the Pokedex\n\t\t3) Veiw your Pokemon\n\t\t4) Veiw your bag\n\t\t5) Quit\n\n\tchoice: ";
	int choice = getInt();
	Explore ex = Explore();
	while (choice != 5) 
	{
		switch (choice) 
		{
		case 1: ex.exploreNow(&game);
			break;
		case 2: game.viewPokedex();
			break;
		case 3: game.viewTeam();
			break;
		case 4: game.viewBag();
			break;
		}
		cout << "\tWhat do you want to do?\n\t\t1) Explore\n\t\t2) Pokedex\n\t\t3) Pokemon\n\t\t4) Bag\n\t\t5) Quit\n\n\tchoice: ";
		choice = getInt();
	}
	cout << "Goodbye!" << endl;
}

void GameEngine::viewTeam()
{
	for(int i = 0; i < 6; i++)
	{
		cout << "Slot " << i << ": " << mainCharacter.getPokemon(i).getName() << endl;
	}
}

void GameEngine::viewPokedex()
{
	for(int i = 0; i < 151; i++)
	{
		cout << i << ": " << mainCharacter.getCurrentPokemon().getPokedexEntry(i, 0) << " of type " << mainCharacter.getCurrentPokemon().getPokedexEntry(i, 3) << endl;
	}
}

void GameEngine::viewBag()
{
	
}

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

GameEngine::GameEngine()
{
	int genderChoice;
	int pokeChoice;
	
	string nameChoice;

	cout << "You wake up dazed and confused in a forest." << endl;
	cout << "There is writing on a tree. You approach and it reads 'Welcome to Kanto.'" << endl;
	cout << "Theres a voice in your head. It says 'What is your name?'\n You respond: ";
	nameChoice = getString();
	cout << "What is your gender?'\n Your gender (1. Female, 2. Male): ";
	genderChoice = getInt();
	mainCharacter = Character(nameChoice, genderChoice);
	cout << "'I see greatness in you, " << mainCharacter.getName() << ". Become the best, and I will speak with you again.'" << endl;
	cout << "The voice disappeared and 3 pokeoballs appeared." << endl;
	cout << "Grab the 1st, 2nd, or 3rd one? " << endl;
	pokeChoice = getInt();
	
	bool valid = false;
	
	do
	{
		switch(pokeChoice)
		{
			case 1:
			{
				mainCharacter.addPokemon(Pokemon(1,0));
				valid = true;
				break;
			}
			case 2:
			{
				mainCharacter.addPokemon(Pokemon(1,1));
				valid = true;
				break;
			}
			case 3:
			{
				mainCharacter.addPokemon(Pokemon(1,2));
				valid = true;
				break;
			}
			default:
			{
				cout << "Invalid choice. Try again: ";
				valid = false;
			}
		
		}
	} while (!valid);
	
	cout << "You got a " << mainCharacter.getPokemon(0).getName() << "!" << endl;
	cout << "The other pokeballs disappeared before you could grab another." << endl;
	cout << "Your " << mainCharacter.getPokemon(0).getName() << " is a pokemon." << endl;
	cout << "Use it to battle other trainers and other wild pokemon." << endl;
	
	/** The map will hold ints and the ints will represent as fallows: 
	* 0: Character
	* 1: wall		Example output: Its a 40 foot tall concrete wall with barbwire on top. aka Trump's wall
	* 2: forest 		Example output: You are in a forest
	* 3: desert		Example output: You are in a desert
	* 4: swamp		Example output: ...
	* 5: town		Example output: You have found (blank) town
	*/
	
	//should be done now
	newmap = new int*[MAP_SIZE];
	
	for(int i = 0; i < MAP_SIZE; i++)
	{
		newmap[i] = new int[MAP_SIZE];
	}
	
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
			newmap[i][j] = FOREST;
		}
	}

	for (int i = 50; i < MAP_SIZE; i++) {
		for (int j = 50; j < MAP_SIZE; j++) {
			newmap[i][j] = DESERT;
		}
	}

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			newmap[i+39][j+39] = FOREST;
		}
	}

	for(int i = 0; i < 100; i++)
	{
		newmap[0][i] = WALL;
		newmap[99][i] = WALL;
		newmap[i][0] = WALL;
		newmap[i][99] = WALL;
	}
	
	//top = north, left = east
	//town 1, smallest
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//top left corner of town is at corordinate (15,15)
			newmap[i + 15][j + 15] = TOWN;
		}
	}
		
	//town 2, smaller
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//top left corner of town is at corordinate (57,57)? i guess, idk, maybe it should be moved
			newmap[i + 57][j + 57] = TOWN;
		}
	}
		
	//town 3, same size as 2
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//top left corner of town is at corordinate (79,20)? i guess, idk, maybe it should be moved
			newmap[i + 79][j + 20] = TOWN;
		}
	}
		
	//town 4, big town
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			//top left corner of town is at corordinate (10,60)? i guess, idk, maybe it should be moved
			newmap[i + 10][j + 60] = TOWN;
		}
	}
	
}

void Explore::exploreNow(GameEngine *g)
{	
	bool hasExit = false;
	
	do
	{
		cout << "Where to? (1 = North, 2 = South, 3 = East, 4 = West, or 5 = exit) ";
		int choice = getInt();
		
		if (choice == 1)
		{
			if(trySpace(g->mainCharacter.xPosition, g->mainCharacter.yPosition - 1, g)) g->mainCharacter.yPosition--;
		}
		else if (choice == 2)
		{
			if(trySpace(g->mainCharacter.xPosition, g->mainCharacter.yPosition + 1, g)) g->mainCharacter.yPosition++;
		}
		else if (choice == 3)
		{
			if(trySpace(g->mainCharacter.xPosition + 1, g->mainCharacter.yPosition, g)) g->mainCharacter.xPosition++;
		}
		else if (choice == 4)
		{
			if(trySpace(g->mainCharacter.xPosition - 1, g->mainCharacter.yPosition, g)) g->mainCharacter.xPosition--;
		}
		else if (choice == 5)
		{
			hasExit = true;
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
		
	} while (!hasExit);
	
}

bool Explore::trySpace(int i, int j, GameEngine *g)
{
	if (i > MAP_SIZE || j > MAP_SIZE)
	{
		cout << "Error: explore.cpp trySpace out of bounds exception " << i << " " << j << " " << MAP_SIZE << endl;
		return false;
	}
	
	//cout << "i: " << i << "   j: " << j << "   mainCharacter name: " << g->mainCharacter.getName() << endl; all of this works and then numbers are what they are supposed to be
	int nextSpace = g->newmap[i][j]; 
	
	switch (nextSpace)
	{
		case WALL:
		{
			foundWall(g);
			return false;
			break;
		}
		case FOREST:
		{
			foundForest(g);
			return true;
			break;
		}
		case DESERT:
		{
			foundDesert(g);
			return true;
			break;
		}
		case SWAMP:
		{
			foundSwamp(g);
			return true;
			break;
		}
		case TOWN:
		{
			foundTown(g);
			return false;
			break;
		}
		default:
		{
			cout << "Error : explore.cpp trySpace mislabled space in map" << endl;
			return false;
			break;
		}
	}
}

void Explore::whatHappened(GameEngine *g)
{
	srand(time(NULL));

	int whatHappened = rand() % 100;
	
	//free steps works as a way to make it more and more likely to be stoped by a trainer or
	//pokemon the more times the player has moved without fighting a player or pokemon
	//we may need to adjust the frequency settings though
	if (whatHappened < (freeSteps*1.7))
	{
		Pokemon joey = Pokemon(g->mainCharacter.getCurrentPokemon().getLevel());
		cout << "A " << joey.getName() << " has appeared from seemingly nowhere to fight!" << endl;
		freeSteps = 0;
		Battle(g->mainCharacter, joey);
	}
	else if (whatHappened > (100 - (freeSteps*1.4)))
	{
		int name = rand() % 20;
		Character joe = Character(people[name], (freeSteps%2) + 1);
		cout << "Trainer " << joe.getName() << " has spotted you! They want to battle!" << endl;
		
		int numberOfPokemon = rand() % 6;
		
		for(int i = 0; i < numberOfPokemon; i++)
		{
			joe.addPokemon(Pokemon(g->mainCharacter.getCurrentPokemon().getLevel()));
		}
		
		freeSteps = 0;
		Battle(g->mainCharacter, joe); 
	}
	else
	{
		freeSteps++;
	}
}

void Explore::foundForest(GameEngine *g)
{
	cout << "You are in a forest." << endl;
	whatHappened(g);
}

void Explore::foundDesert(GameEngine *g)
{
	cout << "You are in a desert." << endl;
	whatHappened(g);
}

void Explore::foundSwamp(GameEngine *g)
{
	cout << "You are in a Swamp." << endl;
	whatHappened(g);
}

void Explore::foundTown(GameEngine *g) 
{
	cout << "You have found a town!" << endl;
	//run town
}

void Explore::foundWall(GameEngine *g)
{
	cout << "You have found a 40 foot wall concrete that is insermountable. The word TRUMP is written on the side.";
}

string Explore::people[20] = {"Alex", "Jack", "Jamie", "Avery", "Blair", "Christian", "Dane", "Fabian", "Glen", "Hayley", 
	"Kerry", "Lonnie", "Montana", "Noel", "Payton", "Quinn", "Rene", "Shay", "Tory", "Whitney"};
