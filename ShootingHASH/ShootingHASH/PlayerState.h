#pragma once

class PlayerClass;

class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState();
	virtual PlayerState* HandleInput(PlayerClass& pPlayer, int pInput) = 0;
	virtual void update(PlayerClass& pPlayer) = 0;

	enum State
	{
		TOP = 1,
		RIGHT = 2,
		TOP_RIGHT = 3,
		BOTTOM = 4,
		BOTTOM_RIGHT = 6,
		LEFT = 8,
		TOP_LEFT = 9,
		BOTTOM_LEFT = 12,
		ATTACK = 16,
		SKILL1 = 32,
		SKILL2 = 64
	};

private:
};

