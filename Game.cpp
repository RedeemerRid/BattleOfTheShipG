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
	arr1 = player1->getArr();
	cout << " thank you, press enter so that another player can arrange their ships" << endl;
	_getch();
	system("cls");
	cout << "Man VS Man" << endl;
	cout << "Player_2 " << endl;
	player2->ArangmentShip();
	arr2 = player2->getArr();
	cout << " thank you, press enter to continue the game" << endl;
	_getch();
	system("cls");




}

void Game::printGane() {
	
	
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
/*
void Human::AtackPrintScreen(int& y, int& x) { // displays the field and ships on the console //выводит на консоль поле и корабли

	system("CLS");
	cout << name << " Guess where the boat is " << endl << endl;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {

			if (i == 0 || j == 0) {
				cout << arr[i][j] << " ";

			}
			if (j == x && i == y && j > 20 && i > 0) {
				if (arr[i][j] != char(254))
					cout << "+" << " ";
				else
					cout << arr[i][j] << " ";
			}
			else if (i > 0 && j > 0) {
				if (i == 11 || j == 11 || j == 31) {
					cout << arr[i][j] << " ";

				}
				else if (arr[i][j] != char(254) && (j < 12 || (j > 20 && j < m - 1))) {
					cout << char(250) << " ";
				}
				else
					cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
}
void Human::AtackShip(int shipLength) {
	int countShipPiece{ 0 }; // подсчет палуб
	int s = 0; // подсчет кораблей
	char c; // захват enter на клавиатуре
	char q; // захват стрелки на клавиатуре
	int x = 21 + rand() % 10;
	int y = 1 + rand() % 10;
	Human::AtackPrintScreen(y, x);
	do {
		do {
			c = _getch();
			if (c == -32) {
				q = _getch();
				// up 72
				if (q == 72 && y > 1) {
					y--;
				}
				// doarrn 80
				if (q == 80 && y < 10) {
					y++;
				}
				// left 75
				if (q == 75 && x > 21) {
					x--;
				}
				// right 77
				if (q == 77 && x < 30) {
					x++;
				}
			}
			else if (arr[y][x] != char(254) && c == 'z' && s < shipLength) {
				if(arr[y][x] ==  )
				arr[y][x] = char(254);
				++s;
				countShipPiece++;
			}
			else if (arr[y][x] == char(254) && c == 'x') {
				arr[y][x] = ' ';
				--s;
				countShipPiece--;
			}
			Human::AtackPrintScreen(y, x);
		} while (c != 13);

	} while (countShipPiece != shipLength);
	countShipPiece = 0;
}
*/