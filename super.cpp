#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>

enum {
	stand = 0, left = -1, right = 1
};

using namespace std;


void setCursor(COORD pos);
void setCursor(short x, short y);
void setColor(int col);
void printCharacters(short x, short y, const char *c);


int main() {
	char kbInput;
	int map[20][30] = { 0, };
	int x = 0, y = 18, jumpCount = 0, state = 0, moveX = 0;
	bool isOnGround = true;

	for (int i = 0; i < 20; ++i)
	{
		map[19][i] = -1;
	}
	map[y][x] = 1;

	map[17][15] = 2;

	while (true)
	{
		if (_kbhit())
		{
			kbInput = _getch();

			map[y][x] = 0;
			switch (kbInput)
			{
			case 'a':
				if(x -1 >= 0)
					x -= 1;
				break;
			case 'd':
				if(x+1 <= 30)
					x += 1;
				break;
			case 'w':

				break;
			case 's':

				break;
			case ' ':
				if (isOnGround)
				{
					jumpCount = 4;
					isOnGround = false;
					state = 2;
				}
				break;
			case 'n':
				map[18 - rand() % 3][rand()%13+1] = 2;

			}
			map[y][x] = 1;
		}
		if (kbInput == 'q')
			break;



		if (!isOnGround)
		{
			map[y][x] = 0;

			if (jumpCount > 0)
			{
				jumpCount = jumpCount - 1;
				y = y - 1;
				map[y][x] = 1;
			}
			else
			{
				y = y + 1;



				map[y][x] = 1;
			}


		}

		if (map[y + 1][x] == -1)
		{
			isOnGround = true;
		}
		else if (map[y+1][x] == 2)
		{
			map[y + 1][x] = 0;
			jumpCount = 2;
		}
		else
		{
			isOnGround = false;
		}

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0, l=0; j < 30; ++j, l+=2)
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
			}
			cout << endl;
		}

		Sleep(33);
		setCursor(0, 0);
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