#include <iostream>
#include<conio.h>
#include<string>
#include "Human.h"
#include "Player.h"
using namespace std;


Human::Human() {
	arr = new char* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[m];
}
Human::~Human() {}
void Human::setName(string name) { this->name = name; }
void Human::FillArr() { // строим массив поле
	
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			if (i == 0 && j < 12)
				arr[i][j] = char(64 + j);
			else if (j > 20 && i == 0)
				arr[i][j] = char(44 + j);
			else if (j == 0 || j == 20)
				arr[i][j] = char(48 + i);
			else {
				if (i == 11 || j == 11 || j == m - 1) {
					if (i == 11)
						arr[i][j] = '-';
					if (j == 11 || j == m - 1)
						arr[i][j] = '|';
					if (j > 11 && j < 21)
						arr[i][j] = ' ';


				}
				else
					arr[i][j] = ' ';
			}
		}
	}
	arr[0][11] = '|';
	arr[0][0] = '#';
	arr[11][0] = '-';
	arr[10][0] = 'X';
	arr[0][m - 1] = '|';
	arr[0][20] = '#';
	arr[10][20] = 'X';
	arr[11][20] = '-';
}


void Human::ArangmentShip() { // cycle along the length of the ship
	
	Human::FillArr();

	int j;
	for (int i = 4; i >= 1; i--) {
		j = 5 - i;
		while (j > 0) {
			Human::FillShipHumanHandle(i);
			j--;
		}
	}
	cout << "FINISH : " << endl;
}
void Human::FillShipHumanHandlePrintScreen(int& y, int& x) { // displays the field and ships on the console //выводит на консоль поле и корабли

	system("CLS");
	cout << name << " Plese Arrange your ships" << endl << endl;
	
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {

			if (i == 0 || j == 0) {
				cout << arr[i][j] << " ";

			}
			if (j == x && i == y && j > 0 && i > 0) {
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
void Human::FillShipHumanHandle(int shipLength) {
	int countShipPiece{ 0 }; // подсчет палуб
	int s = 0; // подсчет кораблей
	char c; // захват enter на клавиатуре
	char q; // захват стрелки на клавиатуре
	int x = 1 + rand() % 10;
	int y = 1 + rand() % 10;
	Human::FillShipHumanHandlePrintScreen(y, x);
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
				if (q == 75 && x > 1) {
					x--;
				}
				// right 77
				if (q == 77 && x < 10) {
					x++;
				}
			}
			else if (arr[y][x] != char(254) && c == 'z' && s < shipLength) {
				arr[y][x] = char(254);
				++s;
				countShipPiece++;
			}
			else if (arr[y][x] == char(254) && c == 'x') {
				arr[y][x] = ' ';
				--s;
				countShipPiece--;
			}
			Human::FillShipHumanHandlePrintScreen(y, x);
		} while (c != 13);

	} while (countShipPiece != shipLength);
	countShipPiece = 0;
}

void Human::print() {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


}

char** Human::getArr() {
	return arr;
}


//------------------------------------------------------------------------


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
				//if (arr[y][x] == )
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