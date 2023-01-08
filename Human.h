#pragma once
#include<iostream>
#include "Player.h"
using namespace std;
class Human : public Player
{
	int n = 12, m = 32;
	int number_hit_per_ship = 0;
	
	int countShipPiece = 0;
	int total_number_hit_deck = 0;
	char** arr{ 0 };
	string name;
	string nameUnfinished;
protected:
	bool chekHitShip(char** arrX, int& y, int& x);
	//string base_name(string const& path);
	void FillArr();
	void freeArr();
	void FillShipHumanHandle(int &shipLength);
	void FillShipHumanHandlePrintScreen(int& y, int& x);
	
	bool correctPlaceShip();

	//void writeToFile(string& nameUnfinishedX);
	//void readFromFile( string& nameq);


public:
	Human();
	~Human();
	void setName(string& name);
	string getNameUnifinished();
	
	void  delAll();
	void print();
	void ArangmentShip();
	string getName();
	char** getArr();
	int getTotal_number_hit_deck();
	//void setNameX( string& nameX);
	//void setArrX(char** arrX);
	
	//----
	
	int AtackShip(char** arrX, const string& nameX);
	void AtackPrintScreen(int& y, int& x);
	
};

