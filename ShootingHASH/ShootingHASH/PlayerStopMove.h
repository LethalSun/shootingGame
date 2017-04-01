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
	int framePoint[4]{ PlayerPlaneFramePoint[0],PlayerPlaneFramePoint[1],PlayerPlaneFramePoint[2],PlayerPlaneFramePoint[3] };
};

