#include "pch.h"
#include "PlayerClass.h"
#include "PlayerStopMovement.h"
#include "PlayerYDirectionMovement.h"
#include "PlayerXDirectionMovement.h"
#include "PlayerChangeMovement.h"

PlayerYDirectionMovement::PlayerYDirectionMovement()
:frameCount{0}
{
	delta = vec2{ 0.f,0.f };
}


PlayerYDirectionMovement::~PlayerYDirectionMovement()
{
}

PlayerState * PlayerYDirectionMovement::HandleInput(PlayerClass & pPlayer, int pInput)
{
	if (pInput == State::TOP)
	{
		//delta = vec2{ 0.f,-1.f };
	}
	else if (pInput == State::BOTTOM)
	{
		//delta = vec2{ 0.f,1.f };
	}
	else if (pInput == State::BOTTOM_LEFT
		|| pInput == State::BOTTOM_RIGHT
		|| pInput == State::LEFT
		|| pInput == State::RIGHT
		|| pInput == State::TOP_LEFT
		|| pInput == State::TOP_RIGHT)
	{
		return new PlayerChangeMovement();
	}
	else if (pInput == 0)
	{
		return new PlayerStopMovement();
	}
	return nullptr;

}

void PlayerYDirectionMovement::update(PlayerClass& pPlayer)
{
	
	vec2 tempVec = vec2(framePoint[frameCount], 1.f);

	++frameCount;
	frameCount = frameCount % 4;
	pPlayer.SetAnimationVec(tempVec,false);
}
