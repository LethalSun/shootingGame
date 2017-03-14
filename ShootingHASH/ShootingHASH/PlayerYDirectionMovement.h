#pragma once
#include "PlayerState.h"
class PlayerYDirectionMovement :
	public PlayerState
{
public:
	PlayerYDirectionMovement();
	~PlayerYDirectionMovement();

	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);

private:
	int framePoint[4]{ 1,153,305,457 };
	int frameCount;
	vec2 delta;
};

