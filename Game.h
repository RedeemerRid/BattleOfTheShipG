#pragma once
#include "Player.h"
#include "Human.h"
#include<vector>
class Game
{

	int n = 12, m = 32;
	int countShipPiece1;
	int countShipPiece2;
	//char** arr{ 0 };
	char** arr1{ 0 };
	char** arr2{ 0 };
	string name1,  name2;
	string nameUnfinished;
	//vector<string>* v;
	Player* player1;
	Player* player2;
	
	
public:
	Game(){}
	~Game() {	}
	void unfinishedGame();
	bool unifinishedSet();
	void playGame();
	void set(vector<string> &v);
	void printGame();
protected:
	void arrangementOfShip();
	void writeToFile();
	void readFromFile();
	
	int AtackShip(char** arr, const string& name, char** arrX, const string& nameX, int &countShipPiece);
	void AtackPrintScreen(int& y, int& x, char** arr, const string& name, char** arrX, const string& nameX);
	
};

