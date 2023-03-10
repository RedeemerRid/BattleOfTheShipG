#include <iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include "Player.h"
#include "Game.h"
#include<vector>
#include<fstream>

using namespace std;


template <class T>
void getValue(string prompt, T& value)
{
	cout << prompt;
	cin >> value;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Error... try again" << endl;
		cout << prompt;
		cin >> value;
	}
	string endLine;
	getline(cin, endLine);



}

template <>
inline void getValue<string>(string prompt, string& value)
{
	cout << prompt;
	do {
		getline(cin, value);
	} while (value.empty());
}

template <>
void getValue<char>(string prompt, char& value)
{
	cout << prompt;
	cin.getline(&value, 30);

}
template <>
void getValue<int>(string prompt, int& value)
{
	cout << prompt;
	cin >> value;

}

void PlayerSMove(const int& clickNUM, vector<string> &v) {
	
	
	int hit_target = rand() % 10;
	int tr = rand() % 10;
	cout << endl;

	string player1, player2;
	system("cls");
	if (clickNUM == 1) {
		do {
			getValue("Enter your NAME player1 : ", player1);
		} while (player1.empty());
		do {
			getValue("Enter your NAME player2 : ", player2);
		} while (player2.empty());
		cout << endl;
	}
	else if (clickNUM == 2) {
		do {
			getValue("Enter your NAME player1 : ", player1);
		} while (player1.empty());
		if (tr > 5)
			player2 = "TerminatorComp";
		else
			player2 = "RobocopComp";
	}
	else if (clickNUM == 3) {
		player2 = "TerminatorComp";
		player2 = "RobocopComp";
	}
	cout << "Roulette gave out a number : " << hit_target << endl;
	if (hit_target < 5) {
		cout << "Goes first : " << player1 << endl;
		player1 = "1_"+player1;
		player2 = "2_"+player2;
		v.push_back(player1);
		v.push_back(player2);
	}
	else {
		cout << "Goes first : " << player2 << endl;
		player1 = "2_"+player1;
		player2 = "1_"+player2;
		v.push_back(player2);
		v.push_back(player1);
	}
	cout << endl;
	_getch();

}



int main() {
	HKL hkl = LoadKeyboardLayout(L"00000409", KLF_ACTIVATE);
	PostMessage(GetConsoleWindow(), WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)hkl);
	
	vector<string> v;
	
	Game gamer;
	
	srand(time(NULL));

	string banner = "Welcome to the SEA BATTLE game - Victory to you";
	string preface = "You have to fight with a person or a computer, you can also run a computer VS a computer";
	cout << banner << endl << endl;
	cout << preface << endl << endl;
	
	bool exit = true;
	int clickNUM;
	do
	{
		cout << "1 - Human VS Human" << endl;
		cout << "2 - Human VS RoboComp" << endl;
		cout << "3 - Terminator VS Robocop" << endl;
		cout << "0 - quit" << endl;

		while (!isdigit(char(cin.peek())))
		{
			system("cls");
			cin.ignore(32767, '\n');       //-----------------------------------------------------

			cout << "1 - Human VS Human" << endl;
			cout << "2 - Human VS RoboComp" << endl;
			cout << "3 - Terminator VS Robocop" << endl;
			cout << "0 - quit" << endl;
		}

		cin >> clickNUM;
		switch (clickNUM)
		{
		case 0://0
			cout << "do you shure that you exit, exit = 0, moving = 1 : ";
			cin >> exit;
			break;
		case 1://1
			//if (gamer.unifinishedSet()==false) {
				
				//system("cls");
				cout << " New game - Man vs Man " << endl << endl;
				_getch();
				PlayerSMove(clickNUM, v);
				gamer.set(v);
				gamer.delAll();
				
				
			//}
			
			//gamer.playGame();
			
			break;
		case 2://2
			cout << " New game - Man vs Comp " << endl << endl;
			_getch();
			PlayerSMove(clickNUM, v);
			gamer.set(v);
			gamer.delAll();
			break;
		case 3://3
			//loaddata(a, m);
			break;
		}
	} while (exit != 0);

	


	return 0;
}