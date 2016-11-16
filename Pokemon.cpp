#include <gameEngine.h>
#include <string>

using namespace std;

/*
I have everything under control as far as generating randomized pokemon with varying stats based on level, and leveling them up based on xp given through battle. There is still a lot to do but here is something i have so far...
*/

// this array contains all of the names and types for each pokemon. the evelution will be chosen during construction based on level.
// gonna be adding all 150 I suppose since it's pretty easy.
static const string pokeMen[11][4] = {{"Bulbasaur", "Ivysaur", "Venusaur", "grass"},{"Charmander", "Charmeleon", "Charizard", "fire"},{"Squirtle", "Wartortle", "Blastoise", "water"},{"Caterpie", "Metapod", "Butterfree", "bug"},{"Weedle", "Kakuna", "Beedrill", "bug"},{"Pidgey", "Pidgeotto", "Pidgeot", "flying"},{"Rattata", "Raticate", "Raticate", "normal"},{"Spearow", "Fearow", "Fearow", "flying"},{"Ekans", "Arbok", "Arbok", "poison"},{"Pikachu", "Raichu", "Raichu", "electric"},{"Sandshrew", "Sandslash", "Sandslash", "ground"}};

Pokemon(int level) {

    // name chosen based on level (1-100)
    choice = rand()%10;
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
    
    // health is random between 50-200, plus 20 per level
    this->health = (this.level-1)*20 + (rand()%200 + 50);
    this->currentHealth = this.health;
    //attack is 8-15 plus 3 per level, for now at least
    this->attack = (this.level-1)*3 + (rand()%15 + 8);
    //what i have right now is that defense is a measure of chance to dodge, from 1-100 percent. it is 5-20 based on health, plus or minus 5. it wont change with level, and is designed to even out lower health pokemen. (low health guys have more chance to dodge)
    this->defense = (1/(this.health-((this.level-1)*20)))*1000 + (rand()%10-5);

}

//still have a lot of methods to do obviously
int getHealth(Pokemon) {
    return this.health;
}
