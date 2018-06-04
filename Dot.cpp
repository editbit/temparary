#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <vector>

using namespace std;


#define X_SIZE 20
#define Y_SIZE 20

void setCursor(COORD pos);
void setCursor(short x, short y);
void setColor(int col);
void printCharacters(short x, short y, const char *c);


/*
검정 0
파란 1
초록 2
옥색 3
빨간 4
자주 5
노란 6
흰색 7
회색 8
연한 파란 9
연한 초록 10
연한 옥색 11
연한 빨간 12
연한 자주 13
연한 노란 14
진한 흰색 15

*/

int main()
{
	int map[Y_SIZE][X_SIZE] = { 0 };
	int curX = 5, curY = 5, curC;
	int count = 0;

	int ch;

	ifstream r;
	vector<string> v, chV;

	string fileName = "";

	cout << "읽을 파일 이름: ";
	cin >> fileName;
	if (fileName == "n")
	{

	}
	else
	{
		r.open(fileName);

		int i = 0;
		for (string line; getline(r, line); ++i) {
			v.push_back(line);
			for (int j = 0; j < X_SIZE; ++j)
			{
				map[i][j] = v[i][j] - '0';
				//cout << map[i][j];
			}
			//cout << endl;
		}
		r.close();


		if (v.size() == 0)
		{
			return 0;
		}
	}


	while (true)
	{
		ch = _getch();
		//_getch();

		system("cls");
		if ((ch >= '0') && (ch <= '9'))
		{
			/*if (count == 1)
			{
				curC = curC * 10 + ch - '1' + 1;
				if (curC > 15)
					curC = 15;
				count = 0;
			}
			else if (count == 0)
			{
				curC = ch - '1' + 1;
				count = 1;
			}*/

			curC = ch - '1' + 1;
		}
		else if (ch == ' ')
		{
			count = 0;
			map[curY][curX] = curC;
		}
		else
		{
			count = 0;
			if (ch == 'a')	// 왼쪽
			{
				if (curX > 0)
					curX--;
			}
			else if (ch == 'd')	// 오른쪽
			{
				if (curX < X_SIZE - 1)
					curX++;
			}
			else if (ch == 'w')	// 위
			{

				if (curY > 0)
					curY--;
			}
			else if (ch == 's')	// 아래
			{
				if (curY < Y_SIZE - 1)
					curY++;

			}
			else if (ch == 'q')
				break;
		}


		for (int i = 0; i < Y_SIZE; ++i)
		{
			for (int j = 0; j < X_SIZE; ++j)
			{
				if (i == curY && j == curX)
				{
					setColor(curC);
					cout << "●";
				}
				else
				{
					setColor(map[i][j]);

					if (map[i][j] != 0)
						cout << "■";
					else
						cout << "  ";
				}
			}
			cout << endl;
		}

	}

	for (int i = 0; i < Y_SIZE; ++i)
	{
		for (int j = 0; j < X_SIZE; ++j)
		{

			setColor(map[i][j]);
			cout << map[i][j];
		}
		cout << endl;
	}

	setColor(7);
	cout << "저장하시겠습니까?";
	cin >> fileName;

	if (fileName == "q")
		return 0;

	ofstream os;                   // os란 변수로 파일 출력 선언
	os.open(fileName);   // os로 텍스트 파일 오픈 ( 이 시점엔 생성시킨다 보면 됩니다. )
	for (int i = 0; i < Y_SIZE; ++i)
	{
		for (int j = 0; j < X_SIZE; ++j)
		{
			os << map[i][j];
		}
		os << endl;
	}
	os.close();                      // 파일 닫기 ( 파일을 열었으면 항상 해줘야 합니다. )


	system("pause");
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


