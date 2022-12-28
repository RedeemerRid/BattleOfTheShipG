#include<iostream>
#include<conio.h>
#include "Game.h"
#include "Player.h"
#include "Human.h"
using namespace std;

void Game::set() {
	Human human1;
	Human human2;
	player1 = &human1;
	player2 = &human2;
	arrangementOfShip();
}
void Game::arrangementOfShip() {
	system("cls");
	cout << "Man VS Man" << endl;
	cout << " Player_1 ";
	
	player1->ArangmentShip();
	cout << " thank you, press enter so that another player can arrange their ships" << endl;
	_getch();
	system("cls");
	cout << "Man VS Man" << endl;
	cout << "Player_2 " << endl;
	player2->ArangmentShip();
	cout << " thank you, press enter to continue the game" << endl;
	_getch();


}