#include<iostream>
#include<conio.h>
#include "Game.h"
#include "Player.h"
#include "Human.h"
#include<vector>
using namespace std;

void Game::set(vector<string> &v) {
	//this->v = &v;
	cout << v[0] << v[1] << endl;
	_getch();
	Human human1;
	Human human2;
	player1 = &human1;
	player2 = &human2;
	player1->setName(v[0]);
	player2->setName(v[1]);
	
	arrangementOfShip();
}



void Game::arrangementOfShip() {
	system("cls");

	cout << "Man VS Man" << endl;
	cout << " Player_1 ";
	
	player1->ArangmentShip();
	arr1 = player1->getArr();
	//name1 = player1->getName();
	cout << " thank you, press enter so that another player can arrange their ships" << endl;
	_getch();
	system("cls");
	cout << "Man VS Man" << endl;
	cout << "Player_2 " << endl;
	player2->ArangmentShip();
	arr2 = player2->getArr();
	//name2 = player2->getName();
	cout << " thank you, press enter to continue the game" << endl;
	_getch();
	system("cls");

}

void Game::playGame() {



}



void Game::printGame() {
	
	
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << arr1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}
}

//--------------------------------

