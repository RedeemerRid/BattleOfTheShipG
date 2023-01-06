#pragma once
#include<iostream>
#include "Player.h"
using namespace std;
class Comp :  public Player
{
	int r = 0, hit=1;
	int direction = 0;
	int qx=0, qy=0, y=0, x=0;
	int n = 12, m = 32;
	int countShipPiece = 0; // количество палуб  при  стройке 
	int ShipPiece = 0; // общее количество подбитых палуб
	int csp = 0; // 'X'
	char** arr{ 0 };
	//char** arrX{ 0 };
	string name;
	string nameUnfinished;
protected:
	void outlineX(int& y, int& x);
	bool shuter(char** arrX, int& y, int& x);
	bool shuterFalse(char** arrX, int& y, int& x);
	bool chekHitShip(char** arrX, int& y, int& x);
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

