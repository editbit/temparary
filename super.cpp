#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <vector>

enum {
	stand = 0, left = -1, right = 1
};

using namespace std;


void setCursor(COORD pos);
void setCursor(short x, short y);
void setColor(int col);
void printCharacters(short x, short y, const char *c);


int main() {
	ifstream r;
	vector<string> v, chV;
	char kbInput;
	int map[20][30] = { 0, };
	int x = 0, y = 17, jumpCount = 0, state = 0, moveX = 0, xS=0, yS=0;
	bool isOnGround = true, isItem = false;

	
	r.open("test_map.txt");

	system("mode con:cols=300 lines=100");
	system("title console title");
	system("color 0F");

	for (string line; getline(r, line);) {
		v.push_back(line);
	}
	r.close();

	
	
	

	for (int i = 0; i < 20; ++i)
	{
		map[18][i] = -1;
	}
	map[y][x] = 1;

	map[17][15] = 2;

	setColor(10);

	while (true)
	{
		setCursor(0, 0);

		for (int i = yS+0; i < 20; ++i)
		{
			for (int j = xS+0, l = 0; j < 20; ++j, l += 2)
			{
				//setCursor(l, i);
				if (v[i][j] == '0')
					cout << "  ";
				else if (v[i][j] == '1')
					cout << "■";
				else if (v[i][j] == '4')
					cout << "○";
				else if (v[i][j] == '2')
					cout << "◎";
				else if (v[i][j] == '3')
					cout << "☆";
			}
			cout << endl;
		}

		//map[y][x] = 0;
		v[y][x] = '0';

		if (_kbhit())
		{
			kbInput = _getch();
			switch (kbInput)
			{
			case 'a':
				if (x - 1 >= 0) {
					x -= 1;
					xS -= 1;
				}
				break;
			case 'd':
				if (x + 1 <= v.at(0).size()-2) {
					x += 1;
					xS += 1;
				}
				break;
			case 'w':

				break;
			case 's':

				break;
			case ' ':
				if (isOnGround)
				{
					jumpCount = 10;
					isOnGround = false;
					state = 2;
				}
				break;
			case 'n':
				v[18 - rand() % 3][rand() % 13 + 1] = '2';
				break;
			case 'm':
				v[18 - rand() % 3][rand() % 13 + 1] = '3';
				break;

			}
		}
		if (kbInput == 'q')
			break;



		if (!isOnGround)
		{
			if (jumpCount > 0)
			{
				jumpCount = jumpCount - 1;
				y = y - 1;
			}
			else
			{
				y = y + 1;
			}
		}

		if (v[y + 1][x] == '1')
		{
			isOnGround = true;
		}
		else if (v[y + 1][x] == 2)
		{
			v[y + 1][x] = '0';
			jumpCount = 2;
		}
		else
		{
			isOnGround = false;
		}

		if (v[y][x] == 2) {
			cout << "패배" << endl;
			break;
		}
		else
		{
			v[y][x] = '4';

			if (y == 19)
			{
				cout << "낙사" << endl;
				break;
			}
		}


		Sleep(100);
		/*

		map[y][x] = 0;

		if (_kbhit())
		{
			kbInput = _getch();
			switch (kbInput)
			{
			case 'a':
				if (x - 1 >= 0)
					x -= 1;
				break;
			case 'd':
				if (x + 1 <= 30)
					x += 1;
				break;
			case 'w':

				break;
			case 's':

				break;
			case ' ':
				if (isOnGround)
				{
					jumpCount = 10;
					isOnGround = false;
					state = 2;
				}
				break;
			case 'n':
				map[18 - rand() % 3][rand() % 13 + 1] = 2;
				break;
			case 'm':
				map[18 - rand() % 3][rand() % 13 + 1] = 3;
				break;

			}
		}
		if (kbInput == 'q')
			break;



		if (!isOnGround)
		{
			if (jumpCount > 0)
			{
				jumpCount = jumpCount - 1;
				y = y - 1;
			}
			else
			{
				y = y + 1;
			}
		}

		if (map[y + 1][x] == -1)
		{
			isOnGround = true;
		}
		else if (map[y + 1][x] == 2)
		{
			map[y + 1][x] = 0;
			jumpCount = 2;
		}
		else
		{
			isOnGround = false;
		}

		if (map[y][x] == 2) {
			cout << "패배"<<endl;
			break;
		}
		else
		{
			map[y][x] = 1;

			if (y == 19)
			{
				cout << "낙사" << endl;
				break;
			}
		}


		
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0, l = 0; j < 30; ++j, l += 2)
			{
				setCursor(l, i);
				if (map[i][j] == 0)
					cout << "  ";
				else if (map[i][j] == -1)
					cout << "■";
				else if (map[i][j] == 1)
					cout << "○";
				else if (map[i][j] == 2)
					cout << "◎";
				else if (map[i][j] == 3)
					cout << "☆";
			}
			cout << endl;
		}
		

		Sleep(33);
		setCursor(0, 0);
		*/
	}

	return 0;
}

void setCursor(short x, short y) {
	setCursor({ x, y });
}

void setCursor(COORD pos) {
	// 콘솔 창 커서 이동
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int col) {
	// 글자색 설정, col: 0~15 or FOREGROUND_식
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void printCharacters(short x, short y, const char *c) {
	setCursor({ x, y });
	cout << c;
}