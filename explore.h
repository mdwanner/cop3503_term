#pragma once
#include "gameEngine.h"
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <time.h>


class explore
{
public:
	static Character exploreNow(Character);

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
