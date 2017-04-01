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
	int framePoint[4]{ PlayerPlaneFramePoint[0],PlayerPlaneFramePoint[1],PlayerPlaneFramePoint[2],PlayerPlaneFramePoint[3] };
	int frameCount;
};

