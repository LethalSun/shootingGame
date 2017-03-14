#include "pch.h"
#include "PlayerChageRight.h"
#include "PlayerMoveRight.h"
#include "PlayerMoveTop.h"
#include "PlayerMoveBottom.h"
#include "PlayerChangeLeft.h"
#include "PlayerStopMove.h"
#include "PlayerClass.h"
PlayerChageRight::PlayerChageRight()
	:frameCount(0)
{
}


PlayerChageRight::~PlayerChageRight()
{
}

PlayerState * PlayerChageRight::HandleInput(PlayerClass & pPlayer, int pInput)
{
	if (frameCount == 4)
	{
		return new PlayerMoveRight();
	}

	switch (pInput)
	{
	case State::TOP:
	{
		return new PlayerMoveTop();
		break;
	}
	case State::TOP_RIGHT:
	{
		return nullptr;
		break;
	}
	case State::TOP_LEFT:
	{
		return new PlayerChangeLeft();
		break;
	}
	case State::BOTTOM:
	{
		return new PlayerMoveBottom();
		break;
	}
	case State::BOTTOM_LEFT:
	{
		return new PlayerChangeLeft();
		break;
	}
	case State::BOTTOM_RIGHT:
	{
		return nullptr;
		break;
	}
	case State::LEFT:
	{
		return new PlayerChangeLeft();
		break;
	}
	case State::RIGHT:
	{
		return nullptr;
		break;
	}
	case 0:
	{
		return new PlayerStopMove();
	}
	default:
	{
		break;
	}
	}
	return nullptr;
}

void PlayerChageRight::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2(framePoint[frameCount], 1.f);

	++frameCount;
	pPlayer.SetAnimationVec(tempVec, false);
}
