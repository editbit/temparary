#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>	// Ű ����¿� ���õ� �Լ����� ��Ƴ��� ���̺귯��

using namespace std;
int main(){
	/* ###########################################################################		�ǽ�			###########################################################
		
		�ǽ� ����:
			5X5 �������� Ÿ�ϸ��� Ű �Է��� �޾� �����¿�� �����̸鼭
			( ���� ������ �� �����̰� ) 
			1) ���� ���� �� ���� ������ �� ������ Ż������ ���ؼ�
			2) �ش� �������� �̵��ϸ� Ż���� �����ϴ� ������ ����� ����.

			0 0 0 0 0
			0 X 0 0 0
			0 0 0 0 0
			0 0 0 0 0 
			0 0 0 0 0

			while���� ����� ����
			while�� �ȿ� system("cls") �־ �Ź� ȭ�� ����
			Ż������ �ƴ� ������ ���� (����� �ⱸ�� ����) �̷� �޽��� ǥ��

			�߰� �ǽ�
				Player, Tile ����ü�� ����ؼ�
				Tile: ����(��, ��, ����), Gold, Exit
				Player: �̸�, �����ݾ�, ���׹̳�

				�̵��� ���¹̳� 1 �Ҹ�, ���¹̳ʰ� 0�� �Ǹ� ���� ����
				���� �ִ� Ÿ�Ϸ� �̵��ϸ� �����ݾ� �߰� ( 50���� �����. �����ݾ�: 200 �� )
				�� Ÿ�Ϸ� �̵��� �ش� Ÿ���� ���� ���� ǥ�� ( �˿� ���Դ� �� )
	*/
	struct Point
	{
		int x;
		int y;
	};

	struct Player
	{
		string name;
		int stamina;
		int gold;
		Point pos;
	};

	struct Tile
	{
		int topography;
		int gold;
		bool isExit;
	};

	Player user;
	Tile map[5][5] = {0,};
	Point dest;
	char userInput;
	string temp =" ";

	srand((unsigned int)time(NULL));

	// Map ����
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			map[i][j].topography = rand() % 3;
			map[i][j].gold = rand() % 10;
			map[i][j].isExit = false;
		}
	}
	dest.x = rand() % 4 + 1;
	dest.y = rand() % 4 + 1;
	map[dest.x][dest.y].isExit = true;

	// �÷��̾� �Է�
	cout << "user name: ";
	cin >> user.name;
	user.gold = 0;
	user.stamina = 10;
	cout << "stamina: " << user.stamina << endl;
	cout << "gold: " << user.gold << endl;
	cout << endl << "input any key";
	user.pos.x = user.pos.y = 0;
	_getch();

	while (true)
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (user.pos.x == j && user.pos.y == i)
					cout << "��";
				else if (map[i][j].topography == 0)
					cout << "  ";
				else if (map[i][j].topography == 1)
					cout << " ,";
				else if (map[i][j].topography == 2)
					cout << " /";
			}
			cout << endl;
		}

		cout << "���� �ݾ�: " << user.gold << endl ;

		if (map[user.pos.y][user.pos.x].topography == 0)
			temp = "����";
		else if (map[user.pos.y][user.pos.x].topography == 1)
			temp = "��";
		else if (map[user.pos.y][user.pos.x].topography == 2)
			temp = "��";

		cout << "���� ����: " << temp << endl;
		if (!(user.pos.x == dest.x && user.pos.y == dest.y))
			cout << "Ż������ X" << endl;
		cout << "���� ���¹̳�: " << user.stamina << endl;

		userInput = _getch();

		if (userInput == 'a' && user.pos.x > 0)
		{
			user.pos.x -= 1;
			user.stamina -= 1;
		}
		else if (userInput == 'd' && user.pos.x < 4)
		{
			user.pos.x += 1;
			user.stamina -= 1;
		}
		else if (userInput == 'w' && user.pos.y > 0)
		{
			user.pos.y -= 1;
			user.stamina -= 1;
		}
		else if (userInput == 's' && user.pos.y < 4)
		{
			user.pos.y += 1;
			user.stamina -= 1;
		}

		if (user.stamina <= 0)
		{
			cout << "Ż�⿡ �����ϼ̽��ϴ�!!!!" << endl;
			break;
		}

		if (map[user.pos.y][user.pos.x].isExit)
		{
			cout << "Ŭ����!!!!!!!!!!!!!!!!!" << endl;
			break;
		}
		else
		{
			user.gold += map[user.pos.y][user.pos.x].gold;
			map[user.pos.y][user.pos.x].gold = 0;
		}


		if (userInput == 'q')
		{
			break;
		}

		system("cls");
	}

	return 0;
}