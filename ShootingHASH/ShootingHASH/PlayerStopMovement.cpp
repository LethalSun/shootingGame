#include "pch.h"
#include "PlayerClass.h"
#include "PlayerStopMovement.h"
#include "PlayerYDirectionMovement.h"
#include "PlayerXDirectionMovement.h"

PlayerStopMovement::PlayerStopMovement()
:frameCount{0}
{
}


PlayerStopMovement::~PlayerStopMovement()
{
}

PlayerState * PlayerStopMovement::HandleInput(PlayerClass & pPlayer, int pInput)
{
	if (pInput == State::BOTTOM || pInput == State::TOP)
	{
		return new PlayerYDirectionMovement();
	}
	else if (pInput == State::BOTTOM_LEFT
		|| pInput == State::BOTTOM_RIGHT
		|| pInput == State::LEFT
		|| pInput == State::RIGHT
		|| pInput == State::TOP_LEFT
		|| pInput == State::TOP_RIGHT)
	{
		return new PlayerXDirectionMovement();
	}

	return nullptr;
}

void PlayerStopMovement::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2((float)framePoint[frameCount], 1.f);

	++frameCount;
	frameCount = frameCount % 4;

	pPlayer.SetAnimationVec(tempVec,false);
}
