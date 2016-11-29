#include "gameEngine.h"
#include <string>
#include "Pokemon.h"
/*
I have everything under control as far as generating randomized pokemon with varying stats based on level, and leveling them up based on xp given through battle. There is still a lot to do but here is something i have so far...
*/

//NEED TO SET BADGES TO ZERO IN CONSTRUCOR, NOT IN HEADER FILE.

// this array contains all of the names and types for each pokemon. the evelution will be chosen during construction based on level.
// gonna be adding all 150 I suppose since it's pretty easy to add names/types.
string pokeMen[11][4] = {{"Bulbasaur", "Ivysaur", "Venusaur", "grass"},{"Charmander", "Charmeleon", "Charizard", "fire"},{"Squirtle", "Wartortle", "Blastoise", "water"},{"Caterpie", "Metapod", "Butterfree", "bug"},
                            {"Weedle", "Kakuna", "Beedrill", "bug"},{"Pidgey", "Pidgeotto", "Pidgeot", "flying"},{"Rattata", "Raticate", "Raticate", "normal"},{"Spearow", "Fearow", "Fearow", "flying"},{"Ekans", "Arbok", "Arbok", "poison"},
                            {"Pikachu", "Raichu", "Raichu", "electric"},{"Sandshrew", "Sandslash", "Sandslash", "ground"}};

Pokemon::Pokemon(int level) {

    //names are chosen based on level, so a level one will be squirtle, etc. i haven't yet implemented evelution for EXISTING pokemon on level up.
    int choice = rand()%10;
    if(level <= 33) {
        this->name = pokeMen[choice][0];
    }
    else if(level <= 66) {
        this->name = pokeMen[choice][1];
    }
    else {
        this->name = pokeMen[choice][2];
    }
    this->type = pokeMen[choice][3];
    this->experience = 0;
    this->level = level;
    
    //these numbers are obviously subject to change. also we will likely not use rand() in final version since it will create the same pokemon each time the game is run, but that may be useful for debugging
    this->health = (level-1)*20 + (rand()%151 + 50);
    this->currentHealth = health;
    this->attack = (level-1)*3 + (rand()%15 + 8);
    
    //defense is a value from 0-25 and is higher for lower health pokemon. i envisioned it being a chance to dodge (out of 100%) to help buff lower health pokemon.
    this->defense = int((1.0/(health-((level-1)*20)))*1000 + (rand()%10-5));

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
    if((currentHealth + healthChange) < health) {
        currentHealth += healthChange;
    }
    else {
        currentHealth = health;
    }
    if(currentHealth < 0) {
        currentHealth = 0;
    }
}

//this should probably print out some messages when level up happens.
void Pokemon::giveExperience(int exp) {
    if((experience + exp) < (50 + (10*level))) {
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
