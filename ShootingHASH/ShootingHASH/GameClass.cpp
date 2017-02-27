#include "pch.h"
#include "GameClass.h"
#include "Draw.h"
#include "Input.h"
#include "Player.h"
GameClass::GameClass(HWND phWnd)
	:hWnd(phWnd)
{
	init();
}


GameClass::~GameClass()
{
	//TODO: Drower 딜리트해주기
	
}

int GameClass::GetKeyboardInput()
{
	Player1->setInputFlag(KeyboardInput->GetKeyInput());
	return 0;
}

int GameClass::Run(float dt)
{
	Drawer->DrawHDC(dt);
	return 0;
}

int GameClass::init()
{
	Drawer = new Draw(hWnd);
	KeyboardInput = new Input();
	Player1 = new Player(Drawer->GetMemoryDC());

	return 0;
}
