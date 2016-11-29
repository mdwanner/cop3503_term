#include "gameEngine.h"
#include <string>
#include "Pokemon.h"
/*
I have everything under control as far as generating randomized pokemon with varying stats based on level, and leveling them up based on xp given through battle. There is still a lot to do but here is something i have so far...
*/

//NEED TO SET BADGES TO ZERO IN CONSTRUCOR, NOT IN HEADER FILE.

// this array contains all of the names and types for each pokemon. the evelution will be chosen during construction based on level.
string pokeMen[151][4] = {{"Bulbasaur", "Ivysaur", "Venusaur", "grass"},{"Charmander", "Charmeleon", "Charizard", "fire"},{"Squirtle", "Wartortle",
 "Blastoise", "water"},{"Caterpie", "Metapod", "Butterfree", "bug"},{"Weedle", "Kakuna", "Beedrill", "bug"},{"Pidgey", "Pidgeotto", "Pidgeot",
 "flying"},{"Rattata", "Raticate", "Raticate", "normal"},{"Spearow", "Fearow", "Fearow", "flying"},{"Ekans", "Arbok", "Arbok", "poison"},{"Pikachu",
  "Raichu", "Raichu", "electric"},{"Sandshrew", "Sandslash", "Sandslash", "ground"},{"Nidoran","Nidorina","Nidoqueen","poison"},{"Nidoran","Nidorina",
  "Nidoking","poison"},{"Clefairy","Clefable","Clefable","fairy"},{"Vulpix","Ninetales","Ninetales","fire"},{"Jigglypuff","Wigglytuff","Wigglytuff",
  "fairy"},{"Zubat","Golbat","Golbat","poison"},{"Oddish","Gloom","Vileplume","grass"},{"Paras","Parasect","Parasect","grass"},{"Venonat","Venomoth",
  "Venomoth","bug"},{"Diglet","Dugtrio","Dugtrio","ground"},{"Meowth","Persian","Persian","normal"},{"Psyduck","Golduck","Golduck","water"},{"Mankey",
  "Primeape","Primeape","fighting"},{"Growlithe","Arcanine","Arcanine","fire"},{"Poliwag","Poliwhirl","Poliwrath","water"},{"Abra","Kadabra","Alakazam",
  "psychic"},{"Machop","Machoke","Machomp","fighting"},{"Bellsprout","Weepinbell","Victreebel","grass"},{"Tentacool","Tentacruel","Tentacruel","water"},
  {"Geodude","Graveler","Golem","rock"},{"Ponyta","Rapidash","Rapidash","fire"},{"Slowpoke","Slowbro","Slowbro","psychic"},{"Magnemite","Magneton",
  "Magneton","electric"},{"Farfetch'd","Doduo","Dodrio","flying"},{"Seel","Dewdong","Dewdong","water"},{"Grimer","Mulk","Mulk","poison"},{"Shellder",
  "Cloyster","Cloyster","water"},{"Gastly","Haunter","Gengar","ghost"},{"Onix","Onix","Onix","rock"},{"Drowzee","Hypno","Hypno","psychic"},{"Krabby",
  "Kingler","Kingler","water"},{"Voltorb","Electrode","Electrode","electric"},{"Exeggcute","Exeggutor","Exeggutor","psychic"},{"Cubone","Marowak","Marowak",
  "ground"},{"Hitmonlee","Hitmonchan","Hitmonchan","fighting"},{"Lickitung","Lickiting","Lickitung","normal"},{"Koffing","Weezing","Weezing","poison"},
  {"Rhyhorn","Rhydon","Rhydon","rock"},{"Chansey","Chansey","Chansey","normal"},{"Tangela","Tangela","Tangela","grass"},{"Kangaskhan","Kangaskhan","Kangaskhan",
  "normal"},{"Horsea","Seadra","Seadra","water"},{"Goldeen","Seaking","Seaking","water"},{"Staryu","Starmie","Starmie","water"},{"Mr. Mime"," Mr. Mime"," Mr. Mime"
  ,"psychic"},{"Scyther"," Scyther"," Scyther","bug"},{"Jynx","Jynx","Jynx","psychic"},{"Electabuzz","Electabuzz","Electabuzz","electric"},{"Magmar","Magmar","Magmar",
  "fire"},{"Pinsir","Pinsir","Pinsir","bug"},{"Tauros","Tauros","Tauros","normal"},{"Magikarp","Gyarados","Gyarados","water"},{"Lapras","Lapras","Lapras",
  "water"},{"Ditto","Ditto","Ditto","normal"},{"Eevee","Eevee","Eevee","normal"},{"Porygon","Porygon","Porygon","normal"},{"Omanyte","Omastar","Omastar","water"},
  {"Kabuto","Kabutops","Kabutops","water"},{"Aerodactyl","Aerodactyl","Aerodactyl","rock"},{"Snorlax","Snorlax","Snorlax","normal"},{"Articuno","Articuno",
  "Articuno","ice"},{"Zapdos","Zapdos","Zapdos","electric"},{"Moltres","Moltres","Moltres","fire"},{"Dratini","Dragonair","Dragonite","dragon"},{"Mewtwo",
  "Mewtwo","Mewtwo","psychic"},{"Mew","Mew","Mew","psychic"}};

Pokemon::Pokemon(int level) {

    //names are chosen based on level, so a level one will be squirtle, etc. i haven't yet implemented evelution for EXISTING pokemon on level up.
    this->choice = rand()%151;
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

//overloaded constructor for picking starters or simply creating specific pokemon.
Pokemon::Pokemon(int level, int choice) {

  this->choice = choice;
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
    
    this->health = (level-1)*20 + (rand()%151 + 50);
    this->currentHealth = health;
    this->attack = (level-1)*3 + (rand()%15 + 8);
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

//handles leveling up and evolving
void Pokemon::giveExperience(int exp) {
    if((experience + exp) < (50 + (10*level))) {
        experience = experience + exp;
      cout << "Your " << name << " has gained " << exp << " experience! - exp: " << experience << "/" << (50 + (10*level)) << "." << endl;
    }
    else if(level < 100) {
        experience = 0;
        level += 1;
        health += 20;
        currentHealth += 20;
        attack += 3;
      cout << "Your " << name << " is now level " << level << "! - Health: " << health << " - Attack: " << attack << " - Dodge: " << defense << "." << endl;
      if((level = 34)&&(pokeMen[choice][0]!=pokeMen[choice][1])) {
        cout << "Your " << name << " has evolved into " << pokeMen[choice][1] << "!" << endl;
        name = pokeMen[choice][1];
      }
      if((level = 67)&&(pokeMen[choice][1]!=pokeMen[choice][2])) {
        cout << "Your " << name << " has evolved into " << pokeMen[choice][2] << "!" << endl;
        name = pokeMen[choice][2];
    }
    else {
      cout << "This " << name << " is already maximum level!" << endl;
    }
}
