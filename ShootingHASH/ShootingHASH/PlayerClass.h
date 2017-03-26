#pragma once
#include "GameObjectClass.h"

class PlayerState;
class GunClass;

class PlayerClass :public GameObjectClass
{
private:
	enum State
	{
		TOP = 1,
		RIGHT = 2,
		TOP_RIGHT = 3,
		BOTTOM = 4,
		BOTTOM_RIGHT = 6,
		LEFT = 8,
		TOP_LEFT = 9,
		BOTTOM_LEFT = 12,
		ATTACK = 16,
		SKILL1 = 32,
		SKILL2 = 64
	};
public:
	PlayerClass(HDC, vec2, float);
	~PlayerClass();

	
	virtual int Render(float);
	virtual int Logic(int);

	int SetAnimationVec(vec2,bool);
private:

	int inputFlag;
	const int OxF;
	int direction;

	const float planeSpeed;
	vec2 dPosition;

	//for Logic Method
	int TakeInputFlag(int);
	int CalculateNextPosition();

	//int identifyNextAction();
	int HandleInput();
	int StateUpdate();

	//for Render Method

	vec2 imgStart;
	vec2 imgEnd;
	bool isLeft;
	PlayerState* state;

	// Gun
	int CheckActionFlag();
	int action;
	GunClass* gun;
};

