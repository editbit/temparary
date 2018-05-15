

#include <iostream>
#include <conio.h>
#include <Windows.h>

#define MAX_H 24
#define MAX_W 10

using namespace std;



int main() {
	int map[MAX_H][MAX_W] = { 0, };
	char input_k = 0;
	char x = 4, y = 0;

	for (int i = 0; i < MAX_W; i++) {
		map[MAX_H - 1][i] = 2;
	}
	for (int i = 0; i < MAX_H; i++) {
		map[i][0] = map[i][MAX_W - 1] = 2;
	}

	map[0][4] = 1;


	while (input_k != 'q') {

		input_k = _getch();	//????


		if (map[y + 1][x] == 1) {
			map[y][x] = 0;
			y++;
			map[y][x] = 1;
		}



		for (int i = 4; i < MAX_H; i++) {
			for (int j = 0; j < MAX_W; j++) {
				if (map[i][j] == 2 || map[i][j] == 1)
					cout << "бс";
				else if (map[i][j] == 0)
					cout << "  ";
			}
			cout << endl;
		}





		for (int i = 4; i < MAX_H; i++) {
			for (int j = 0; j < MAX_W; j++) {
				if (map[i][j] == 2 || map[i][j] == 1)
					cout << "бс";
				else if (map[i][j] == 0)
					cout << "  ";
			}
			cout << endl;
		}

		Sleep(100);
		System("cls");
	}

	system("pause");

	return 0;
}