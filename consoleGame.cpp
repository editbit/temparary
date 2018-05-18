#include <iostream>
#include <Windows.h>

using namespace std;

void setCursor(COORD pos);
void setCursor(short x, short y);
void setColor(int col);
void printCharacters(short x, short y, const char *c);

int main() {
	int x = 8, y=1;

	system("mode con:cols=300 lines=100");
	system("title console title");

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			setColor(i%16);
			cout << "��";
		}
		cout << endl;
	}

	COORD pos = { x, y };
	setCursor(pos);

	//system("color �������ڻ�");	//16��Ʈ ���� �� ��, ��ü ����.
	//system("color 3E");

	cout << "##" << endl;

	printCharacters(20, 20, "��");

	return 0;
}

void setCursor(short x, short y) {
	setCursor({x, y});
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