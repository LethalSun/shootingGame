#include "pch.h"
#include "PlayerStopMovement.h"
#include "PlayerYDirectionMovement.h"
#include "PlayerXDirectionMovement.h"
#include "PlayerChangeMovement.h"
#include "PlayerClass.h"

PlayerXDirectionMovement::PlayerXDirectionMovement()
	:noRightLeft(0)
	,frameCount{0}
{
}


PlayerXDirectionMovement::~PlayerXDirectionMovement()
{
}

PlayerState * PlayerXDirectionMovement::HandleInput(PlayerClass & pPlayer, int pInput)
{
	if (pInput == State::TOP || pInput == State::BOTTOM)
	{
		return new PlayerYDirectionMovement();
	}
	else if (pInput == State::BOTTOM_LEFT
		|| pInput == State::LEFT
		|| pInput == State::TOP_LEFT)
	{
		if (noRightLeft == 1)
		{
			return new PlayerChangeMovement();
		}
		noRightLeft = 2;
	}
	else if (pInput == State::BOTTOM_RIGHT
		|| pInput == State::RIGHT
		|| pInput == State::TOP_RIGHT)
	{
		if (noRightLeft == 2)
		{
			return new PlayerChangeMovement();
		}
		noRightLeft = 1;
	}
	else if (pInput == 0)
	{
		return new PlayerStopMovement();
	}
	return nullptr;
}

void PlayerXDirectionMovement::update(PlayerClass & pPlayer)
{
	bool tempBool =false;
	
	if (noRightLeft == 2)
	{
		tempBool = true;
	}

	vec2 tempVec = vec2((float)framePoint[frameCount], 1.f);
	++frameCount;
	frameCount = frameCount % 4;

	pPlayer.SetAnimationVec(tempVec, tempBool);
}
