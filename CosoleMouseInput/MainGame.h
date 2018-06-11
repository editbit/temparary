#pragma once
#ifndef _MAINGAME_H

#include "config.h"

class MainGame
{
private:
	INPUT_RECORD rec;
	DWORD        dwNOER;

public:
	MainGame();
	~MainGame();

	void CheckMouse();
};

#endif