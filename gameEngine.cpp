#include "gameEngine.h"
#include "explore.h"


// Define functions from header
int main() 
{
	GameEngine game = new GameEngine();
	cout << "\tWhat do you want to do?\n\t\t1) Explore\n\t\t2) Pokedex\n\t\t3) Pokemon\n\t\t4) Bag\n\t\t5) Quit\n\n\tchoice: ";
	int choice = getInt();
	while (choice != 5) 
	{
		switch (choice) 
		{
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

GameEngine()
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
	
	if(ans.compare("No") == 0 || ans.compare("NO") == 0 || ans.compare("no") == 0)
	{
		cout << "Okay, then I will fill you in. ";
	}
	else if(ans.compare("YES") == 0 || ans.compare("Yes") == 0 || ans.compare("yes") == 0)
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
	* 0: Character
	* 1: wall		Example output: Its a 40 foot tall concrete wall with barbwire on top. aka Trump's wall
	* 2: forest 		Example output: You are in a forest
	* 3: desert		Example output: You are in a desert
	* 4: swamp		Example output: ...
	* 5: town		Example output: You have found (blank) town
	*/
	
	//should be done now
	createMap();
	
}

void createMap()
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
			newmap[i+39][j+39] = FOREST;
		}
	}


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
