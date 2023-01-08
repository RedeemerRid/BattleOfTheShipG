#pragma once
#include<iostream>
#include "Player.h"
using namespace std;
class Comp :  public Player
{
	int r = 0;
	int hit_target = 1; // 
	int direction = 0;
	int  y=0, x=0;
	int n = 12, m = 32;
	int total_number_hit_deck = 0; // общее количество подбитых палуб
	int number_hit_per_ship = 0; // количество попаданий на один корабль, вы€сн€ю подбит он или нет  //  the number of hits per ship, I find out whether it is hit or not
	char** arr{ 0 };
	string name;
	string nameUnfinished;
protected:
	void outlineX(int& y, int& x);
	bool shuter(char** arrX, int& y, int& x);
	void shuterFalse(char** arrX, int& y, int& x);
	bool chekHitShip(char** arrX, int& y, int& x);
	int rrand();
	//string base_name(string const& path);
	void FillArr();
	void freeArr();
	

	bool correctPlaceShip();

	//void writeToFile(string& nameUnfinishedX);
	//void readFromFile( string& nameq);


public:
	Comp();
	~Comp();
	void setName(string& name);
	string getNameUnifinished();

	void  delAll();
	void print();
	void ArangmentShip();
	string getName();
	char** getArr();
	int getTotal_number_hit_deck();
	

	int AtackShip(char** arrX, const string& nameX);
	void AtackPrintScreen(int& y, int& x);

};

