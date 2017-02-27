#pragma once
class Player
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
	Player(HDC);
	~Player();

	int setInputFlag(int);
	int bitToState();
private:
	HDC memoryDC;
	
	int positionX;
	int positionY;

	int inputBitflag;

};

