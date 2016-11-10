#include "gameEngine.h"

// Define functions from header
int main() 
{
	
}

GameEngine()
{
	int genderChoice;
	string nameChoice;

	cout << "Welcome to Pokemon Orange and Blue!" << endl;
	cout << "What is your gender? 1. Female 2. Male" << endl;
	genderChoice = getInt();
	cout << "What is your name: ";
	nameChoice = getString();
	
	mainCharacter = new Character(nameChoice, genderChoice);
	
	
	/** The map will hold ints and the ints will represent as fallows: 
	* 0: wall		Example output: Its a 40 foot tall concrete wall with barbwire on top. aka Trump's wall
	* 1: trainer spot 	Example output: Trainer (blank) wants to battle.
	* 2: tree/cactus	Example output: There is a tree north of you... go north... you hit a tree
	* 3: forest 		Example output: You are in a forest
	* 3: desert		Example output: You are in a desert
	* 4: swamp		Example output: ...
	* 5: town		Example output: You have found (blank) town
	*/
	
	createMap();
	
}

void createMap()
{
	int[][] newmap = int[100][100];
	for(int i = 0; i < 100; i++)
	{
		newmap[0][i] = 0;
		newmap[99][i] = 0;
		newmap[i][0] = 0;
		newmap[i][99] = 0;
	}
	
	//top = north, left = east
	//town 1, smallest
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//top left corner of town is at corordinate (15,15)
			newmap[i + 15][j + 15] = 5;
		}
	}
		
	//town 2, smaller
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//top left corner of town is at corordinate (57,57)? i guess, idk, maybe it should be moved
			newmap[i + 57][j + 57] = 5;
		}
	}
		
	//town 3, same size as 2
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			//top left corner of town is at corordinate (79,20)? i guess, idk, maybe it should be moved
			newmap[i + 79][j + 20] = 5;
		}
	}
		
	//town 4, big town
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			//top left corner of town is at corordinate (10,60)? i guess, idk, maybe it should be moved
			newmap[i + 10][j + 60] = 5;
		}
	}
	
	//need to fill in a lot more here
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
