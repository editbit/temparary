#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>	// 키 입출력에 관련된 함수들을 모아놓은 라이브러리

using namespace std;

/*
	1) 배열
		1-1) 키 입력
	2) 구조체
		2-1) 포인터
	3) 함수
		3-1) 지역변수/전역변수/extern 변수
*/


struct pirates
{
	string Name;
	int HP;
	int Att;
	int Def;
	float Speed;
};	// 구조체의 정의


// 그렇다면 구조체 안에 하위변수로 들어갈 수 있는 변수들은 뭐가 있을까???
struct piratesGroup
{
	// int/float/bool 등 기본 자료형들은 모두 사용 가능
	string Name;			// 클래스도 사용 가능
	string Treasures[5];	// 배열도 사용 가능
	pirates Members[3];		// 앞에서 정의한 구조체도 사용 가능
} strawHat, arribean;	// 구조체를 선언할 때 변수도 함께 선언할 수 있다.
// int a, b, c;

struct studentInfo
{
	string name;
	int age;
	float grade[4];
	float totalGrade;
	bool isMale;
	bool possGraduation;
};

int main()
{
	/*	#########################################################################		배열			##################################################################

		어떤 변수에 대해 동일한 크기로 메모리상에 연속으로 공간을 할당해 놓는 개념
		변수를 효율적으로 관리하기에 용이
	*/

	// 01. 배열의 선언
	// string student1Name, student2Name, student3Name;	// 일반적인 변수의 선언
	// => string studentName[3];

	// 위와 같은 경우(연속된 관련성을 갖는 변수들을 선얼할 때) 배열이라는 개념을 활용하면 훨씬 효율적으로 데이터를 관리할 수 있다.
	// int num[3];		// 배열의 선언 + 배열의 기본적인 구조
	// num이라는 이름과 3개의 연번을 가진 변수를 한 번에 선언한다.
	// num[0], num[1], num[2] 라는 3개의 변수가 한 번에 선언됨
	// 배열의 선언: '자료형 변수명[번호];'의 형태

	// num[0] = 3, num[1] = 5, num[2] = 8;
	// 배열을 통해 비슷한 성격의 변수들을 효율적으로 선언, 관리할 수 있다.

	// 여러 변수의 값을 넣기가 편해진다.
	/*
	for (int i = 0; i < 3; i = i + 1)
	{
		num[i] = i + 3;
	}
	*/
	// => num[0] = 3; num[1] = 4; num[2] = 5;
	// num1 = 3, num2 = 4, num3 = 5

	/*
		int myHP;
		메모리에 int형 데이터를 위해 비어있는 4바이트 공간을 확보한 후 myHP라는 이름을 붙인다.
		1) 비어있는 공간 아무 곳을 확보하는 것은 아니다. (비어있는 가장 낮은 주소의 공간)
			- 메모리 주소가 가장 낮은 곳부터 차례대로 확인하다가 비어있는 공간이 발견되었을 때 확보

		userHP라는 int형 변수 4개를 선언한다.
		int userHP[4];
		2) 메모리 상의 가장 낮은 주소부터 비어있는 공간을 탐색하다가 int형의 크기인 4 byte 씩 4개, 총 16 byte의 '연속된 메모리 공간'을 확보한 후 이름을 userHP라고 붙인다.
			연속된 메모리 공간에 할당.	주소는 메모리의 제일 앞의 메모리 공간의 주소.	배열의 첫 번째 주소와 자료형의 크기를 알고 있으면 배열로 선언된 변수들의 주소를 계산할 수 있다.
		배열은 메모리 상의 연속된 위치에 저장된다.

		02. 배열의 선언과 초기화

		int numA = 3;					// 일반적인 변수의 초기화
		int num[4] = { 3, 4, 5, 6};		// 배열 변수의 가장 기본적인 초기화
			=> num[0] = 3, num[1] = 4, num[2] = 5, num[3] = 6;

		배열의 크기를 초기화 하면서 지정해 줄 수도 있다.
		int num[] = {2, 4, 6, 8, 10}		// 이런 형태로도 선언 + 초기화 가능
		: 값의 개수(5개)만큼 배열이 선언, 초기화 된다.

		int testNum[10] = {1, 3, 5};
		: 배열의 크기만큼 초기화해 주지 않으면 나머지 값은 모두 0으로 초기화된다.

		int testNum[10] = { 1, 3, 5 };
		for (int i = 0; i < 10; ++i)
		{
			cout << testNum[i] << ' ';
		}
			=> 출력결과: 1 3 5 0 0 0 0 0 0 0

		문자와 문자열의 차이: 문자열 == 문자의 배열
		string myName = "Henry";
		char myName[6] = {'H', 'e', 'n', 'r', 'y', '\0'};
		위의 문자열 "Henry"는 사실 6개의 배열로 구성된 문자형 배열 변수이다.

		기본적으로 배열은 아래와 같은 형태로 선언할 수 없다.
			int i;
			cin >> i;
			int num[i];
			이와 같이 배열을 선언하고 싶은 경우가 많은데 기본적으로는 불가능
				- 메모리 상의 연속된 위치에 배열의 크기만큼 메모리 공간을 확보해야하는데
				  메모리 공간을 확보하는 작업은 컴파일 도중에 이루어진다.
				  그렇지만 변수 i의 값은 컴파일이 끝난 이후가 되어야 알 수 있다.
				  그렇기 때문에 얼마만큼의 크기를 확보해야 하는지 알 수 없기 때문에 이와 같이 선언할 수 없다.

			=>	이와같은 형태로 활용을 할 때
					1) 스택과 힙 메모리의 개념 이해가 필요하다.
					2) 포인터를 알아야 한다.


		03. 배열에 접근하는 방법
		int testNum[10] = { 1, 3, 5 };
		int testNum2[20] = {0, };
		cout << testNum[2] << endl;		// 5가 출력
		cout << testNum[20] << endl;	// 이게 왜 에러도 안뜨고 실행이 되지????
		// 배열변수명[번호] -> 배열의 시작 주소 + (배열의 자료형 크기) * (번호)의 주소를 찾아가서
		// 해당 주소에 있는 값을 사용
		//		배열 변수는 주소와 자료형의 크기를 이용해 연산하여 원하는 위치의 주소를 찾아 접근하며 메모리는 차례대로 확보되므로 에러가 발생하지 않는다.
		//			testNum[20]은 testNum의 시작 주소로부터 20번째(20*4)에 위치한 4 byte 크기의 공간에 위치한 값을 의미한다.
	*/

	/*
		데이터가 저장되는 메모리 공간
			stack 메모리는 낮은 주소부터 일정 크기 할당되고
			heap 메모리는 가장 높은 주소부터 시작하여 빈 공간에 할당

			stack 메모리
				- 메모리의 낮은 주소부터 차례대로 값을 저장하도록 되어 있다.
				- 메모리의 크기가 컴파일시 지정된다.
				- 주소가 저장된 데이터형: point
					pointer에 가변적인 데이터가 저장되어 있는 heap 메모리의 주소를 stack 메모리의 point 변수에 저장한다.
				- 컴파일시 메모리의 공간을 확보하여 사용.

			heap 메모리
				- 프로그램이 실행될 때 가변적(동적)으로 메모리를 사용해야할 경우 heap 메모리를 사용한다.
				- 런타임시 메모리의 공간을 확보하여 사용.

	*/

	/* ################################################################################		실습		################################################################

		실습 내용:
			string 형 배열 변수 3개를 선언하고 ( 이름 studentName )
			for문을 사용해서 cin으로 각 학생의 이름을 입력받고
			이후에 1 ~ 3 사이의 번호를 입력하면 해당 학생의 이름을 출력하게 하기.
	*/

/*
	string studentName[3];
	int studentNum;

	cout << "3명의 학생의 이름을 입력하세요." << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << i + 1 << ". 이름: ";
		cin >> studentName[i];
	}

	cout << endl;

	while (true)
	{
		cout << "번호(종료: -1): ";
		cin >> studentNum;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			studentNum = -2;
		}
		if (studentNum == -1)
			break;
		else if (studentNum - 1 >= 0 && studentNum - 1 < 3)
			cout << studentNum << "번 학생의 이름은 " << studentName[studentNum - 1] << "입니다." << endl;
		else
			cout << "해당 번호의 학생은 없습니다." << endl;

	}
*/

	/*
		04. 2차원 배열 및 다차원 배열
		1차원 배열: student[30] -> xx번 학생 일어나!
					데이터를 구분하는 구분자가 1개만 필요할 경우에 사용

		2차원 배열: 배열이 ( 개념적으로는 ) 이중으로 되어 있는 것
					바둑, 오목, 체크, SRPG, 타이쿤 게임 등의 공간 표현에 사용
			- 개념적으로 이중으로 되어있다?
				: N차원의 배열도 실제적으로는 데이터가 순차적으로 연속해서 들어간다.

				int num[3][4];
					(1)	00 01 02 03
						10 11 12 13
						20 21 22 23
				
					(2)	00 01 02 03 10 11 12 13 20 21 22 23

					(1)과 같은 형태로 메모리에 존재하는 것이 아닌 (2)와 같은 형태로 메모리에 존재한다.
				
			
			2차원 배열의 선언:
				int student[3][2];		// 3X2 = 6개의 배열 변수가 선언		->		x반 y번 앞으로 나와!
					데이터를 구분하는 구분자가 2개 필요할 때.

			2차원 배열의 선언과 초기화:
				int student[3][2] = {{1, 3}, {5, 7}, {9, 11}};
					-> student[0][0] ~ student[2][1]까지 값이 들어간다.
						student[0][0] = 1, student[0][1] = 3;
						student[1][0] = 5, student[1][1] = 7;
						student[2][0] = 9, student[2][1] = 11;

						N차원 배열에서 값이 입력되는 순서는 자릿수가 올라가는 것과 흡사하다.
						오른쪽 대괄호부터 숫자가 차근차근 올라간다.

						cout << student[1][0] << endl;	// 5가 정확히 나오는지 확인해 보자.

				int numTest[2][3] = {{1, 2, 3}, {4, 5, 6}};


	*/

	/*
	int student[3][2] = { { 1, 3 },{ 5, 7 },{ 9, 11 } };
	
	// 2차원 배열에서 for문 활용
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << student[i][j] << ' ';
		}
		cout << endl;
	}

	*/

	/* ########################################################################			키 입력		##################################################
		
		키 입력을 받으려면 키 입출력에 관련된 함수들을 모아놓은 라이브러리가 필요

		_getch() 함수를 사용
		: 키보드 입력하면 1개의 ASCII 문자의 값이 반환되는 함수

	*/

	/*
	char keyGet = _getch();
	cout << keyGet << " : " << (int)keyGet << endl;
	if (keyGet == 'a' || keyGet == 'A')
		cout << "A를 눌렀습니다." << endl;
	*/


	/* #########################################################################		실습			###################################################
	
		실습 내용:
			A ~ Z까지의 키 중에 한 개의 키를 맞추는 게임
			컴퓨터가 생각한 1개의 키 == 내가 입력한 키 -> '승리' 표시
			컴퓨터가 a~z 사이의 랜덤한 수 하나를 char 자료형의 변수에 저장한 후 사용
			5번 이내에 맞추지 못하면 게임 오버 ( while 문을 사용하라는 뜻 )

	*/
	/*
	char comKey, userKey;
	int i;

	srand((unsigned int)time(NULL));

	cout << "숫자 맞추기 게임~!" << endl;
	cout << "5번 내로 A ~ Z 사이의 문자를 맞춰보세요!" << endl;

	comKey = rand() % 26 + 'A';

	cout << comKey << endl;
	char a = 97;

	i = 5;
	while (true) {

		if (i <= 0)
		{
			cout << "더이상 기회가 없습니다." << endl;
			break;
		}

		cout << "(남은 기회: " << i << "회) 문자: ";
		userKey = _getch();
		_getch();
		cout << userKey << endl;

		if (userKey == comKey || userKey == (comKey + 32))
		{
			cout << endl << "컴퓨터: "<<comKey << "   유저: " << userKey << " => 정답입니다~!!" << endl; 
			cout << 5-i+1 << "번의 시도만에 맞추셨습니다." << endl;
			break;
		}
		else
		{
			cout << "오답입니다" << endl;
		}

		--i;

	}
	*/


	/* ##################################################################################		구조체		#############################################################
	
		00. 추상화의 개념

		배열/구조체/함수 -> 코드의 추상화를 위한 도구

		추상화???
			- 실제 현상(현실 세계)을 간략화/기호화/보편화해서 흉내낸 것

		코드에서 추상화가 중요한 이유
			- 결국 코드는 사람(들)이 짜는 것이기 때문!
				
		배  열: 속성이 동일한 여러 개의 데이터를 같은 이름과 연번으로 표현함으로써 추상화
		구조체: 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화
		함  수: 코드를 특정 기능 단위로 묶어서 추상화

		최악의 추상화: 추상화 단계를 상승시키는 과정
				- a = "김상균"					최악
				- a[3] = "김상균"
				- stduentName[3] = "김상균"
				- student[3].name = "김상균"		최선

		01. 구조체란??
		변수들이 모여 있는 집합체
		
		구조체를 사용하는 경우: 특정 변수들이 무언가의 하위 개념으로 묶일 때
			- 학생의 이름, 학생의 나이, 학생의 국어 점수, 학생의 영어 점수, 학생의 석차
				-> 이름, 나이, 국어점수, 영어점수, 석차를 '학생'이라는 구조체로 묶어서 사용한다.

		구조체 정의의 위치: 구조체가 사용되는 함수 앞 ( 해당 함수의 밖 )

		구조체 정의의 기본 문법
			struct 구조체_변수명
			{
				구조체 안에 있는 하위 변수들
			};	// 세미클론 위치에 주의할 것!!

	*/
	/*

	string lupiName;		// 구조체 사용 이전의 변수 선언
	struct pirates lupi;			// 구조체의 선언 ( lupi라는 이름의 pirates형 변수를 선언 ) C++에서는 struct 생략 가능
	lupi.Name = "루피";		// lupi(라는 해적)의 이름 == "루피"
	lupi.Att = 10;			// lupi(라는 해적)의 공격력 == 10
	lupi.Def = 5;			// lupi(라는 해적)의 방어력 == 5
	lupi.HP = 300;
	lupi.Speed = 1.4f;		// lupi(라는 해적)의 속도 == 1.4f	실수의 뒤에 f를 붙이면 이 숫자는 float형 숫자로 간주한다.
	// f를 붙이 않으면 double(실수의 기본 자료형)을 float에 넣는 것으로 인식되어 경고를 한다.

	*/

	/* #######################################################################		실습			###############################################################

		실습 내용:
			pirates 구조체를 활용해서 zoro를 만들어 보자.
			zoro의 이름과 HP를 출력해 보자.
	*/
	/*
	pirates zoro;
	zoro.Name = "조로";
	zoro.Att = 11;
	zoro.Def = 6;
	zoro.HP = 200;
	zoro.Speed = 1.8f;
	
	strawHat.Name = "밀집모자해적단";
	strawHat.Members[0] = lupi;
	strawHat.Members[1] = zoro;

	cout << strawHat.Members[0].Name << endl;	// 이게 '루피'가 출력되는 이유는? strawHat.Members[0] 에 lupi를 대입했기 때문에
	cout << strawHat.Members[1].HP << endl;		// 이 값은?? 200
	// 밀집모자 해적단'의' 첫 번째 멤버'의' HP
	strawHat.Treasures[0] = "금덩어리";
	strawHat.Treasures[1] = "은덩어리";
	

	/*
		02. 구조체 변수의 선언과 초기화
			기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
	*/

	/*
	pirates nami, usop;	// 여러 개의 구조체 변수를 동시에 선언
	pirates minion[5];	// 구조체 변수도 배열로 선언

	pirates sangdi = {"상디", 100, 8, 15, 1.2f};		// 선언과 동시에 초기화		string Name; int HP, Att, Def; float Speed;
													// (구조체를 선언할 때 안에 선언한 변수의 순서대로 초기화 된다.)
													// 배열 변수의 초기화와 방법이 같다.

	sangdi.HP -= (zoro.Att - sangdi.Def);			// 구조체를 사용하면 설명(주석)이 없어도 코드만으로 가독성 확보

	*/

	/*################################################################		실습		##################################################################
	
		실습 내용:
			학생을 구조체화해서 다음 속성을 설정하시오.
			이름, 나이, 1~4학년까지의 학점(float형의 실수), 성별, 졸업조건
			샘플로 학생 3명의 정보를 초기화해서 입력하시오.

			학생 이름을 입력하면 해당 학생의 1 ~ 4학년 학점, 평균학점, 성별, 졸업 조건 만족 여부
	*/

	/*

	struct studentInfo student[3] = {
										{"김가", 27, {4.0f, 3.9f, 3.5f, 3.7f}, true, false },
										{"이가", 25, { 4.1f, 4.0f, 3.6f, 3.8f }, false, true},
										{"박가", 22,{ 4.2f, 4.1f, 3.7f, 3.9f }, true, false}
									};
	string name;


	while (true)
	{
		cout << "학생의 이름: ";
		cin >> name;

		system("cls");

		if (name == "q" || name == "종료")
			break;

		for (int i = 0; i < 3; ++i)
		{
			if (name == student[i].name) {
				cout << student[i].name << endl;
				float avg=0;
				for (int j = 0; j < 4; ++j)
				{
					cout << j + 1 << "grade: " << student[i].grade[j]<< endl;
					avg += student->grade[j];
				}
				avg /= 4;
				cout << "\navg: " << avg << "\ngender: " << ((student[i].isMale) ? "male" : "female") << "\n" << ((student[i].possGraduation)?"can graduate":"can't graduate") << endl << endl;

			}
		}

	}
	*/

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
		// 맵 출력
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

		if (map[user.pos.y][user.pos.x].isExit)
		{
			cout << "클리어!!!!!!!!!!!!!!!!!" << endl;
			break;
		}
		else if (user.stamina <= 0)
		{
			cout << "탈출에 실패하셨습니다!!!!" << endl;
			break;
		}
		else
		{
			user.gold += map[user.pos.y][user.pos.x].gold;
			map[user.pos.y][user.pos.x].gold = 0;
		}

		// 입력
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

		


		if (userInput == 'q')
		{
			break;
		}

		system("cls");
	}

	return 0;
}