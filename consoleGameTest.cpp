#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

#define SCREEN_SIZE_W 80
#define SCREEN_SIZE_H 50

using namespace std;

void setCursor(COORD pos);
void setCursor(short x, short y);
void setColor(int col);
void printCharacters(short x, short y, const char *c);

int main() {
	ifstream r;
	vector<string> v, chV;
	char ch = 0;
	int x=0, y=0, chX = 20, chY = 20;

	r.open("hmap.txt");

	system("mode con:cols=300 lines=100");
	system("title console title");
	system("color 0F");

	for (string line; getline(r, line);) {
		v.push_back(line);
	}
	r.close();

	/*
	r.open("charac.txt");
	for (string line; getline(r, line);) {
		chV.push_back(line);
	}
	r.close();
	*/

		
	while (true) {

		/*
		if (fdNum == 0)
			continue;
		*/

		
		if (_kbhit()) {	// #include <conio.h>
			ch = _getch();

			switch (ch) {
			case 'a':
				if (x - 2 >= 0) {
					if (chX > 22) {
						chX -= 2;
					}
					else if (chX < 20) {
						chX = 20;
					}
					else {
						x -= 2;
					}
				}
				else {
					if (chX - 2 >= 0) {
						chX -= 2;
					}
				}
				break;
			case 'd':
				if (x + 2 <= (v.at(0).length() - 1 - SCREEN_SIZE_W)) {
					if (chX < 18) {
						chX += 2;
					}
					else if (chX > 20) {
						chX = 20;
					}
					else {
						x += 2;
					}
				}
				else {
					if (chX + 2 <= SCREEN_SIZE_W - 5) {
						chX += 2;
					}
				}
				break;
			case 's':
				if (y + 2 <= (v.size() - 1 - SCREEN_SIZE_H)) {
					if (chY < 18) {
						chY += 2;
					}
					else if (chY > 20) {
						chY = 20;
					}
					else {
						y += 2;
					}
				}
				else {
					if (chY + 2 <= SCREEN_SIZE_H - 4) {
						chY += 2;
					}
				}
				break;

			case 'w':
				if (y - 2 >= 0) {
					if (chY > 22) {
						chY -= 2;
					}
					else if (chY < 20) {
						chY = 20;
					}
					else {
						y -= 2;
					}
				}
				else {
					if (chY - 2 >= 0) {
						chY -= 2;
					}
				}
				break;
			}
			if (ch == 'q')
				break;
		}
		setCursor(0, 0);
		setColor(1);

		for (int i = y+0; i < y+SCREEN_SIZE_H; i++) {
			for (int j = x+0; j < x+SCREEN_SIZE_W; j++) {
				cout << v.at(i)[j];
			}
			cout << endl;
		}

		setColor(2);
		setCursor(20, 20);

		for (int i = chX; i <= chX+2; i +=2 ) {
			for (int j = chY; j <= chY+2; ++j) {
				printCharacters(i, j, "■");
			}
			setCursor(chX, chY+i);

		}
		Sleep(33);

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