#pragma once
#include "PlayerState.h"
class PlayerChangeMovement :
	public PlayerState
{
public:
	PlayerChangeMovement();
	~PlayerChangeMovement();

	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput);
	virtual void update(PlayerClass& pPlayer);

private:
	const int frame[4]{ 457,609,761,913 };
	int noRightLeft;
	int frameCount;
	vec2 delta;

	int setDelta(int);
};

