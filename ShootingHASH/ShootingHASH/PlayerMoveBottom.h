#pragma once
#include "PlayerState.h"
class PlayerMoveBottom :
	public PlayerState
{
public:
	PlayerMoveBottom();
	~PlayerMoveBottom();

	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);
private:
	int framePoint[4]{ 1,153,305,457 };
	int frameCount;
};

