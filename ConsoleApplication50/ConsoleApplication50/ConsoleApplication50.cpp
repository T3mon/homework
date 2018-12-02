
#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;
enum collor
{
	black = 0,
	white = 1,

};

void draw(int x1, int y1, int x2, int y2, int size)
{
	for (int column = 0; column < size; ++column)
	{
		cout << (char)219;
	}
	cout << "\n";
	for (int row = 0; row < 18; ++row)
	{
		cout << (char)219;

		for (int column = 0; column < size - 2; column++)
		{
			if (row == x1 && column == y1)
			{
				//field[column][row] = (char)178;
				cout << (char)178;
			}
			else if (row == x2 && column == y2)
			{
				cout << (char)177;
			}
			else {
				cout << " ";
			}

		}
		cout << (char)219 << endl;
	}
	for (int column = 0; column < size; ++column)
	{
		cout << (char)219;
	}
	cout << "\n";
}

//Написать игру в котором пользователь бегает за мобами
//В случае если он их догоняет - моб убивается и игроку дается 1 монетка
//За эти монетки пользователь может покупать улучшения для своего персонажа в магазине
int main()
{
	srand(time(0));
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	int x1 = 2;
	int y1 = 12;
	int x2 = 15;
	int y2 = 15;

	const int size = 50;
	const int column = 1;
	const int row = 1;
	int field[column][row];

	while (true) {

		draw(x1, y1, x2, y2, size);
		char inp = _getch();

		int direction = rand() % 4 + 1;

		switch (direction)
		{
		case 1:
			if (x2 > 0)
			{
				x2--;
			}
			
			break;
		case 2:
			if (x2 < 17)
			{
				x2++;
			}
			
			break;
		case 3:
			if(y2 < size - 3)
			y2++;
			break;
		case 4:
			if (y2 > 0)
			{
				y2--;
			}
			break;
		}

		switch (inp) {
		case 72:
			system("cls");
			cout << "up\n";
			if (x1 > 0)
			{
				x1--;
			}

			break;
		case 75:
			system("cls");
			cout << "left\n";
			if (y1 > 0)
			{
				y1--;
			}
			break;
		case 77:
			system("cls");
			cout << "right\n";
			if (y1 < size - 3)
			{
				y1++;
			}

			break;
		case 80:
			system("cls");
			cout << "down\n";
			if (x1 < 17)
			{
				x1++;
			}

			break;
		default:
			break;
		}

		if (x1 == x2 && y1 == y2)
		{
			system("cls");
			cout << "Victory!!!";
			system("pause");
			break;
		}
	}


	return 0;
	system("pause");
}