#include "pch.h"
#include "PlayerChageRight.h"
#include "PlayerChangeLeft.h"
#include "PlayerMoveTop.h"
#include "PlayerMoveBottom.h"
#include "PlayerMoveLeft.h"
#include "PlayerStopMove.h"
#include "PlayerClass.h"
PlayerChangeLeft::PlayerChangeLeft()
	:frameCount(0)
{
}


PlayerChangeLeft::~PlayerChangeLeft()
{
}

PlayerState * PlayerChangeLeft::HandleInput(PlayerClass & pPlayer, int pInput)
{
	if (frameCount == 4)
	{
		return new PlayerMoveLeft();
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
		return new PlayerChageRight();
		break;
	}
	case State::TOP_LEFT:
	{
		return nullptr;
		break;
	}
	case State::BOTTOM:
	{
		return new PlayerMoveBottom();
		break;
	}
	case State::BOTTOM_LEFT:
	{
		return nullptr;
		break;
	}
	case State::BOTTOM_RIGHT:
	{
		return new PlayerChageRight();
		break;
	}
	case State::LEFT:
	{
		return nullptr;
		break;
	}
	case State::RIGHT:
	{
		return new PlayerChageRight();
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

void PlayerChangeLeft::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2(framePoint[frameCount], 1.f);

	++frameCount;
	pPlayer.SetAnimationVec(tempVec, true);
}
