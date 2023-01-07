#pragma once
#include<iostream>
class Player
{

	
public:
	//Player() {}
	//virtual ~Player() {};
	//std::string virtual getNameUnifinished() = 0;
	
	//void virtual writeToFile(std::string& nameUnfinishedX)=0;
	//void virtual readFromFile(std::string& nameq) = 0;
	
	void virtual delAll()=0;
	
	void virtual print() = 0;
	
	void virtual ArangmentShip() = 0;
	void virtual setName(std::string& name) = 0;
	std::string virtual getName() = 0;
	char virtual **getArr() = 0;
	
	int virtual getShipPice() = 0;
	
	int virtual AtackShip(char** arrX, const std::string& nameX) = 0;
	void virtual AtackPrintScreen(int& y, int& x) = 0;

};

