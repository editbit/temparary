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
���� 0
�Ķ� 1
�ʷ� 2
���� 3
���� 4
���� 5
��� 6
��� 7
ȸ�� 8
���� �Ķ� 9
���� �ʷ� 10
���� ���� 11
���� ���� 12
���� ���� 13
���� ��� 14
���� ��� 15

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

	cout << "���� ���� �̸�: ";
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
			if (ch == 'a')	// ����
			{
				if (curX > 0)
					curX--;
			}
			else if (ch == 'd')	// ������
			{
				if (curX < X_SIZE - 1)
					curX++;
			}
			else if (ch == 'w')	// ��
			{

				if (curY > 0)
					curY--;
			}
			else if (ch == 's')	// �Ʒ�
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
					cout << "��";
				}
				else
				{
					setColor(map[i][j]);

					if (map[i][j] != 0)
						cout << "��";
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
	cout << "�����Ͻðڽ��ϱ�?";
	cin >> fileName;

	if (fileName == "q")
		return 0;

	ofstream os;                   // os�� ������ ���� ��� ����
	os.open(fileName);   // os�� �ؽ�Ʈ ���� ���� ( �� ������ ������Ų�� ���� �˴ϴ�. )
	for (int i = 0; i < Y_SIZE; ++i)
	{
		for (int j = 0; j < X_SIZE; ++j)
		{
			os << map[i][j];
		}
		os << endl;
	}
	os.close();                      // ���� �ݱ� ( ������ �������� �׻� ����� �մϴ�. )


	system("pause");
}


void setCursor(short x, short y) {
	setCursor({ x, y });
}

void setCursor(COORD pos) {
	// �ܼ� â Ŀ�� �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int col) {
	// ���ڻ� ����, col: 0~15 or FOREGROUND_��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void printCharacters(short x, short y, const char *c) {
	setCursor({ x, y });
	cout << c;
}


