#pragma once
class Draw;
class Input;
class Player;
class GameClass
{
public:

	GameClass(HWND);
	~GameClass();

	int GetKeyboardInput();
	int Logic();
	int Run(float);
private:
	int init();

	Input* KeyboardInput;
	Player* Player1;
	Draw* Drawer;
	HWND hWnd;
};

