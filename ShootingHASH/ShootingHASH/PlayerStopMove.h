#pragma once
#include "PlayerState.h"
class PlayerStopMove :
	public PlayerState
{
public:
	PlayerStopMove();
	~PlayerStopMove();
	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);

private:
	int frameCount;
	int framePoint[4]{ 1,153,305,457 };
};

