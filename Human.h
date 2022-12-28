#pragma once
#include<iostream>
#include "Player.h"
using namespace std;
class Human : public Player
{
	int n = 12, m = 32;
	char** arr{ 0 };
	string name;
protected:
	void FillArr();
	void FillShipHumanHandle(int shipLength);
	void FillShipHumanHandlePrintScreen(int& y, int& x);
	void setName();
public:
	Human();
	~Human();
	void print();
	
	void ArangmentShip();
	
	string getName();

};

