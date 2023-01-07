#pragma once
#include<iostream>
#include "Player.h"
#include "Human.h"
#include "Comp.h"
//#include<string>
#include<vector>
class Game
{
	Player* player1;
	Player* player2;
	int n = 12, m = 32;
	int countShipPiece1=0, ShipPiece1=0;
	int countShipPiece2=0, ShipPiece2=0;
	
	char** arr1{ 0 };
	char** arr2{ 0 };
	string name1,  name2;
	string nameUnfinished;
	//vector<string> vgame;
	
	
	
public:
	
	void  delAll();
	void playGame();
	void set(vector<string> &v);
	//void printGame();
protected:
	bool unifinishedSet();
	void base_name();
	void arrangementOfShip();
	
	//void readFromFile();
	
	
	
};

