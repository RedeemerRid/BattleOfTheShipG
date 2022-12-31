#include <iostream>
#include<conio.h>
#include<string>
#include "Human.h"
#include "Player.h"
using namespace std;


Human::Human() {
	Human::freeArr();
}
Human::~Human() {
	
}

void  Human::delAll() {
	if (arr!=nullptr) {
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	}

}

void Human::freeArr() {
	arr = new char* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[m];
}
void Human::setName(string name) { this->name = name; }
string Human::getName() { return name; }
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
	bool correct = false;
	do {
		int j{ 0 };
		for (int i = 4; i >= 1; i--) {
			j = 5 - i;
			while (j > 0) {
				Human::FillShipHumanHandle(i);
				j--;
			}
		}

		if (correct == Human::correctPlaceShip()) {
			_getch();
			delAll();
			Human::freeArr();
			Human::FillArr();
		}
		else
			correct = true;
		
	}while(correct==false);
	_getch();
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

bool Human::correctPlaceShip() {

	int s1 = 0;
	int  s2 = 0, s21 = 0, s22 = 0;
	int  s3 = 0, s31 = 0, s32 = 0;
	int  s4 = 0, s41 = 0, s42 = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (arr[i][j] == char(254)) {
				if (arr[i - 1][j - 1] != char(254) && arr[i - 1][j] != char(254) && arr[i - 1][j + 1] != char(254) && arr[i][j + 1] != char(254) && arr[i + 1][j + 1] != char(254) && arr[i + 1][j] != char(254) && arr[i + 1][j - 1] != char(254) && arr[i][j - 1] != char(254)) {
					s1++;
				}
			}
		}

	}

	if (s1 != 4) {
		cout << "The ships are not positioned correctly. 1-deck " << endl;
		return false;
	}
	else {

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (arr[i][j] == char(254) && arr[i][j + 1] == char(254)) {
					if (arr[i - 1][j - 1] != char(254) && arr[i - 1][j] != char(254) && arr[i - 1][j + 1] != char(254) && arr[i - 1][j + 2] != char(254) && arr[i][j + 2] != char(254) && arr[i + 1][j + 2] != char(254) && arr[i + 1][j + 1] != char(254) && arr[i + 1][j] != char(254) && arr[i + 1][j - 1] != char(254) && arr[i][j - 1] != char(254))
						s21++;
				}
			}
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n - 1; j++)
			{
				if (arr[j][i] == char(254) && arr[j + 1][i] == char(254)) {
					if (arr[j - 1][i - 1] != char(254) && arr[j - 1][i] != char(254) && arr[j - 1][i + 1] != char(254) && arr[j][i + 1] != char(254) && arr[j + 1][i + 1] != char(254) && arr[j + 2][i + 1] != char(254) && arr[j + 2][i] != char(254) && arr[j + 2][i - 1] != char(254) && arr[j + 1][i - 1] != char(254) && arr[j][i - 1] != char(254))
						s22++;
				}
			}
		}
		s2 = s21 + s22;
		if (s2 != 3) {
			cout << "The ships are not positioned correctly. 2-deck " << endl;
			return false;
		}
		else {

			int t31 = 0;
			for (int i = 1; i < n; i++)
			{
				for (int j = 1; j < m - 3; j++)
				{
					t31 = 0;
					if (arr[i][j] == char(254) && arr[i][j + 1] == char(254) && arr[i][j + 2] == char(254)) {
						//cout << arr[i][0] << arr[0][j] << endl;
						if (arr[i][j - 1] != char(254) && arr[i][j + 3] != char(254)) {
							int l = -1;
							t31++;
							while (l < 2) {
								for (int k = -1; k < 4; k++) {
									if (arr[i + l][j + k] != char(254))
										t31++;
								}
								l = l + 2;
							}
						}
						if (t31 == 11)
							s31++;
					}
				}
			}

			int t32 = 0;
			for (int i = 1; i < m; i++)
			{

				for (int j = 1; j < n - 3; j++)
				{
					t32 = 0;
					if (arr[j][i] == char(254) && arr[j + 1][i] == char(254) && arr[j + 2][i] == char(254)) {

						if (arr[j - 1][i] != char(254) && arr[j + 3][i] != char(254)) {
							//cout << arr[0][i] << arr[j][0] << endl;
							int l = -1;
							t32++;
							while (l < 2) {
								for (int k = -1; k < 4; k++) {
									if (arr[j + k][i + l] != char(254))
										t32++;
								}
								l = l + 2;
							}
						}
						if (t32 == 11) {
							s32++;
						}
					}

				}


			}
			s3 = s31 + s32;
			if (s3 != 2) {
				cout << "The ships are not positioned correctly. 3-deck " << endl;
				return false;
			}
			else {
				int t41 = 0;
				for (int i = 1; i < n; i++)
				{
					for (int j = 1; j < m - 3; j++)
					{
						t41 = 0;
						if (arr[i][j] == char(254) && arr[i][j + 1] == char(254) && arr[i][j + 2] == char(254) && arr[i][j + 3] == char(254)) {
							//cout << arr[i][j] << arr[i][j] << endl;
							if (arr[i][j - 1] != char(254) && arr[i][j + 4] != char(254)) {
								int l = -1;
								t41++;
								while (l < 2) {
									for (int k = -1; k < 5; k++) {
										if (arr[i + l][j + k] != char(254))
											t41++;
									}
									l = l + 2;
								}
							}
							if (t41 == 13)
								s41++;
						}
					}
				}

				int t42 = 0;
				for (int i = 1; i < m; i++)
				{

					for (int j = 1; j < n - 3; j++)
					{
						t42 = 0;
						if (arr[j][i] == char(254) && arr[j + 1][i] == char(254) && arr[j + 2][i] == char(254) && arr[j + 3][i] == char(254)) {
							//cout << arr[0][i] << arr[j][0] << endl;
							if (arr[j - 1][i] != char(254) && arr[j + 4][i] != char(254)) {
								int l = -1;
								t42++;
								while (l < 2) {
									for (int k = -1; k < 5; k++) {
										if (arr[j + k][i + l] != char(254))
											t42++;
									}
									l = l + 2;
								}
							}
							if (t42 == 13) {
								s42++;
							}
						}

					}


				}
				s4 = s41 + s42;
				if (s4 != 1) {
					cout << "The ships are not positioned correctly. 4-deck " << endl;
					return false;
				}
				else {
					cout << "The ships are positioned correctly. Perfect " << endl;
					return true;
				}

			}
		}
	}
}
	





