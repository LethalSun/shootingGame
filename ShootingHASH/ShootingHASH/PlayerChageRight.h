#pragma once
#include "PlayerState.h"
class PlayerChageRight :
	public PlayerState
{
public:
	PlayerChageRight();
	~PlayerChageRight();

	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);

private:
	const int framePoint[4]{ 457,609,761,913 };
	int frameCount;
};

