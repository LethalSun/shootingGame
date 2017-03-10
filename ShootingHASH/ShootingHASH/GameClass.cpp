#include "pch.h"
#include "GameClass.h"
#include "DeviceContextManager.h"
#include "BackgroundClass.h"
#include "Input.h"
#include "Player.h"
#include "PlayerClass.h"

GameClass::GameClass(HWND phWnd)
	:hWnd(phWnd)
{
	init();
}


GameClass::~GameClass()
{
	delete(DCManager);
	
}

int GameClass::Run(float dt)
{
	Logic();
	Render(dt);
	return 0;
}

int GameClass::init()
{
	DCManager = new DeviceContextManager(hWnd);

	keyboardInput = new Input();
	
	player = new PlayerClass(DCManager->GetMemoryDC(), vec2(325, 475),PlaneSpeed);
	
	player->LoadCImage(PartialPlane,PartialPlaneMask);
	
	bg = new BackgroundClass(DCManager->GetMemoryDC());
	
	return 0;
}

int GameClass::Logic()
{
	player->Logic(keyboardInput->GetInputFlag());

	return 0;
}

int GameClass::Render(float dt)
{

	bg->Render(dt);

	player->Render(dt);
	
	DCManager->DrawMemoryDCtoHDC();
	
	return 0;
}
