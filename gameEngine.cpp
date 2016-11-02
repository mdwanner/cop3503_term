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