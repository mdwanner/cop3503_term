#include "explore.h"

void explore::exploreNow(GameEngine g)
{	
	bool hasExit = false;
	
	do
	{
		cout << "Where to? (North, South, East, West, or exit)";
		string choice = getString();

		for (int i = 0; i < choice.size(); i++)
		{
			choice.at(i) = toupper(choice.at(i));
		}

		if (choice.compare("NORTH") == 0)
		{
			if(trySpace(g.mainCharacter.xPosition, g.mainCharacter.yPosition + 1, g)) g.mainCharacter.yPosition++;
		}
		else if (choice.compare("EAST") == 0)
		{
			if(trySpace(g.mainCharacter.xPosition + 1, g.mainCharacter.yPosition, g)) g.mainCharacter.xPosition++;
		}
		else if (choice.compare("WEST") == 0)
		{
			if(trySpace(g.mainCharacter.xPosition - 1, g.mainCharacter.yPosition, g)) g.mainCharacter.xPosition--;
		}
		else if (choice.compare("SOUTH") == 0)
		{
			if(trySpace(g.mainCharacter.xPosition, g.mainCharacter.yPosition - 1, g)) g.mainCharacter.yPosition--;
		}
		else if (choice.compare("EXIT") == 0)
		{
			hasExit = true;
		}
		else
		{
			cout << "Invalid Input" << endl;
		}
		
	} while (!hasExit);
	
}

bool explore::trySpace(int i, int j, GameEngine g)
{
	if (i > MAP_SIZE || j > MAP_SIZE)
	{
		cout << "Error: explore.cpp trySpace out of bounds exception" << endl;
		return false;
	}

	int nextSpace = g.newmap[i][j];

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
		}
	}
}

void explore::whatHappened(GameEngine g)
{
	srand(time(NULL));

	int whatHappened = rand % 100;
	
	//free steps works as a way to make it more and more likely to be stoped by a trainer or
	//pokemon the more times the player has moved without fighting a player or pokemon
	//we may need to adjust the frequency settings though
	if (whatHappened < freeSteps)
	{
		cout << "A pokemon has appeared from seemingly nowhere to fight!" << endl;
		freeSteps = 0;
		g.mainCharacter;// = /*battle wild*/(g.mainCharacter);
	}
	else if (whatHappened > (100 - freeSteps/2))
	{
		cout << "A trainer has spotted you! They want to battle!" << endl;
		freeSteps = 0;
		g.mainCharacter; //= /*battle trainer*/(g.mainCharacter);
	}
	else
	{
		freeSteps++;
	}
}

void explore::foundForest(GameEngine g)
{
	cout << "You are in a forest." << endl;
	whatHappened(g);
}

void explore::foundDesert(GameEngine g)
{
	cout << "You are in a desert." << endl;
	whatHappened(g);
}

void explore::foundSwamp(GameEngine g)
{
	cout << "You are in a Swamp." << endl;
	whatHappened(g);
}

void explore::foundTown(GameEngine g) 
{
	cout << "You have found a town!" << endl;
	//run town
}

void explore::foundWall(GameEngine g)
{
	cout << "You have found a 40 foot wall concrete that is insermountable. The word TRUMP is written on the side.";
}

string explore::getString()
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
