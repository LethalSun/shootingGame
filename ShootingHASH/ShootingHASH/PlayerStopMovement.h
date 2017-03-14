#pragma once
#include "PlayerState.h"
class PlayerStopMovement :
	public PlayerState
{
public:
	PlayerStopMovement();
	~PlayerStopMovement();

	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);

private:
	int frameCount;
	int framePoint[4]{1,153,305,457};
};

