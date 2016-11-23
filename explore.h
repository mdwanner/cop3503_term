#pragma once
#include "gameEngine.h"
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <time.h>


class explore
{
public:
	static void exploreNow();	//this is just going directly edit main because expoler an game engine are "friends"

private:
	int freeSteps;
	string getString();
	bool trySpace(int, int);
	void foundForest();
	void foundDesert();
	void foundSwamp();
	void foundTown();
	void foundWall();
	void foundTown();
	void whatHappened();
};
