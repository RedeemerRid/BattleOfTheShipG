#pragma once
#include "Player.h"
#include "Human.h"
class Game
{
	int n = 12, m = 32;
	Player* player1;
	Player* player2;
	char** arr1{0};
	char** arr2{0};
	
public:
	
	void set();
	void printGane();
protected:
	void arrangementOfShip();
	void playGame() {
		

	}
	/*
	void AtackShip(int shipLength);
	void AtackPrintScreen(int& y, int& x);
	*/
};

