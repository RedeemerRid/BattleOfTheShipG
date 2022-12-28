#include <iostream>
#include<conio.h>
#include<Windows.h>
#include "Human.h"

#include "Player.h"
#include "Game.h"

using namespace std;



int main() {
	HKL hkl = LoadKeyboardLayout(L"00000409", KLF_ACTIVATE);
	PostMessage(GetConsoleWindow(), WM_INPUTLANGCHANGEREQUEST, 0, (LPARAM)hkl);
	Game gamer;
	//Human* human;
	//Human human1;
	//Human human2;
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
			
			gamer.set();

			
			_getch();
			break;
		case 2://2
			//add(a, m);
			break;
		case 3://3
			//loaddata(a, m);
			break;
		}
	} while (exit != 0);

	


	return 0;
}