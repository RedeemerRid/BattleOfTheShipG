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
#include "Comp.h"
#include<vector>
#include<filesystem>
using namespace std;
namespace fs = filesystem;
void  Game::delAll() {
	
	
	total_number_hit_deck_1 = 0;
	
	total_number_hit_deck_2 = 0;
	name1.erase();
	name2.erase();
	nameUnfinished.erase();
	//vgame.clear();

}



void Game::set(vector<string> &v) {
	cout << "set" << endl;
	name1 = v[0];
	name2 = v[1];
	cout << name1 << " - " << name2;
	_getch();
	if (name1 == "1_TerminatorComp" || name2 == "1_TerminatorComp" || name1 == "1_RobocopComp" || name2 == "1_RobocopComp" || name1 == "2_TerminatorComp" || name2 == "2_TerminatorComp" || name1 == "2_RobocopComp" || name2 == "2_RobocopComp") {
		Human human;
		Comp comp;
		if (name1 == "1_TerminatorComp" || name1 == "1_RobocopComp") {
			player1 = &comp;
			player2 = &human;
		}
		else {
			player1 = &human;
			player2 = &comp;
		}
	}
	else {
		Human human1;
		Human human2;
		player1 = &human1;
		player2 = &human2;
	}
	
	player1->setName(name1);
	player2->setName(name2);
		
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
						total_number_hit_deck_1 = player1->getTotal_number_hit_deck();
						total_number_hit_deck_2 = player2->getTotal_number_hit_deck();


						arr1 = player1->getArr();
						arr2 = player2->getArr();

						
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
	cout << name1 << " VS " << name2 << endl;
	cout << " Player " << name1 << endl;
	player1->ArangmentShip();
	arr1 = player1->getArr();
	
	player1->print();
	cout << " thank you, press enter so that another player can arrange their ships" << endl;
	_getch();
	system("cls");
	cout << name1 << " VS " << name2 << endl;
	cout << "Player " << name2 << endl;
	player2->ArangmentShip();
	arr2 = player2->getArr();
	
	player2->print();
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
					if (total_number_hit_deck_1 < 20 && total_number_hit_deck_2 < 20) {
						do {
							//hit1 = 1;
							//cout << name1 << " -  attack " << endl << endl;
							nameUnfinished = name1;
							hit1 = player1->AtackShip(arr2, name2);
							total_number_hit_deck_1 = player1->getTotal_number_hit_deck();
						} while (hit1);
						nameUnfinished = name2;
						//player1->writeToFile(nameUnfinished);
						//player2->writeToFile(nameUnfinished);
						
						do {
							if (total_number_hit_deck_1 < 20) {
								cout << "The player  - " << name1 << " - missed, the move is up to the player 2 - " << name2 << endl;
								cout << endl << endl << endl;
								cout << "if you want to stop the game, press - ' e '" << endl << endl;
								cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl;
								
								q = _getch();
								//_getch();
								if (q == 'e')
									return ;
								system("cls");
							}
							else
								q = 13;
						} while (q != 13);
					}
				}
				if (total_number_hit_deck_1 < 20 && total_number_hit_deck_2 < 20) {
					do {
						//hit2 = 1;
						//cout << name2 << " -  attack " << endl << endl;
						nameUnfinished = name2;

						hit2 = player2->AtackShip(arr1, name1);
						total_number_hit_deck_2 = player2->getTotal_number_hit_deck();
					} while (hit2);
					nameUnfinished = name1;
					//player1->writeToFile(nameUnfinished);
					//player2->writeToFile(nameUnfinished);
					
					do {
						if (total_number_hit_deck_2 < 20) {
							cout << endl << endl;
							cout << "The player - " << name2 << " - missed, the move is up to the player 1 - " << name1 << endl;
							cout << endl << endl << endl;
							cout << "if you want to stop the game, press - ' e '" << endl << endl << endl;
							cout << "press ENTER without fear. Poke, to be afraid to poke - to give up in the game." << endl << endl;
							
							q = _getch();
							//_getch();
							if (q == 'e')
								return;
							system("cls");
						}
						else
							q = 13;
					} while (q != 13);
				}

			} while (total_number_hit_deck_1 < 20 && total_number_hit_deck_2 < 20);
			system("cls");
			
				do {
					if (total_number_hit_deck_1 == 20)
						cout << "win player " << name1 << " press enter " << endl;

					else if (total_number_hit_deck_2 == 20)
						cout << "win player " << name2 << " press enter " << endl;
					else
						cout << "confuse  ups " << endl;

					//string txt3 = "C:\\Windows\\Temp\\111\\";
					//remove(txt3.c_str());

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
void Game::writeToFile() {
	string s1 = to_string(total_number_hit_deck_1);
	string s2 = to_string(total_number_hit_deck_2);

	
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
	total_number_hit_deck_1 = stoi(ss1);
	total_number_hit_deck_2 = stoi(ss2);


}


*/