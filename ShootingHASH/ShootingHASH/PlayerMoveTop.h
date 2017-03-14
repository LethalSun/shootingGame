#pragma once
#include "PlayerState.h"
class PlayerMoveTop :
	public PlayerState
{
public:
	PlayerMoveTop();
	~PlayerMoveTop();

	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);

private:
	int framePoint[4]{ 1,153,305,457 };
	int frameCount;
};

