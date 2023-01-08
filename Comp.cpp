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
	
}

void  Comp::delAll() {
	if (arr) {
		for (int i = 0; i < n; i++)
			delete[] arr[i];
		delete[] arr;
		
		number_hit_per_ship = 0;
		total_number_hit_deck = 0;
		r = 0;
		hit_target = 1;
		direction = 0;
		y = 0;
		x = 0;
		name.erase();
		nameUnfinished.erase();
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
	int mm = 11, nn = 11;
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
			if (mm - r42 > 5)
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
			if (nn - r41 > 5)
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
			else if (nn - r41 < 6)
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
				if (nn - r31 > 5)

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
				else if (nn - r31 < 6)
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
				if (mm - r22 > 5)
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
				if (nn - r21 > 5)

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
				else if (nn - r21 < 6)
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
	cout << name << "  -  Atack   -    Guess where the boat is " << endl << endl;

	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < m; j++) {

			if (i == 0 || j == 0) {
				cout << arr[i][j] << " ";

			}
			if (j == x && i == y && j > 20 && i > 0) {
				if (arr[i][j] != char(254) && arr[i][j] != '*' && arr[i][j]!=char(253))
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
					if (j < 12 && arr[i][j]!=' ') 
						cout << char(250) << " ";
					else
						cout << arr[i][j] << " ";
			}
		}
		cout << endl;
	}

}

bool Comp::chekHitShip(char** arrX, int& y, int& x) {
	
	if (arrX[y][x - 20 - 1] == char(254) || arrX[y][x - 20 + 1] == char(254) || arrX[y - 1][x-20] == char(254) || arrX[y + 1][x-20] == char(254)) {
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
			}else
				return true;
		}else if (arrX[y][x - 20 + 1] == 'X') {
			if (arrX[y][x - 20 +2] == char(254))
				return false;
			else if (arrX[y][x - 20 + 2] == 'X') {
				if (arrX[y][x - 20 + 3] == char(254))
					return false;
				else if (arrX[y][x - 20 + 3] == 'X')
					return true;
				else
					return true;
			}else
				return true;
		} else if (arrX[y - 1][x-20] == 'X') {
			if (arrX[y - 2][x-20] == char(254))
				return false;
			else if (arrX[y - 2][x-20] == 'X') {
				if (arrX[y - 3][x-20] == char(254))
					return false;
				else if (arrX[y - 3][x-20] == 'X') 
					return true;
				else
					return true;
			}else
				return true;
		}else if (arrX[y + 1][x-20] == 'X') {
			if (arrX[y + 2][x-20] == char(254))
				return false;
			else if (arrX[y + 2][x-20] == 'X') {
				if (arrX[y + 3][x-20] == char(254))
					return false;
				else if (arrX[y + 3][x-20] == 'X') 
					return true;
				else
					return true;
			}else
				return true;
		}else
			return true;
	
}

void Comp::outlineX(int& y, int& x) {  //  -------------------------  put ' * ' around the damaged ships, so as not to shoot at these places
	if (number_hit_per_ship == 1) {
		for (int i = y - 1; i < y + 2; i++) {
			for (int j = x - 1; j < x + 2; j++) {
				if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
					arr[i][j] = '*';
			}
		}
	}
	else if (number_hit_per_ship > 1) {
		if (arr[y][x + 1] == char(254)) { // X***
			if (number_hit_per_ship == 2) {

				for (int i = y - 1; i < y + 2; i++) {
					for (int j = x - 1; j < x + 3; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			if (number_hit_per_ship == 3) {
				for (int i = y - 1; i < y + 2; i++) {
					for (int j = x - 1; j < x + 4; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			if (number_hit_per_ship == 4) {
				for (int i = y - 1; i < y + 2; i++) {
					for (int j = x - 1; j < x + 5; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
		}
		//--
		else if (arr[y][x - 1] == char(254)) { //***X
			if (number_hit_per_ship == 2) {

				for (int i = y - 1; i < y + 2; i++) {
					for (int j = x - 2; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			else if (number_hit_per_ship == 3) {
				for (int i = y - 1; i < y + 2; i++) {
					for (int j = x - 3; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			else if (number_hit_per_ship == 4) {
				for (int i = y - 1; i < y + 2; i++) {
					for (int j = x - 4; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
		}
		//--    Y***
		else if (arr[y+1][x] == char(254)) {
			if (number_hit_per_ship == 2) {

				for (int i = y - 1; i < y + 3; i++) {
					for (int j = x - 1; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			else if (number_hit_per_ship == 3) {
				for (int i = y - 1; i < y + 4; i++) {
					for (int j = x - 1; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			else if (number_hit_per_ship == 4) {
				for (int i = y - 1; i < y + 5; i++) {
					for (int j = x - 1; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
		}
		//--    ***Y
		else if (arr[y-1][x] == char(254)) {
			if (number_hit_per_ship == 2) {

				for (int i = y - 2; i < y + 2; i++) {
					for (int j = x - 1; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			else if (number_hit_per_ship == 3) {
				for (int i = y - 3; i <= y + 1; i++) {
					for (int j = x - 1; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
			else if (number_hit_per_ship == 4) {
				for (int i = y - 4; i < y + 2; i++) {
					for (int j = x - 1; j < x + 2; j++) {
						if (i > 0 && j > 20 && j < m - 1 && i < n - 1 && arr[i][j] != char(253) && arr[i][j] != char(254))
							arr[i][j] = '*';
					}
				}
			}
		}
	}
}


bool Comp::shuter(char** arrX, int& y, int& x) {
	
	if (hit_target == 1 && number_hit_per_ship > 0) {
		if (direction == 1)
			x--;
		if (direction == 2)
			y++;
		if (direction == 3)
			y--;
		if (direction == 4)
			x++;
		
	}
	
	if (number_hit_per_ship != 0) {
		
					
		while (arr[y][x] == '*' || arr[y][x] == char(253) || x == 20 || x == 31 || y == 0 || y == 11) { // движемся в другую сторонц
			if (direction == 1) {
				
				if (x + number_hit_per_ship + 1 < m )
					x = x + number_hit_per_ship + 1;
				if (x == m - 1 || x == 20 || arr[y][x] == char(253) || arr[y][x] == '*') {
					x = x - 1;
					y = y + 1;
					direction = 2;
					
				}
				else
					direction = 4;
				

			}
			else if (direction == 2) {
				
				if (y - number_hit_per_ship - 1 >= 0 )
					y = y - number_hit_per_ship - 1;
				if (y == 0 || y == n - 1 || arr[y][x] == char(253) || arr[y][x] == '*') {
					x = x + 1;
					y = y + 1;
					direction = 4;
					
				}
				else
					direction = 3;
				
			}
			else if (direction == 3) {
				
				if (y + number_hit_per_ship + 1 < n )
					y = y + number_hit_per_ship + 1;
				if (y == 0 || y == n - 1 || arr[y][x] == char(253) || arr[y][x] == '*') {
					x = x - 1;
					y = y - 1;
					direction = 1;
					

				}
				else
					direction = 2;
				

			}
			else if (direction == 4) {
				
				if (x - number_hit_per_ship - 1 >= 20 )
					x = x - number_hit_per_ship - 1;
				if (x == m - 1 || x == 20 || arr[y][x] == char(253) || arr[y][x] == '*') {
					x = x + 1;
					y = y - 1;
					direction = 3;
					

				}
				else
					direction = 1;
				

			}
						
		}

	}
		
	if ( arr[y][x] != char(254) && arr[y][x] != '*' && arr[y][x] != char(253) ) {
		
		if (arrX[y][x - 20] == char(254)) {
			

			arr[y][x] = char(254);
			
			arrX[y][x - 20] = 'X';
			cout << endl;
			cout << "COMP Player - " << name << " shot position : " << endl;
			cout << "\t " << arr[y][0] << " : " << arr[0][x] << endl;
			cout << endl;
			
			total_number_hit_deck++;
			number_hit_per_ship++;
				
			
			return true;
		
		}
		else {
			arr[y][x] = char(253);
			arrX[y][x - 20] = char(253);
			cout << endl;
			cout << "COMP Player - " << name << " shot position : " << endl;
			cout << "\t " << arr[y][0] << " : " << arr[0][x] << endl;
			cout << "LOOOOOOSEr" << endl;
			cout << endl;
			//system("pause");
			return false;

		}

	} 
	
	
	return false;
		
		
}


int Comp::AtackShip(char** arrX, const string& nameX) {
	
	
	if (number_hit_per_ship == 0) {
		do {
			x = rand() % 10 + 21;
			y = rand() % 10 + 1;
		} while (arr[y][x] != ' ');
		r = rand() % 10 + 1;
	}
	
	
			
	do {

		//Comp::AtackPrintScreen(y, x);

		if (Comp::shuter(arrX, y, x)) {

			//Comp::AtackPrintScreen(y, x);
						
			if (Comp::chekHitShip(arrX, y, x)) {

				Comp::outlineX(y, x);
				
				//Comp::AtackPrintScreen(y, x);
				cout << "COMP Player - " << name << "  KILL  " << number_hit_per_ship << " ship deck " << endl;
				cout << endl;
				
				number_hit_per_ship = 0;
				direction = 0;
				//system("pause");
				
				if (total_number_hit_deck == 20)
					hit_target = 0;
			}
			
			
			if (number_hit_per_ship == 0) {
								
				do {
					x = rand() % 10 + 21;
					y = rand() % 10 + 1;
				} while (arr[y][x] != ' ');
				r = rand() % 10 + 1;

			}
			if (number_hit_per_ship == 1 ) {
				
				if (x > 25 && y < 6) {
					if (r < 6) {
						direction = 1; // x--;
					}
					else
						direction = 2; // y++;
				}
				else if (x > 25 && y > 5) {
					if (r > 5)
						direction = 1; // x--;
					else
						direction = 3; // y--;
				}
				else if (x < 26 && y>5) {
					if (r < 6)
						direction = 4; //  x++;
					else
						direction = 3; //  y--;
				}
				else if (x < 26 && y < 6) {
					if (r > 5)
						direction = 4; //  x++;
					else
						direction = 2; //  y++;
				}
				
				
				//system("pause");
			}
			hit_target = 1;
			

		} else {
			
			if (number_hit_per_ship == 0) {
				x = rand() % 10 + 21;
				y = rand() % 10 + 1;
				r = rand() % 10 + 1;
			}
			hit_target = 0;
			
		}
			
		//Comp::AtackPrintScreen(y, x);
							
		
	} while (hit_target);
	


	return hit_target;
}

int Comp::getTotal_number_hit_deck() { return total_number_hit_deck; }


bool Comp::correctPlaceShip() {

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