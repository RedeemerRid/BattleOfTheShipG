#pragma once
#include<iostream>
#include "Player.h"
#include "Human.h"
#include<vector>
class Game
{
	Player* player1;
	Player* player2;
	int n = 12, m = 32;
	int countShipPiece1=0, ShipPiece1=0;
	int countShipPiece2=0, ShipPiece2=0;
	//char** arr{ 0 };
	char** arr1{ 0 };
	char** arr2{ 0 };
	string name1,  name2;
	string nameUnfinished;
	vector<string> vgame;
	
	
	
public:
	//void writeToFile();
	void  delAll();
	//void unfinishedGame();
	bool unifinishedSet();
	void playGame();
	void set(vector<string> &v);
	void printGame();
protected:
	void base_name();
	void arrangementOfShip();
	
	//void readFromFile();
	
	//int AtackShip(char** arr, const string& name, char** arrX, const string& nameX, int &countShipPiece);
	//void AtackPrintScreen(int& y, int& x, char** arr, const string& name, char** arrX, const string& nameX);
	
};

