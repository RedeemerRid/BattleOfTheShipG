#pragma once
#include<iostream>
class Player
{
		
public:
	
	void virtual print() = 0;
	//void virtual FillArr()=0;
	void virtual ArangmentShip() = 0;
	std::string virtual getName() = 0;
	char virtual **getArr() = 0;
};

