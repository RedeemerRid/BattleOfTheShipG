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
	name1 = player1->getName();
	cout << " thank you, press enter so that another player can arrange their ships" << endl;
	_getch();
	system("cls");
	cout << "Man VS Man" << endl;
	cout << "Player_2 " << endl;
	player2->ArangmentShip();
	arr2 = player2->getArr();
	name2 = player2->getName();
	cout << " thank you, press enter to continue the game" << endl;
	_getch();
	system("cls");

}

void Game::playGame() {
	int countShipPiece1{ 0 };
	int countShipPiece2{ 0 };
	int hit1= 1;
	int hit2 = 1;
	do{
		char q=' ';
		if (countShipPiece2 < 20) {
			do {
				hit1 = 1;
				cout << name1 << " - Player 1 attack " << endl << endl;
				//name = name1;
				//arr = arr1;
				hit1 = Game::AtackShip(arr1, name1, arr2, name2, countShipPiece1);
			} while (hit1);
			do {
				if (countShipPiece1 < 20) {
					cout << "The player 1 - " << name1 << " - missed, the move is up to the player 2 - " << name2 << endl;
					cout << endl << endl << endl;
					cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl;
					q = _getch();
					system("cls");
				}
			} while (q != 13);
		}
		if (countShipPiece1 < 20) {
			do {
				hit2 = 1;
				cout << name2 << " - Player 2 attack " << endl << endl;
				//name = name2;
				//arr = arr2;
				hit2 = Game::AtackShip(arr2, name2, arr1, name1, countShipPiece2);
			} while (hit2);

			do {
				if (countShipPiece2 < 20) {
					cout << "The player 2 - " << name2 << " - missed, the move is up to the player 1 - " << name1 << endl;
					cout << endl << endl << endl;
					cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl;
					q = _getch();
					system("cls");
				}
			} while (q != 13);
		}
	} while (countShipPiece1 < 20 && countShipPiece2 < 20);
	system("cls");
	if (countShipPiece1 ==20)
		cout << "win player1 " << name1 << endl;
	else if (countShipPiece2 ==20)
		cout << "win player 2 " << name2 << endl;
	else
		cout << "confuse  " << endl;

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


void Game::AtackPrintScreen(int& y, int& x, char** arr, const string& name, char** arrX, const string& nameX) { // displays the field and ships on the console //выводит на консоль поле и корабли

	system("CLS");
	cout << name << " Guess where the boat is " << endl << endl;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {

			if (i == 0 || j == 0) {
				cout << arr[i][j] << " ";

			}
			if (j == x && i == y && j > 20 && i > 0) {
				if (arr[i][j] != char(254) && arr[i][j]!='*')
					cout << "+" << " ";
				else
					cout << arr[i][j] << " ";
			}
			else if (i > 0 && j > 0) {
				if (i == 11 || j == 11 || j == 31) {
					cout << arr[i][j] << " ";

				}
				else if (arr[i][j] != char(254) && arr[i][j] != '*' && arr[i][j] != char(253) && arr[i][j] != 'X' && (j < 12 || (j > 20  && j < m - 1))) {
					cout << char(250) << " ";
				}
				else
					cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
}
int Game::AtackShip(char** arr, const string &name, char** arrX, const string& nameX, int &countShipPiece) {
	int hit = 1;
	//int countShipPiece{ 0 }; // подсчет палуб
	int s = 0; // подсчет кораблей
	char c; // захват enter на клавиатуре
	char q; // захват стрелки на клавиатуре
	int x = 21;
	int y = 1;
	Game::AtackPrintScreen(y, x, arr, name, arrX, nameX);
	do {
		
		//do {
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
			else if (arr[y][x] != char(254) && arr[y][x] != '*' && arr[y][x] != char(253) && arr[y][x] != 'X' && c == 'z') {
				if (arrX[y][x - 20] == char(254)) {
					arr[y][x] = arrX[y][x-20];
					arrX[y][x - 20] = 'X';
					countShipPiece++;
					
				}
				else {
					arr[y][x] = char(253);
					cout << "LOOOOOOSEr";
					hit = 0;
					
				}
				
			}
			else if (arr[y][x] != char(254) && arr[y][x] != char(253) && arr[y][x] != 'X' && c == 'x') {
				arr[y][x] = '*';
				
				
			}
			else if (arr[y][x] == '*' && c == 'c') {
				arr[y][x] = ' ';
				
			}

			Game::AtackPrintScreen(y, x, arr, name, arrX, nameX);
		//} while (c != 13);
			

	} while (hit);
	
	return hit;
}