#include "pch.h"
#include "PlayerStopMovement.h"
#include "PlayerYDirectionMovement.h"
#include "PlayerXDirectionMovement.h"
#include "PlayerChangeMovement.h"
#include "PlayerStopMove.h"
PlayerChangeMovement::PlayerChangeMovement()
	:frameCount(0)
	, noRightLeft(0)
{
}


PlayerChangeMovement::~PlayerChangeMovement()
{
}

PlayerState * PlayerChangeMovement::HandleInput(PlayerClass & pPlayer, int pInput)
{
	if (pInput == State::TOP||pInput == State::BOTTOM)
	{
		frameCount = 0;
		return new PlayerYDirectionMovement();
	}
	else if (pInput == State::BOTTOM_LEFT
		|| pInput == State::LEFT
		|| pInput == State::TOP_LEFT)
	{
		++frameCount;
		noRightLeft = 2;
	}
	else if (pInput == State::BOTTOM_RIGHT
		|| pInput == State::RIGHT
		|| pInput == State::TOP_RIGHT)
	{
		++frameCount;
		noRightLeft = 1;
	}
	else if (pInput == 0)
	{
		noRightLeft = 0;
	}
	else if (frameCount == 4)
	{
		frameCount = 0;
		return new PlayerXDirectionMovement();
	}
	return nullptr;
}

void PlayerChangeMovement::update(PlayerClass & pPlayer)
{
}

//TODO : 바깥에서 하는게
int PlayerChangeMovement::setDelta(int pInput)
{
	switch (pInput)
	{
		case  State::BOTTOM_LEFT:
		{
			delta = vec2(1.f, 1.f);
		}
		case State::LEFT:
		{
			delta = vec2(1.f, 0.f);
		}
		case State::TOP_LEFT:
		{
			delta = vec2(1.f, -1.f);
		}
		case State::BOTTOM_RIGHT:
		{
			delta = vec2(1.f, -1.f);
		}
		case State::RIGHT:
		{
			delta = vec2(1.f, 0.f);
		}
		case State::TOP_RIGHT:
		{
			delta = vec2(-1.f, 1.f);
		}
		default:
		{
			break;
		}
	}
	return 0;
}
