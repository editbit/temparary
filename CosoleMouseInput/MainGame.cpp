#include "MainGame.h"



MainGame::MainGame()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (true)
	{
		CheckMouse();
	}

}


MainGame::~MainGame()
{
}

void MainGame::CheckMouse()
{
	while (true)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER);
		if (rec.EventType == MOUSE_EVENT)
		{
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X;
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y;
				COORD Coor = { 0, 0 };
				DWORD dw;
				FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Coor, &dw);
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor);
				printf("%d, %d", mouse_x, mouse_y);
				return;
			}
		}
		else if (rec.EventType == KEY_EVENT)
		{
			cout << rec.Event.KeyEvent.wVirtualKeyCode;

		}
	}
}

