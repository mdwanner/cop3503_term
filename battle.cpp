#include "battle.h"
#include "Pokemon.h"
//I put these in the header file - joey
//#include <iostream>
//#include <sstream>
//#include <time.h>
//#include <ctime>

using namespace std;

// define functions in header (main() NOT located here)

//todo: INVENTORY SECTION STILL NEEDS CREATION AND IMPLEMENTATION
void Battle::attack(int turns, Character* thePlayer, Character* theEnemyPlayer)
{
	Pokemon currEnemyPok = theEnemyPlayer->getCurrentPokemon();
	Pokemon currMyPok = thePlayer->getCurrentPokemon();
	
	int dodgechance;
	int damage;
	if (turns == 0)
		dodgechance = currMyPok.getDodge();
	else
		dodgechance = currEnemyPok.getDodge();
	srand(time(NULL));
	int dodgeroll = rand() % 100+1;
	if (dodgeroll >= dodgechance) 
	{
		//attack
		if (turns == 0) 
		{
			//Note: attacks have yet to be balanced.
			//mypokemon attacks
			damage = currMyPok.getAttack() * (-0.5);
			//The typeMultiplier represents a double array of gen 1 pokemon type chart multipliers.
			//the pokemon.typenumber
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			
			currEnemyPok.changeCurrentHealth(damage);
			cout << "Your attack was successful!\n";
			theEnemyPlayer->setCurrentPokemon(currEnemyPok);
		}
		else 
		{
			//enemy pokemon attacks
			damage = currEnemyPok.getAttack() * (-0.5);
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			currMyPok.changeCurrentHealth(damage);
			cout << "Their attack was successful!\n";
			thePlayer->setCurrentPokemon(currMyPok);
		}
	}
	else
		//attack missed.
		cout << "The attack missed!\n";
	if (currMyPok.getCurrentHealth() <= 0) 
	{
		//forces a switch of pokemon if pokemon faints.
		cout << "Your pokemon has fainted!" << endl;
		switchPokemon(thePlayer);
	}

	
	if (currEnemyPok.getCurrentHealth() <= 0) {
		cout << "The enemy pokemon has fainted!";
		//todo: make a loop that checks the next healthy pokemon (and maybe battle type).
		switchPokemon(theEnemyPlayer);
	}
	
};

void Battle::attack(int turns, Character* thePlayer, Pokemon* wildPokemon) 
{
	//Pokemon currEnemyPok = wildPokemon;       			<--  Matt: These seem redundant and might be the reason the health isn't changing in battle,
	//Pokemon currMyPok = thePlayer->getCurrentPokemon();        our pointer values were saved into local variables
	int dodgechance;
	int damage;
	if (turns == 0)
		dodgechance = thePlayer->getCurrentPokemon().getDodge();
	else
		dodgechance = wildPokemon->getDodge();
	srand(time(NULL));
	int dodgeroll = rand() % 100+1;
	if (dodgeroll >= dodgechance) 
	{
		//attack
		cout << "Your attack was successful!\n";
		if (turns == 0) 
		{
			//Note: attacks have yet to be balanced.
			//mypokemon attacks
			damage = thePlayer->getCurrentPokemon().getAttack() * (-0.5);
			//The typeMultiplier represents a double array of gen 1 pokemon type chart multipliers.
			//the pokemon.typenumber
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			
			wildPokemon->changeCurrentHealth(damage);
		}
		else 
		{
			//enemy pokemon attacks
			damage = wildPokemon->getAttack() * (-0.5);
			//damage = damage*typeMultiplier[mypokemon.typeNumber][enemypokemon.typeNumber];
			Pokemon temp = thePlayer->getCurrentPokemon();
			temp.changeCurrentHealth(damage);
			thePlayer->setCurrentPokemon(temp);
			if (temp.getCurrentHealth() <= 0)
			switchPokemon(thePlayer);
		}
	}
	else
	{
		//attack missed.
		cout << " The attack missed!\n";
	}
};

Pokemon Battle::switchPokemon(Character* trainer){
	//For forced pokemon switch.

	for (int i = 0; i < 6; i++)
	{
		Pokemon switchPokemon = trainer->getPokemon(i);
		cout <<switchPokemon.getCurrentHealth();
		if (switchPokemon.getCurrentHealth() >= 0 && switchPokemon.getName().compare("Empty") != 0)
		{
			trainer->setCurrentPokemon(i);
			cout << "Switched to " << switchPokemon.getName() << ".\n";
			break;
		}	
	}
	return trainer->getCurrentPokemon();
};

Pokemon Battle::switchPokemon(int numPokemon, Character* trainer){
	//For user choice switch.
	Pokemon currPokemon = trainer->getCurrentPokemon();
	Pokemon switchPokemon = trainer->getPokemon(numPokemon);
	if (switchPokemon.getCurrentHealth() >= 0 && switchPokemon.getName().compare("Empty") != 0)
	{
		trainer->setCurrentPokemon(numPokemon);
		return switchPokemon;
	}
	else 
	{
		cout << "You cannot switch to that pokemon!\n";
			
	}
	return currPokemon;
};

Battle::Battle(Character* player, Pokemon* enemy) 
{
	Pokemon currPokemon = player->getCurrentPokemon();
	int action = 0;
	//turn decides who attacks: 0 = you, 1 = enemy.
	bool turn = 0;
	while (action != 4 && (enemy->getCurrentHealth()>0 && currPokemon.getCurrentHealth()>0)) 
	{
		cout << "\nYou encountered a wild pokemon, what would you like to do?" << endl;
		cout << "\t1) FIGHT\t2) BAG\n\t3) POKEMON\t4) RUN\n\n\tchoice: ";
		action = getInt1();
		switch (action)
		{
		case 1:
			{
				attack(0,player,enemy);
				turn = 1;
				break;
			}
		case 2:
			{
				int bagChoice = 5;//for now but open bag
				int bagOption = 0;
				while (bagChoice > 3 || bagChoice < 1) {
					cout << "You have: \t1) " << player->getPokeBallCount() << " pokeballs\n\t2) " << player->getPotionCount() << " health potions";
					cout << "\n\t3)RETURN\nWhat will you use?\n\t\tchoice: ";
					bagChoice = getInt1();
					if (bagChoice == 1) {
						//use Pokeball
						player->usePokeBall();
					}
					if (bagChoice == 2) {
						//use health potion
						//Matt: I have a function available in the Character class that handles the Potion calculations that
						// we can use:

						//Pokemon temp = player->getCurrentPokemon();
						player->usePotion(&currPokemon);
						player->setCurrentPokemon(currPokemon);
						//currPokemon.changeCurrentHealth(currPokemon.getCurrentHealth()*.3);

						//if (player.potions != 0) {
						//	player.potions--;
						//	currPokemon.changeCurrentHealth(currPokemon.getCurrentHealth() + currPokemon.getHealth()*0.5);
						//	if (currPokemon.getCurrentHealth() > currPokemon.getHealth()) {
						//		//Takes away the extra health if it exceeds maxhealth.
						//		currPokemon.changeCurrentHealth(0 - (currPokemon.getCurrentHealth() - currPokemon.getHealth()));
						//	}
						//}
						//else {
						//	cout << "You have no potions!\n";
						//}
					}
				}
				break;
			}
		case 3:
			{
				int pokeswitch = 0;
				Pokemon beforePokemon = currPokemon;
				while (pokeswitch > 7 || pokeswitch < 1) 
				{
					cout << "Which pokemon would you like to switch to?";
					Pokemon pok1 = player->getPokemon(1);
					cout << "\n\t1)" << pok1.getName();
					Pokemon pok2 = player->getPokemon(2);
					cout << "\t2)" << pok2.getName();
					Pokemon pok3 = player->getPokemon(3);
					cout << "\n\t3)" << pok3.getName();
					Pokemon pok4 = player->getPokemon(4);
					cout << "\t4)" << pok4.getName();
					Pokemon pok5 = player->getPokemon(5);
					cout << "\n\t5)" << pok5.getName();
					Pokemon pok6 = player->getPokemon(6);
					cout << "\t6)" << pok6.getName();
					cout << "\n\t\t7) Exit\n\n\tchoice: ";
					pokeswitch = getInt1();
					switch (pokeswitch) 
					{
						case 1:
							currPokemon = switchPokemon(1,player);
							break;
						case 2:
							currPokemon = switchPokemon(2,player);
							break;
						case 3:
							currPokemon = switchPokemon(3,player);
							break;
						case 4:
							currPokemon = switchPokemon(4,player);
							break;
						case 5:
						currPokemon = switchPokemon(5,player);
						break;
						case 6:
							currPokemon = switchPokemon(6,player);
							break;
					}
					if (pokeswitch > 7 || pokeswitch < 1)
						cout << "Invalid pokemon choice, please try again.\n";
				}
				//if (pokeswitch != 7) turn = 1; (replaced code)
				if (currPokemon.getName() != beforePokemon.getName()) 
				{
					turn = 1;
				}
				break;
			}
		}
		
		if (turn == 1 && enemy->getCurrentHealth() > 0) 
		{
			cout << "The enemy pokemon attacks! ";
			attack(1, player, enemy);
			turn = 0;
		}
		
		currPokemon = player->getCurrentPokemon();

		cout << "Your pokemon has: " << currPokemon.getCurrentHealth() << " hp. ";
		cout << "Enemy pokemon has: " << enemy->getCurrentHealth() << " hp.";

	}
	if (currPokemon.getCurrentHealth() <= 0) 
	{
		cout << "You have lost the battle!\n";
		lostMatch(player);
	}
	else if (enemy->getCurrentHealth() <=0 && action != 4) 
	{
		cout << "You have won the battle!" << endl;
		currPokemon.giveExperience(10);
		currPokemon = player->getCurrentPokemon();
		//award exp.
	}
	else
	{
		cout << "You ran away!" << endl;
	}
}
//Battle for a character essentially does the same thing but you cannot run away nor catch.
Battle::Battle(Character* player, Character* opponent) 
{
	Pokemon currPokemon = player->getCurrentPokemon();
	Pokemon currEnemyPokemon = opponent->getCurrentPokemon();
	int action = 0;
	//turn decides who attacks: 0 = you, 1 = enemy.
	bool turn = 0;
	while (currEnemyPokemon.getCurrentHealth()>0 && currPokemon.getCurrentHealth()>0) 
	{	
		cout << "\nWhat would you like to do?" << endl;
		cout << "\t1) FIGHT\t2) BAG\n\t3) POKEMON\n\n\tchoice: ";
		action = getInt1();
		switch (action) 
		{
		case 1:
			{
				attack(0,player,opponent);
				turn = 1;
				break;
			}
		case 2:
			{
				int bagChoice = 5; //open bag
				int bagOption = 0;
				while (bagChoice > 3 || bagChoice < 1) {
					cout << "You have: \t1) " << player->getPokeBallCount() << " pokeballs\n\t2) " << player->getPotionCount() << " health potions";
					cout << "\n\t3)RETURN\nWhat will you use?\n\n\tchoice: ";
					bagChoice = getInt1();
					if (bagChoice == 1){
						//can't use pokeballs here.
						cout << "You can't catch their pokemon!\n";
						bagOption = 0;
					}
					if (bagChoice == 2){
						//use health potion
						//Matt: I have a function available in the Character class that handles the Potion calculations that
						// we can use:

						
						player->usePotion(&currPokemon);
						player->setCurrentPokemon(currPokemon);
						//if (player.potions != 0) {
						//	player.potions--;
						//	currPokemon.changeCurrentHealth(currPokemon.getCurrentHealth() + currPokemon.getHealth()*0.5);
						//	if (currPokemon.getCurrentHealth() > currPokemon.getHealth()) {
						//		//Takes away the extra health if it exceeds maxhealth.
						//		currPokemon.changeCurrentHealth(0 - (currPokemon.getCurrentHealth() - currPokemon.getHealth()));
						//	}
						//}
						//else {
						//	cout << "You have no potions!\n";
						//}
					}
				}
				break;
			}
		case 3:
			{
				int pokeswitch = 0;
				Pokemon beforePokemon = currPokemon;
				while (pokeswitch > 7 || pokeswitch < 1) {
					cout << "Which pokemon would you like to switch to?";
					Pokemon pok1 = player->getPokemon(1);
					cout << "\n\t1)" << pok1.getName();
					Pokemon pok2 = player->getPokemon(2);
					cout << "\t2)" << pok2.getName();
					Pokemon pok3 = player->getPokemon(3);
					cout << "\n\t3)" << pok3.getName();
					Pokemon pok4 = player->getPokemon(4);
					cout << "\t4)" << pok4.getName();
					Pokemon pok5 = player->getPokemon(5);
					cout << "\n\t5)" << pok5.getName();
					Pokemon pok6 = player->getPokemon(6);
					cout << "\t6)" << pok6.getName();
					cout << "\n\t\t7) Exit\n\n\tchoice: ";
					pokeswitch = getInt1();
					switch (pokeswitch) {
					case 1:
						currPokemon = switchPokemon(1, player);
						break;
					case 2:
						currPokemon = switchPokemon(2, player);
						break;
					case 3:
						currPokemon = switchPokemon(3, player);
						break;
					case 4:
						currPokemon = switchPokemon(4, player);
						break;
					case 5:
						currPokemon = switchPokemon(5, player);
						break;
					case 6:
						currPokemon = switchPokemon(6, player);
						break;
					}
					if (pokeswitch > 7 || pokeswitch < 1)
						cout << "Invalid pokemon choice, please try again.\n";
				}
	
				if (currPokemon.getName() != beforePokemon.getName()) {
					turn = 1;
				}
				break;
			}
		}
		
		currEnemyPokemon = opponent->getCurrentPokemon();
		
		if (turn == 1 && currEnemyPokemon.getCurrentHealth() > 0) 
		{
			cout << "The enemy trainer attacks! " << endl;
			attack(1, player, opponent);
			turn = 0;
		}
		
		currPokemon = player->getCurrentPokemon();
		
		cout << "Your pokemon has " << currPokemon.getCurrentHealth() << " hp. ";
		cout << "The enemy pokemon has " << currEnemyPokemon.getCurrentHealth() << " hp.";
	}
	
	currPokemon = player->getCurrentPokemon();
	if (currPokemon.getCurrentHealth() <= 0) 
	{
		cout << "You have lost the battle! You give your opponent some money.\n";
		player->forfeitCash(300);
		lostMatch(player);
	}

	else if(currEnemyPokemon.getCurrentHealth() <= 0) 
	{
		cout << "You won the battle! Your opponent gives you $300.\n";
		player->addMoney(300);
		//award exp and gold (for trainers).
	}
	
}

void Battle::lostMatch(Character* c)
{
	cout << "You wake up dazed and confused in a forest." << endl;
	cout << "The voice in your head returns. It says 'All is well. Continue your journey.'\n";
	cout << "'Next time, try using a potion.'" << endl;
	cout << "You find yourself where you first woke up. " << endl;
	
	c->setPos(); 
	for (int i = 0; i < 6; ++i) 
	{
		c->party[i].changeCurrentHealth(999999);
		cout << "Your  " << c->party[i].getName() << " has " << c->party[i].getCurrentHealth() << " hp. " << endl;
	}
	c->setCurrentPokemon(0);
}

int getInt1() {
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
