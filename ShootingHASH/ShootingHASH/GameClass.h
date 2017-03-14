#pragma once

//NEW CLASS
class DeviceContextManager;
class Input;
class BackgroundClass;
class PlayerClass;

//OLDCLASS
class Player;

class GameClass
{
public:

	GameClass(HWND);
	~GameClass();

	int Run(float);
private:
	//member
	DeviceContextManager* DCManager;
	
	BackgroundClass* bg;

	Input* keyboardInput;
	
	PlayerClass* player;
	
	HWND hWnd;

	//method
	int init();
	int Logic();
	int Render(float);
};

