#include "Comp.h"
#include<conio.h>

int Comp::rrand() {

	//this_thread::sleep_for(chrono::milliseconds(1000));
	int r = rand() % 10 + 1;
	return r;
}



Comp::Comp() {
	Comp::freeArr();
}
Comp::~Comp() {
	//Human::delAll();
	//countShipPiece= 0;
	//ShipPiece = 0;
	//name = " ";
}

void  Comp::delAll() {
	if (arr) {
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
		countShipPiece = 0;
		ShipPiece = 0;
		name.erase();
	}

}
string Comp::getNameUnifinished() { return nameUnfinished; }

void Comp::freeArr() {
	arr = new char* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new char[m];
}
void Comp::setName(string& name) { this->name = name; }
string Comp::getName() { return name; }
void Comp::FillArr() { // строим массив поле

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

void Comp::ArangmentShip()  {
	FillArr();
	int m = 11, n = 11;
	int r4=0, r41=0, r42=0;
	int k=0, i=0, j=0, q4 = 0;
	r4 = rrand();
	r41 = rrand();
	r42 = rrand();
	//cout << "r41= " << r41 << " : " << "r42= " << r42 << endl;
	while (q4 < 4)
	{





		if (r4 > 5)
		{
			i = r41;
			if (m - r42 > 5)
			{
				for (j = r42; j < r42 + 4; j++)
				{
					arr[i][j] = char(254);
					q4++;
					if (i > 1)
					{
						arr[i - 1][j] = char(250);
					}
					if (i < 10) //10
					{
						arr[i + 1][j] = char(250);
					}
				}

				arr[r41][r42 + 4] = char(250);
				if (r42 > 1)
					arr[r41][r42 - 1] = char(250);
				if (r41 > 1)
				{
					arr[r41 - 1][r42 + 4] = char(250);
					if (r42 > 1)
						arr[r41 - 1][r42 - 1] = char(250);
				}
				if (r41 < 10) //10
				{
					arr[r41 + 1][r42 + 4] = char(250);
					if (r42 > 1)
						arr[r41 + 1][r42 - 1] = char(250);
				}

			}
			else // ------------ if(m - r2 < 6)
			{
				for (j = r42; j > r42 - 4; j--)
				{
					arr[i][j] = char(254);
					q4++;
					if (i > 1)
					{
						arr[i - 1][j] = char(250);
					}
					if (i < 10)//10
					{
						arr[i + 1][j] = char(250);
					}
				}

				arr[r41][r42 - 4] = char(250);
				if (r42 < 10)
					arr[r41][r42 + 1] = char(250);
				if (r41 > 1)
				{
					arr[r41 - 1][r42 - 4] = char(250);
					if (r42 < 10)
						arr[r41 - 1][r42 + 1] = char(250);
				}
				if (r41 < 10)
				{
					arr[r41 + 1][r42 - 4] = char(250);
					if (r42 < 10)
						arr[r41 + 1][r42 + 1] = char(250);
				}
			}


		}
		else  // if (r < 6 )

		{
			j = r42;
			if (n - r41 > 5)
			{
				for (i = r41; i < r41 + 4; i++)
				{
					arr[i][j] = char(254);
					q4++;
					if (j > 1)
					{
						arr[i][j - 1] = char(250);
					}
					if (j < 10)
					{
						arr[i][j + 1] = char(250);
					}
				}

				arr[r41 + 4][r42] = char(250);
				if (r41 > 1)
					arr[r41 - 1][r42] = char(250);
				if (r42 > 1)
				{
					arr[r41 + 4][r42 - 1] = char(250);
					if (r41 > 1)
						arr[r41 - 1][r42 - 1] = char(250);
				}
				if (r42 < 10)
				{
					arr[r41 + 4][r42 + 1] = char(250);
					if (r41 > 1)
						arr[r41 - 1][r42 + 1] = char(250);
				}

			}
			else if (n - r41 < 6)
			{
				for (i = r41; i > r41 - 4; i--)
				{
					arr[i][j] = char(254);
					q4++;
					if (j > 1)
					{
						arr[i][j - 1] = char(250);
					}
					if (j < 10)
					{
						arr[i][j + 1] = char(250);
					}
				}

				arr[r41 - 4][r42] = char(250);
				if (r41 < 10)
					arr[r41 + 1][r42] = char(250);
				if (r42 > 1)
				{
					arr[r41 - 4][r42 - 1] = char(250);
					if (r41 < 10)
						arr[r41 + 1][r42 - 1] = char(250);
				}
				if (r42 < 10)
				{
					arr[r41 - 4][r42 + 1] = char(250);
					if (r41 < 10)
						arr[r41 + 1][r42 + 1] = char(250);
				}
			}

		}
	}

	//-----------------------------------------

	int q3 = 0;
	int r3, r31, r32;

	for (int k = 0; k < 2; k++)
	{

		q3 = 0;

		while (q3 < 2)
		{
			if (q3 == 0)
			{

				r3 = rrand();
				r31 = rrand();
				r32 = rrand();
				//cout << "r31=" << r31 << ":" << "r32= " << r32 << endl;
			}
			if (r3 > 5)
			{

				i = r31;
				if (m - r32 > 5)
				{
					if (arr[r31][r32] == ' ' && arr[r31][r32 + 1] == ' ' && arr[r31][r32 + 2] == ' ')
					{


						for (j = r32; j < r32 + 3; j++)
						{
							arr[i][j] = char(254);
							q3++;

							if (i > 1)
							{
								arr[i - 1][j] = char(250);
							}
							if (i < 10)
							{
								arr[i + 1][j] = char(250);
							}
						}

						arr[r31][r32 + 3] = char(250);
						if (r32 > 1)
							arr[r31][r32 - 1] = char(250);
						if (r31 > 1)
						{
							arr[r31 - 1][r32 + 3] = char(250);
							if (r32 > 1)
								arr[r31 - 1][r32 - 1] = char(250);
						}
						if (r31 < 10)
						{
							arr[r31 + 1][r32 + 3] = char(250);
							if (r32 > 1)
								arr[r31 + 1][r32 - 1] = char(250);
						}
					}
				}
				else // ------------ if(m - r2 < 6)
				{
					if (arr[r31][r32] == ' ' && arr[r31][r32 - 1] == ' ' && arr[r31][r32 - 2] == ' ')
					{

						for (j = r32; j > r32 - 3; j--)
						{
							arr[i][j] = char(254);
							q3++;

							if (i > 1)
							{
								arr[i - 1][j] = char(250);
							}
							if (i < 10)
							{
								arr[i + 1][j] = char(250);
							}
						}

						arr[r31][r32 - 3] = char(250);
						if (r32 < 10)
							arr[r31][r32 + 1] = char(250);
						if (r31 > 1)
						{
							arr[r31 - 1][r32 - 3] = char(250);
							if (r32 < 10)
								arr[r31 - 1][r32 + 1] = char(250);
						}
						if (r31 < 10)
						{
							arr[r31 + 1][r32 - 3] = char(250);
							if (r32 < 10)
								arr[r31 + 1][r32 + 1] = char(250);
						}
					}

				}
			}
			else  // if (r < 6 )

			{
				j = r32;
				if (n - r31 > 5)

				{
					if (arr[r31][r32] == ' ' && arr[r31 + 1][r32] == ' ' && arr[r31 + 2][r32] == ' ')
					{

						for (i = r31; i < r31 + 3; i++)
						{
							arr[i][j] = char(254);
							q3++;
							//w2++;
							if (j > 1)
							{
								arr[i][j - 1] = char(250);
							}
							if (j < 10)
							{
								arr[i][j + 1] = char(250);
							}
						}

						arr[r31 + 3][r32] = char(250);
						if (r31 > 1)
							arr[r31 - 1][r32] = char(250);
						if (r32 > 1)
						{
							arr[r31 + 3][r32 - 1] = char(250);
							if (r31 > 1)
								arr[r31 - 1][r32 - 1] = char(250);
						}
						if (r32 < 10)
						{
							arr[r31 + 3][r32 + 1] = char(250);
							if (r31 > 1)
								arr[r31 - 1][r32 + 1] = char(250);
						}
					}
				}
				else if (n - r31 < 6)
				{
					if (arr[r31][r32] == ' ' && arr[r31 - 1][r32] == ' ' && arr[r31 - 2][r32] == ' ')
					{

						for (i = r31; i > r31 - 3; i--)
						{
							arr[i][j] = char(254);
							q3++;
							//w2++;
							if (j > 1)
							{
								arr[i][j - 1] = char(250);
							}
							if (j < 10)
							{
								arr[i][j + 1] = char(250);
							}
						}

						arr[r31 - 3][r32] = char(250);
						if (r31 < 10)
							arr[r31 + 1][r32] = char(250);
						if (r32 > 1)
						{
							arr[r31 - 3][r32 - 1] = char(250);
							if (r31 < 10)
								arr[r31 + 1][r32 - 1] = char(250);
						}
						if (r32 < 10)
						{
							arr[r31 - 3][r32 + 1] = char(250);
							if (r31 < 10)
								arr[r31 + 1][r32 + 1] = char(250);
						}
					}
				}
			}
		}

	}
	//-----------------------------------------------------------
	int q2 = 0;
	int r2, r21, r22;

	for (int k = 0; k < 3; k++)
	{

		q2 = 0;

		while (q2 < 2)
		{
			if (q2 == 0)
			{

				r2 = rrand();
				r21 = rrand();
				r22 = rrand();
				//cout << "r21=" << r21 << ":" << "r22= " << r22 << endl;
			}
			if (r2 > 5)
			{

				i = r21;
				if (m - r22 > 5)
				{
					if (arr[r21][r22] == ' ' && arr[r21][r22 + 1] == ' ')
					{


						for (j = r22; j < r22 + 2; j++)
						{
							arr[i][j] = char(254);
							q2++;
							if (i > 1)
							{
								arr[i - 1][j] = char(250);
							}
							if (i < 10)
							{
								arr[i + 1][j] = char(250);
							}
						}

						arr[r21][r22 + 2] = char(250);
						if (r22 > 1)
							arr[r21][r22 - 1] = char(250);
						if (r21 > 1)
						{
							arr[r21 - 1][r22 + 2] = char(250);
							if (r22 > 1)
								arr[r21 - 1][r22 - 1] = char(250);
						}
						if (r21 < 10)
						{
							arr[r21 + 1][r22 + 2] = char(250);
							if (r22 > 1)
								arr[r21 + 1][r22 - 1] = char(250);
						}
					}
				}
				else // ------------ if(m - r2 < 6)
				{
					if (arr[r21][r22] == ' ' && arr[r21][r22 - 1] == ' ')
					{

						for (j = r22; j > r22 - 2; j--)
						{
							arr[i][j] = char(254);
							q2++;

							if (i > 1)
							{
								arr[i - 1][j] = char(250);
							}
							if (i < 10)
							{
								arr[i + 1][j] = char(250);
							}
						}

						arr[r21][r22 - 2] = char(250);
						if (r22 < 10)
							arr[r21][r22 + 1] = char(250);
						if (r31 > 1)
						{
							arr[r21 - 1][r22 - 2] = char(250);
							if (r22 < 10)
								arr[r21 - 1][r22 + 1] = char(250);
						}
						if (r21 < 10)
						{
							arr[r21 + 1][r22 - 2] = char(250);
							if (r22 < 10)
								arr[r21 + 1][r22 + 1] = char(250);
						}
					}

				}
			}
			else  // if (r < 6 )

			{
				j = r22;
				if (n - r21 > 5)

				{
					if (arr[r21][r22] == ' ' && arr[r21 + 1][r22] == ' ')
					{

						for (i = r21; i < r21 + 2; i++)
						{
							arr[i][j] = char(254);
							q2++;

							if (j > 1)
							{
								arr[i][j - 1] = char(250);
							}
							if (j < 10)
							{
								arr[i][j + 1] = char(250);
							}
						}

						arr[r21 + 2][r22] = char(250);
						if (r21 > 1)
							arr[r21 - 1][r22] = char(250);
						if (r22 > 1)
						{
							arr[r21 + 2][r22 - 1] = char(250);
							if (r21 > 1)
								arr[r21 - 1][r22 - 1] = char(250);
						}
						if (r22 < 10)
						{
							arr[r21 + 2][r22 + 1] = char(250);
							if (r21 > 1)
								arr[r21 - 1][r22 + 1] = char(250);
						}
					}
				}
				else if (n - r21 < 6)
				{
					if (arr[r21][r22] == ' ' && arr[r21 - 1][r22] == ' ')
					{

						for (i = r21; i > r21 - 2; i--)
						{
							arr[i][j] = char(254);
							q2++;

							if (j > 1)
							{
								arr[i][j - 1] = char(250);
							}
							if (j < 10)
							{
								arr[i][j + 1] = char(250);
							}
						}

						arr[r21 - 2][r22] = char(250);
						if (r21 < 10)
							arr[r21 + 1][r22] = char(250);
						if (r22 > 1)
						{
							arr[r21 - 2][r22 - 1] = char(250);
							if (r21 < 10)
								arr[r21 + 1][r22 - 1] = char(250);
						}
						if (r22 < 10)
						{
							arr[r21 - 2][r22 + 1] = char(250);
							if (r21 < 10)
								arr[r21 + 1][r22 + 1] = char(250);
						}
					}
				}
			}
		}

	}
	//----------------------------------------------------------------------------1
	int q1 = 0;
	int r11, r12;

	for (int k = 0; k < 4; k++)
	{

		q1 = 0;

		while (q1 < 1)
		{
			r11 = rrand();
			r12 = rrand();
			//cout << "r11=" << r11 << ":" << "r12= " << r12 << endl;

			if (arr[r11][r12] == ' ')
			{

				arr[r11][r12] = char(254);
				q1++;

				if (r11 > 1)
				{
					arr[r11 - 1][r12] = char(250);
					if (r12 > 1)
					{
						arr[r11 - 1][r12 - 1] = char(250);
						arr[r11][r12 - 1] = char(250);

					}
					if (r12 < 10)
					{
						arr[r11 - 1][r12 + 1] = char(250);
						arr[r11][r12 + 1] = char(250);
					}
				}
				if (r11 < 10)
				{
					arr[r11 + 1][r12] = char(250);
					if (r12 > 1)
					{
						arr[r11][r12 - 1] = char(250);
						arr[r11 + 1][r12 - 1] = char(250);
					}
					if (r12 < 10)
					{
						arr[r11][r12 + 1] = char(250);
						arr[r11 + 1][r12 + 1] = char(250);
					}
				}


			}



		}

	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == char(250))
			{
				arr[i][j] = ' ';
			}
		}
	}
	*/
}


void Comp::print() {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


}

char** Comp::getArr() {
	return arr;
}


void Comp::AtackPrintScreen(int& y, int& x) { // displays the field and ships on the console //выводит на консоль поле и корабли

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

int Comp::AtackShip(char** arrX, const string& nameX) {

	int hit = 1;
	char c; // захват enter на клавиатуре
	char q; // захват стрелки на клавиатуре
	int x = 21;
	int y = 1;


	Comp::AtackPrintScreen(y, x);
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
				ShipPiece++;

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

		Comp::AtackPrintScreen(y, x);

		//Human::writeToFile(name);

	} while (hit);

	return hit;
}

int Comp::getShipPice() { return ShipPiece; }