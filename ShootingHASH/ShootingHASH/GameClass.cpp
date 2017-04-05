#include "pch.h"
#include "GameClass.h"
#include "DeviceContextManager.h"
#include "BackgroundClass.h"
#include "Input.h"
#include "Player.h"
#include "PlayerClass.h"
#include "UIManagerClass.h"
#include "EnemyClass.h"
#include "EnemyManagerClass.h"
#include "CollideManager.h"

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

	UI = new UIManagerClass(DCManager->GetMemoryDC(),vec2(0,0));

	UI->LoadCImage(PartialUi, PartialUiMasking);

	enemyManager = new EnemyManagerClass(DCManager->GetMemoryDC());

	enemyManager->initEnemyAndBullet();

	collide = new CollideManager(DCManager->GetHDC());

	collide->SetPlayer(player);
	collide->SetPlayerBullet(player->GetBulletVector());
	collide->SetEnemy(enemyManager->GetEnemyArray());
	collide->SetEnemyBullet(enemyManager->GetBulletArray());

	//SetEnemyArray();

	return 0;
}

int GameClass::Logic()
{
	//tempEnemy->Logic(int(0));

	enemyManager->Logic(int(0));

	player->Logic(keyboardInput->GetInputFlag());

	UI->SetHpBar(player->GetHP());
	
	UI->Logic(int(0));

	collide->Logic(int(0));
	return 0;
}

int GameClass::Render(float dt)
{

	bg->Render(dt);

	//tempEnemy->Render(dt);

	enemyManager->Render(dt);

	player->Render(dt);

	UI->Render(dt);

	DCManager->DrawMemoryDCtoHDC();

	
	return 0;
}

int GameClass::Delete()
{
	delete collide;
	delete enemyManager;
	delete tempEnemy;
	delete UI;
	delete bg;
	delete player;
	delete keyboardInput;
	delete DCManager ;
	return 0;
}

int GameClass::SetEnemyArray()
{

	tempEnemy = new EnemyClass(DCManager->GetMemoryDC(),vec2(100.f,100.f),PlaneSpeed/10);
	tempEnemy->LoadCImage(PartialEnemy, PartialEnemyMasking);
	tempEnemy->SetIsNotDead();
	tempEnemy->init(vec2(100.f, 100.f), PlaneSpeed/10);
	tempEnemy->SetMovementAndAttack(1, vec2{ 1,1 }, 1, vec2{ 0,1 },5, 5.f);
	return 0;
}
