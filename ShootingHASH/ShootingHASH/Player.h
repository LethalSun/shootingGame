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

	int LoadCImage();

	int setInputFlag(int);

	int Logic(float);
	int MoveBy(int, int);
	int MoveTo(int, int);
	int GetPosition(int*, int*);

	int Draw(float);

private:
	HDC memoryDC;
	
	int positionX;
	int positionY;
	int attackFlag;
	int skill1Flag;
	int skill2Flag;

	int inputBitFlag;

	CImage imgPlane;
	CImage imgPlaneMasking;
	CImage imgEngineGlow;
	CImage imgEngineGlowMasking;



	int interpretInput();
	
	int Animation();

	int SetDirectionByInput();
	bool isTop();
	bool isBottom();
	bool isRight();
	bool isLeft();
	bool isXMax();
	bool isXMin();
	bool isYMax();
	bool isYmin();

	int SetActionFlagByInput();
};

