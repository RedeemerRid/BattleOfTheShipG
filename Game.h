#pragma once
#include "Player.h"
#include "Human.h"
class Game
{
	Player* player1;
	Player* player2;

public:
	void set();
protected:
	void arrangementOfShip();
};

