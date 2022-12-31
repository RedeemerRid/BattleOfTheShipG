#include<iostream>
#include<string>
#include<fstream>
#include <windows.h>
#include <cstdio> 
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

bool Game::unifinishedSet() {
	
	string txt = "unfinishedGame\\player.dat";
	
	ifstream iff(txt);
	if (!iff.is_open()) {
		
			return false;
	}
	else{
		arr1 = new char* [n];
		for (int i = 0; i < n; i++)
			arr1[i] = new char[m];
		arr2 = new char* [n];
		for (int i = 0; i < n; i++)
			arr2[i] = new char[m];
		
		readFromFile();
		
		printGame();
		_getch();
		return true;
	}
	
		
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
	
		
	
	//cout << "The player - " << name1 << " - will be walking now " << endl;
	//_getch();
	//int countShipPiece1{ 0 };
	//int countShipPiece2{ 0 };
	int hit1= 1;
	int hit2 = 1;
	
	do{
		char q=' ';
		if (nameUnfinished != name2) {
			if (countShipPiece2 < 20) {
				do {
					hit1 = 1;
					cout << name1 << " -  attack " << endl << endl;
					nameUnfinished = name1;
					
					hit1 = Game::AtackShip(arr1, name1, arr2, name2, countShipPiece1);
					
				} while (hit1);
				do {
					nameUnfinished = name2;
					
					if (countShipPiece1 < 20) {
						cout << "The player  - " << name1 << " - missed, the move is up to the player 2 - " << name2 << endl;
						cout << endl << endl << endl;
						cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl;
						q = _getch();

						system("cls");
					}
				} while (q != 13);
			}
			Game::writeToFile();
		}
		
		if (countShipPiece1 < 20) {
			do {
				hit2 = 1;
				cout << name2 << " -  attack " << endl << endl;
				nameUnfinished = name2;
				
				hit2 = Game::AtackShip(arr2, name2, arr1, name1, countShipPiece2);
				
			} while (hit2);
			do {
				nameUnfinished = name1;
				
				if (countShipPiece2 < 20) {
					cout << "The player - " << name2 << " - missed, the move is up to the player 1 - " << name1 << endl;
					cout << endl << endl << endl;
					cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl;
					q = _getch();
					
				}
			} while (q != 13);
		}
		Game::writeToFile();
		
	} while (countShipPiece1 < 20 && countShipPiece2 < 20);
	system("cls");
	do {
		if (countShipPiece1 == 20)
			cout << "win player /n/n/n press enter " << name1 << endl;

	    else if (countShipPiece2 ==20)
		    cout << "win player /n/n/n press enter " << name2 << endl;
	    else
		    cout << "confuse  ups " << endl;

		string txt = "unfinishedGame\\player.dat";
		remove(txt.c_str());



	} while (_getch() != 13);
	system("cls");
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


void Game::AtackPrintScreen(int& y, int& x, char** arr, const string& name, char** arrX, const string& nameX) { // displays the field and ships on the console //������� �� ������� ���� � �������

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
	//int countShipPiece{ 0 }; // ������� �����
	int s = 0; // ������� ��������
	char c; // ������ enter �� ����������
	char q; // ������ ������� �� ����������
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

void Game::writeToFile() {
	string s1 = to_string(countShipPiece1);
	string s2 = to_string(countShipPiece2);

	
	string txt = "unfinishedGame\\player.dat";
	FILE* f;

	fopen_s(&f,txt.c_str(), "wb");
	
	for (int i = 0; i < s1.size(); i++)
		fputc(s1.c_str()[i], f);
	fputc('\n', f);
	for (int i = 0; i < s2.size(); i++)
		fputc(s2.c_str()[i], f);
	fputc('\n', f);
	for (int i = 0; i < txt.size(); i++)
		fputc(nameUnfinished.c_str()[i], f);
	fputc('\n', f);
	for (int i = 0; i < txt.size(); i++)
		fputc(name1.c_str()[i], f);
	fputc('\n', f);
	for (int i = 0; i < txt.size(); i++)
		fputc(name2.c_str()[i], f);
	fputc('\n', f);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fputc(arr1[i][j], f);
		}
		fputc('\n', f);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fputc(arr2[i][j], f);
		}
		fputc('\n', f);
	}
	fclose(f);
}

void Game::readFromFile() {
	char uF[31];
	char n1[31];
	char n2[31];
	char ss1[2];
	char ss2[2];
	string txt = "unfinishedGame\\player.dat";
	char c = ' ';
	FILE* ff;

	fopen_s(&ff, txt.c_str(), "rb");
	c = getc(ff);
	int i = 0;
	while (c != '\n') {
		ss1[i] = c;
		c = getc(ff);
		i++;
	}
	c = getc(ff);
	i = 0;
	while (c != '\n') {
		ss2[i] = c;
		c = getc(ff);
		i++;
	}

	c = getc(ff);
	i = 0;
	while (c != '\n') {
		uF[i] = c;
		c = getc(ff);
		i++;
	}
	c = getc(ff);
	i = 0;
	while (c != '\n') {
		n1[i] = c;
		c = getc(ff);
		i++;
	}
	c = getc(ff);
	i = 0;
	while (c != '\n') {
		n2[i] = c;
		c = getc(ff);
		i++;
	}

	for (int i = 0; i < n; i++) {
		c = getc(ff);
		int j = 0;
		while (c != '\n') {
			arr1[i][j] = c;
			c = getc(ff);
			j++;
		}

	}
	for (int i = 0; i < n; i++) {
		c = getc(ff);
		int j = 0;
		while (c != '\n') {
			arr2[i][j] = c;
			c = getc(ff);
			j++;
		}

	}
	fclose(ff);
	name1 = n1;
	name2 = n2;
	nameUnfinished = uF;
	countShipPiece1 = stoi(ss1);
	countShipPiece2 = stoi(ss2);
}

void Game::unfinishedGame() {
	

}