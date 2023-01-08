#include <iostream>
#include<conio.h>
#include<string>
#include "Human.h"
#include "Player.h"
#include<fstream>
//#include "Game.h"
using namespace std;


Human::Human() {
	Human::freeArr();
}
Human::~Human() {
	
}

void  Human::delAll() {
	if (arr) {
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
	countShipPiece= 0;
	total_number_hit_deck = 0;
    name.erase();
	}

}
string Human::getNameUnifinished() { return nameUnfinished; }

void Human::freeArr() {
	arr = new char* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[m];
}
void Human::setName( string& name) { this->name = name; }
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
void Human::FillShipHumanHandle(int& shipLength) {
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
	






/*
void Human::writeToFile(string& nameUnfinishedX) {
	
	string txt = "C:\\Windows\\Temp\\111\\" + name + ".txt";
	ofstream os(txt, ios::binary);


	os.write((char*)&ShipPiece, sizeof(int)); // Запись POD-члена
	size_t len = nameUnfinishedX.length() + 1;       // Длина с нулевым байтом
	os.write((char*)&nameUnfinishedX, sizeof(len)); // Запись длины
	os.write((char*)nameUnfinishedX.c_str(), len);

	len = name.length() + 1;       // Длина с нулевым байтом
	os.write((char*)&name, sizeof(len)); // Запись длины
	os.write((char*)name.c_str(), len);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 32; j++) {
			os << arr[i][j];
		}
	}

	os.close();

	/*
	
	string s = to_string(ShipPiece).c_str();
	
	
	string txt = "C:\\Windows\\Temp\\111\\" + name + ".dat";
	FILE* f;

	fopen_s(&f, txt.c_str(), "wb");
	
	for (int i = 0; i < s.size() + 1; i++)
		fputc(s[i], f);
	fputc('\n', f);
	for (int i = 0; i < nameUnfinishedX.length()+1; i++)
		fputc(nameUnfinishedX.c_str()[i], f);
	fputc('\n', f);
	for (int i = 0; i < name.length()+1; i++)
		fputc(name.c_str()[i], f);
	fputc('\n', f);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			fputc(arr[i][j], f);
		}
		fputc('\n', f);
	}
	
	fclose(f);
	
}
*/
/*
void Human::readFromFile( string& nameq) {
	
	string txt = "C:\\Windows\\Temp\\111\\" + nameq + ".txt";

	ifstream in(txt, ios::binary);

	in.read((char*)&ShipPiece, sizeof(int));   // Чтение POD-члена
	
	size_t len;                         // Переменная для длины
	in.read((char*)&len, sizeof(len));  // Чтение длины записанной строки
	char* buf = new char[len];         // Выделение буфера для чтения
	in.read(buf, len);                   // Чтение (с нулевым байтом)
	nameUnfinished = buf;                         // Присвоение считанной строки члену
	delete[]buf;

	in.read((char*)&len, sizeof(len));  // Чтение длины записанной строки
	char* buf1 = new char[len];         // Выделение буфера для чтения
	in.read(buf, len);                   // Чтение (с нулевым байтом)
	name = buf1;                         // Присвоение считанной строки члену
	delete[]buf1;

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 32; j++) {
			in >> arr[i][j];
		}
	}

		
	in.close();

	
	/*
	char uF[31]{0};
	char nm[31]{0};
	char s[3]{0};
	
	
	
	string txt = "C:\\Windows\\Temp\\111\\" + nameq + ".dat";
	char c=' ';
	FILE* ff;

	fopen_s(&ff, txt.c_str(), "rb");
	if (ff) {
		while (feof(ff) == 0) {
			c = getc(ff);
			
			int i = 0;
			while (c != '/n') {
				s[i] = c;
				
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
				nm[i] =  c;
				c = getc(ff);
				i++;
			}

			for (int i = 0; i < n; i++) {
				c = getc(ff);
				int j = 0;
				while (c != '\n') {
					arr[i][j] = c;
					c = getc(ff);
					j++;
				}

			}
		}
		fclose(ff);
	}
	
	
	
	name = nm;
	nameUnfinished = uF;
	ShipPiece = stoi(s);
	
	
}
*/


bool Human::chekHitShip(char** arrX, int& y, int& x) {

	if (arrX[y][x - 20 - 1] == char(254) || arrX[y][x - 20 + 1] == char(254) || arrX[y - 1][x - 20] == char(254) || arrX[y + 1][x - 20] == char(254)) {
		return false;
	}

	else  if (arrX[y][x - 20 - 1] == 'X') {
		if (arrX[y][x - 20 - 2] == char(254))
			return false;
		else if (arrX[y][x - 20 - 2] == 'X') {
			if (arrX[y][x - 20 - 3] == char(254))
				return false;
			else if (arrX[y][x - 20 - 3] == 'X')
				return true;
			else
				return true;
		}
		else
			return true;
	}
	else if (arrX[y][x - 20 + 1] == 'X') {
		if (arrX[y][x - 20 + 2] == char(254))
			return false;
		else if (arrX[y][x - 20 + 2] == 'X') {
			if (arrX[y][x - 20 + 3] == char(254))
				return false;
			else if (arrX[y][x - 20 + 3] == 'X')
				return true;
			else
				return true;
		}
		else
			return true;
	}
	else if (arrX[y - 1][x - 20] == 'X') {
		if (arrX[y - 2][x - 20] == char(254))
			return false;
		else if (arrX[y - 2][x - 20] == 'X') {
			if (arrX[y - 3][x - 20] == char(254))
				return false;
			else if (arrX[y - 3][x - 20] == 'X')
				return true;
			else
				return true;
		}
		else
			return true;
	}
	else if (arrX[y + 1][x - 20] == 'X') {
		if (arrX[y + 2][x - 20] == char(254))
			return false;
		else if (arrX[y + 2][x - 20] == 'X') {
			if (arrX[y + 3][x - 20] == char(254))
				return false;
			else if (arrX[y + 3][x - 20] == 'X')
				return true;
			else
				return true;
		}
		else
			return true;
	}
	else
		return true;

}

void Human::AtackPrintScreen(int& y, int& x) { // displays the field and ships on the console //выводит на консоль поле и корабли

	system("CLS");
	cout << name << "Atack   -    Guess where the boat is " << endl << endl;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {

			if (i == 0 || j == 0) {
				cout << arr[i][j] << " ";

			}
			if (j == x && i == y && j > 20 && i > 0) {
				if (arr[i][j] != char(254) && arr[i][j] != '*')
					cout << "+" << " ";
				else
					cout << arr[i][j] << " ";
			}
			else if (i > 0 && j > 0) {
				if (i == 11 || j == 11 || j == 31) {
					cout << arr[i][j] << " ";

				}
				else if (arr[i][j] != char(254) && arr[i][j] != '*' && arr[i][j] != char(253) && arr[i][j] != 'X' && (j < 12 || (j > 20 && j < m - 1))) {
					cout << char(250) << " ";
				}
				else
					cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}

}




int Human::AtackShip(char** arrX, const string& nameX) {
	
	int hit_target = 1;
	char c; // захват enter на клавиатуре
	char q; // захват стрелки на клавиатуре
	int x = 21;
	int y = 1;
	
	
	Human::AtackPrintScreen(y, x);
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
				arr[y][x] = arrX[y][x - 20];
				arrX[y][x - 20] = 'X';
				cout << endl;
				cout << "MAN Player - " << name << " shoot position : " << endl;
				cout << "\t " << arr[y][0] << " : " << arr[0][x] << endl;
				cout << endl;
				system("pause");
				total_number_hit_deck++;
				number_hit_per_ship++;
				if (Human::chekHitShip(arrX, y, x)) {
					cout << "MAN Player - " << name << "  KILL  " << number_hit_per_ship << " ship deck " << endl;
					cout << endl;
					number_hit_per_ship = 0;
					system("pause");
					
					if (total_number_hit_deck == 20)
						hit_target = 0;
				}
			}
			else {
				arr[y][x] = char(253);
				cout << endl;
				cout << "MAN Player - " << name << " shot position : " << endl;
				cout << "\t " << arr[y][0] << " : " << arr[0][x] << endl;
				cout << "LOOOOOOSEr" << endl;
				cout << endl;
				system("pause");
				hit_target = 0;

			}

		}
		else if (arr[y][x] != char(254) && arr[y][x] != char(253) && arr[y][x] != 'X' && c == 'x') {
			arr[y][x] = '*';


		}
		else if (arr[y][x] == '*' && c == 'c') {
			arr[y][x] = ' ';

		}
		
		Human::AtackPrintScreen(y, x);
		
		//Human::writeToFile(name);
		
	} while (hit_target);
	
	return hit_target;
}
int Human::getTotal_number_hit_deck() { return total_number_hit_deck; }
