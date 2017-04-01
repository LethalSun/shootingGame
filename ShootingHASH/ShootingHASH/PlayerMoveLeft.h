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
	const int framePoint[4]{ PlayerPlaneFramePoint[6],PlayerPlaneFramePoint[7],PlayerPlaneFramePoint[8],PlayerPlaneFramePoint[9] };
	int frameCount;
};

