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
	const int framePoint[4]{ 457,609,761,913 };
	int frameCount;
};

