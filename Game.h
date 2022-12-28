#pragma once
#include "Player.h"
#include "Human.h"
#include<vector>
class Game
{
	int n = 12, m = 32;
	char** arr1{ 0 };
	char** arr2{ 0 };
	//string name1,  name2;
	//vector<string>* v;
	Player* player1;
	Player* player2;
	
	
public:
	
	void set(vector<string> &v);
	void printGame();
protected:
	void arrangementOfShip();
	void playGame(); 
	
	
	
};

