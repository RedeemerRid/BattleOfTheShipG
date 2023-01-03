#pragma once
#include<iostream>
#include "Player.h"
using namespace std;
class Human : public Player
{
	int n = 12, m = 32;
	int countShipPiece = 0;
	int ShipPiece = 0;
	char** arr{ 0 };
	//char** arrX{ 0 };
	string name;
	//string nameUnfinished;
protected:
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
	int getShipPice();
	//void setNameX( string& nameX);
	//void setArrX(char** arrX);
	
	//----
	
	int AtackShip(char** arrX, const string& nameX);
	void AtackPrintScreen(int& y, int& x);
	
};

