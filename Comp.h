#pragma once
#include<iostream>
#include "Player.h"
using namespace std;
class Comp :  public Player
{
	int n = 12, m = 32;
	int countShipPiece = 0;
	int ShipPiece = 0;
	char** arr{ 0 };
	//char** arrX{ 0 };
	string name;
	string nameUnfinished;
protected:
	int rrand();
	//string base_name(string const& path);
	void FillArr();
	void freeArr();
	//void ArangmentShip();
	//void FillShipHumanHandlePrintScreen(int& y, int& x);

	//bool correctPlaceShip();

	//void writeToFile(string& nameUnfinishedX);
	//void readFromFile( string& nameq);


public:
	Comp();
	~Comp();
	void setName(string& name);
	string getNameUnifinished();

	void  delAll();
	void print();
	void ArangmentShip() override;
	string getName();
	char** getArr();
	int getShipPice();
	//void setNameX( string& nameX);
	//void setArrX(char** arrX);

	//----

	int AtackShip(char** arrX, const string& nameX);
	void AtackPrintScreen(int& y, int& x);

};

