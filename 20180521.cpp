#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>	// 키 입출력에 관련된 함수들을 모아놓은 라이브러리

using namespace std;
int main(){
	/* ###########################################################################		실습			###########################################################
		
		실습 내용:
			5X5 사이즈의 타일맵을 키 입력을 받아 상하좌우로 움직이면서
			( 벽에 막히면 못 움직이게 ) 
			1) 게임 시작 시 맵의 랜덤한 한 지점에 탈출점을 정해서
			2) 해당 지점으로 이동하면 탈출을 성공하는 게임을 만들어 보자.

			0 0 0 0 0
			0 X 0 0 0
			0 0 0 0 0
			0 0 0 0 0 
			0 0 0 0 0

			while문을 사용해 갱신
			while문 안에 system("cls") 넣어서 매번 화면 갱신
			탈출점이 아닌 곳으로 가면 (여기는 출구가 없다) 이런 메시지 표현

			추가 실습
				Player, Tile 구조체를 사용해서
				Tile: 지형(숲, 늪, 평지), Gold, Exit
				Player: 이름, 소지금액, 스테미너

				이동시 스태미나 1 소모, 스태미너가 0이 되면 게임 오버
				돈이 있는 타일로 이동하면 소지금액 추가 ( 50원을 얻었다. 소지금액: 200 등 )
				각 타일로 이동시 해당 타일의 지형 정보 표시 ( 늪에 들어왔다 등 )
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

	// Map 생성
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

	// 플레이어 입력
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
					cout << "○";
				else if (map[i][j].topography == 0)
					cout << "  ";
				else if (map[i][j].topography == 1)
					cout << " ,";
				else if (map[i][j].topography == 2)
					cout << " /";
			}
			cout << endl;
		}

		cout << "소지 금액: " << user.gold << endl ;

		if (map[user.pos.y][user.pos.x].topography == 0)
			temp = "평지";
		else if (map[user.pos.y][user.pos.x].topography == 1)
			temp = "숲";
		else if (map[user.pos.y][user.pos.x].topography == 2)
			temp = "산";

		cout << "현재 지형: " << temp << endl;
		if (!(user.pos.x == dest.x && user.pos.y == dest.y))
			cout << "탈출지점 X" << endl;
		cout << "남은 스태미나: " << user.stamina << endl;

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
			cout << "탈출에 실패하셨습니다!!!!" << endl;
			break;
		}

		if (map[user.pos.y][user.pos.x].isExit)
		{
			cout << "클리어!!!!!!!!!!!!!!!!!" << endl;
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