#pragma once
#include "gameEngine.h"
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <time.h>


class explore
{
public:
	void exploreNow(GameEngine);	//this is just going directly edit main because expoler an game engine are "friends"

private:
	int freeSteps;
	string getString();
	bool trySpace(int, int, GameEngine);
	void foundForest(GameEngine);
	void foundDesert(GameEngine);
	void foundSwamp(GameEngine);
	void foundWall(GameEngine);
	void foundTown(GameEngine);
	void whatHappened(GameEngine);
};
