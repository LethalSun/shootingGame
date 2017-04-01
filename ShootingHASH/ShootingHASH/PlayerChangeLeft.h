#pragma once
#include "PlayerState.h"
class PlayerChangeLeft :
	public PlayerState
{
public:
	PlayerChangeLeft();
	~PlayerChangeLeft();
	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);
private:
	const int framePoint[4]{ PlayerPlaneFramePoint[3],PlayerPlaneFramePoint[4],PlayerPlaneFramePoint[5],PlayerPlaneFramePoint[6] };
	int frameCount;
};

