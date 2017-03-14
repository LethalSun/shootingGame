#pragma once
#include "PlayerState.h"
class PlayerMoveLeft :
	public PlayerState
{
public:
	PlayerMoveLeft();
	~PlayerMoveLeft();
	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);
private:
	const int framePoint[4]{ 913,1065,1217,1369 };
	int frameCount;
};

