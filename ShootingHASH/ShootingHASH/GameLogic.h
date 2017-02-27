#pragma once
class GameLogic
{
private:
	enum State
	{
		TOP = 1,
		RIGHT = 2,
		BOTTOM = 4,
		LEFT = 8,
		ATTACK = 16,
		SKILL1 = 32,
		SKILL2 = 64
	};
public:
	GameLogic();
	~GameLogic();

	int SetinputFromKeyboard(int);
	int Logic();


private:

	int inputBitFlag;

};

