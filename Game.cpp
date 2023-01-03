#include<iostream>
//#include <stdio.h>
//#include<string>
#include<fstream>
//#include <windows.h>
//#include <cstdio> 
#include<conio.h>
#include "Game.h"
#include "Player.h"
#include "Human.h"
#include<vector>
#include<filesystem>
using namespace std;
namespace fs = filesystem;
void  Game::delAll() {
	
	countShipPiece1 = 0; 
	ShipPiece1 = 0;
	countShipPiece2 = 0;
	ShipPiece2 = 0;
	name1.erase();
	name2.erase();
	nameUnfinished.erase();
	//vgame.clear();

}

void Game::set(vector<string> &v) {
	cout << "set" << endl;
	Human human1;
	Human human2;
	player1 = &human1;
	player2 = &human2;
	
	name1 = v[0];
	name2 = v[1];
	player1->setName(name1);
	player2->setName(name2);
	//player1->setNameX(name2);
	//player2->setNameX(name1);
	
	Game::arrangementOfShip();
	Game::playGame();
	v.clear();
	player1->delAll();
	player2->delAll();
	

}
/*
bool Game::unifinishedSet() {
	string txt = "C:\\Windows\\Temp\\111\\";
	fs::path path(txt);
	if (!fs::is_directory(path)) {
		cout << "non directiry" << endl;
		_getch();
	}
	else {
		if (fs::is_empty(path)) {
			cout << " directory empty" << endl;
			_getch();
			return false;
		}
		else {

			Game::base_name();
			char q;

			string txt1 = "C:\\Windows\\Temp\\111\\" + vgame[0] + ".txt";
			string txt2 = "C:\\Windows\\Temp\\111\\" + vgame[1] + ".txt";

			ifstream iff1(txt1);
			ifstream iff2(txt2);
			if (!iff2.is_open() || !iff1.is_open()) {
				cout << "false" << endl;
				_getch();
				return false;
			}
			else {

				do {

					cout << " You have an unfinished game. Do you want to continue " << endl;
					cout << " n - not continue. new game. \ny - continue " << endl;
					cout << "enter word : ";
					q = _getch();

					if (q == 'y' || q == 'Y') {



						Human human1;
						Human human2;
						player1 = &human1;
						player2 = &human2;
						name1 = vgame[0];
						name2 = vgame[1];

						player1->readFromFile(name1);
						player2->readFromFile(name2);
						countShipPiece1 = player1->getShipPice();
						countShipPiece2 = player2->getShipPice();


						arr1 = player1->getArr();
						arr2 = player2->getArr();

						//player1->setNameX(name2);
						//player2->setNameX(name1);
						nameUnfinished = player1->getNameUnifinished();
						//player2->getSetUnifinished();

						_getch();

						cout << "This game" << name1 << " VS " << name2 << " are your shure, CONTINUE ? : ";
						q = _getch();
						if (q == 'y' || q == 'Y')
							Game::playGame();
						else
							return false;
					}
					else if (q == 'n' || q == 'N')
						return false;


				} while (q != 'y' || q != 'Y' || q != 'n' || q != 'N');
				system("pause");

			}
		}


	}
}
*/
void Game::arrangementOfShip() {
	system("cls");
	cout << "Man VS Man" << endl;
	cout << " Player " << name1 << endl;
	player1->ArangmentShip();
	arr1 = player1->getArr();
	//player2->setArrX(arr1);
	//name1 = player1->getName();
	cout << " thank you, press enter so that another player can arrange their ships" << endl;
	_getch();
	system("cls");
	cout << "Man VS Man" << endl;
	cout << "Player " << name2 << endl;
	player2->ArangmentShip();
	arr2 = player2->getArr();
	//player1->setArrX(arr2);
	//name2 = player2->getName();
	cout << " thank you, press enter to continue the game" << endl;
	_getch();
	system("cls");
	//player1->writeToFile(nameUnfinished);
	//player2->writeToFile(nameUnfinished);

}

void Game::playGame() {
	
	do {
		system("cls");
		cout << name2 << " step away from the screen, close your eyes, let the other player make a move " << endl << endl;
		cout << name1<< " please push ENTER " << endl;

	} while (_getch() != 13);


			int hit1 = 1;
			int hit2 = 1;

			do {
				char q = ' ';
				if (nameUnfinished != name2) {
					if (countShipPiece1 < 20 && countShipPiece2 < 20) {
						do {
							hit1 = 1;
							//cout << name1 << " -  attack " << endl << endl;
							nameUnfinished = name1;
							hit1 = player1->AtackShip(arr2, name2);
							countShipPiece1 = player1->getShipPice();
						} while (hit1);
						nameUnfinished = name2;
						//player1->writeToFile(nameUnfinished);
						//player2->writeToFile(nameUnfinished);
						do {
							if (countShipPiece1 < 20) {
								cout << "The player  - " << name1 << " - missed, the move is up to the player 2 - " << name2 << endl;
								cout << endl << endl << endl;
								cout << "if you want to stop the game, press - ' e '" << endl << endl;
								cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl;
								q = _getch();
								if (q == 'e')
									return ;
								system("cls");
							}
							else
								q = 13;
						} while (q != 13);
					}
				}
				if (countShipPiece1 < 20 && countShipPiece2 < 20) {
					do {
						hit2 = 1;
						//cout << name2 << " -  attack " << endl << endl;
						nameUnfinished = name2;

						hit2 = player2->AtackShip(arr1, name1);
						countShipPiece2 = player2->getShipPice();
					} while (hit2);
					nameUnfinished = name1;
					//player1->writeToFile(nameUnfinished);
					//player2->writeToFile(nameUnfinished);
					
					do {
						if (countShipPiece2 < 20) {
							cout << endl << endl;
							cout << "The player - " << name2 << " - missed, the move is up to the player 1 - " << name1 << endl;
							cout << endl << endl << endl;
							cout << "if you want to stop the game, press - ' e '" << endl << endl << endl;
							cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl << endl;
							q = _getch();
							if (q == 'e')
								return;
							system("cls");
						}
						else
							q = 13;
					} while (q != 13);
				}

			} while (countShipPiece1 < 20 && countShipPiece2 < 20);
			system("cls");
			
				do {
					if (countShipPiece1 == 20)
						cout << "win player " << name1 << " press enter " << endl;

					else if (countShipPiece2 == 20)
						cout << "win player " << name2 << " press enter " << endl;
					else
						cout << "confuse  ups " << endl;

					string txt3 = "C:\\Windows\\Temp\\111\\";
					remove(txt3.c_str());

				} while (_getch() != 13);
				_getch();
				
				
			system("cls");
		

			
}
/*
void Game::base_name(){

	string txt = "C:\\Windows\\Temp\\111";
	
		for (const auto& file : filesystem::directory_iterator(txt)) {

			vgame.push_back(file.path().stem().string().substr(file.path().stem().string().find_last_of("/\\") + 1));

		}
	
}
*/
/*
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
*/

/*
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
	char c; // захват enter на клавиатуре
	char q; // захват стрелки на клавиатуре
	int x = 21;
	int y = 1;
	
	Game::AtackPrintScreen(y, x, arr, name, arrX, nameX);
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
		
			Game::writeToFile();
			
	} while (hit);
	
	return hit;
}
*/

/*
void Game::writeToFile() {
	string s1 = to_string(countShipPiece1);
	string s2 = to_string(countShipPiece2);

	
	string txt = "C:\\Windows\\Temp\\player.dat";
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
	string txt = "C:\\Windows\\Temp\\player.dat";
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
*/