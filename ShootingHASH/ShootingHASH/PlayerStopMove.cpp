#include "pch.h"
#include "PlayerStopMove.h"
#include "PlayerMoveTop.h"
#include "PlayerChageRight.h"
#include "PlayerChangeLeft.h"
#include "PlayerMoveBottom.h"
#include "PlayerClass.h"

PlayerStopMove::PlayerStopMove()
	:frameCount(0)
{
}


PlayerStopMove::~PlayerStopMove()
{
}

PlayerState * PlayerStopMove::HandleInput(PlayerClass & pPlayer, int pInput)
{
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
		return new PlayerChageRight();
		break;
	}
	case State::LEFT:
	{
		return new PlayerChangeLeft();
		break;
	}
	case State::RIGHT:
	{
		return new PlayerChageRight();
		break;
	}
	case 0:
	{
		return nullptr;
	}
	default:
	{
		break;
	}
	}
	return nullptr;
}

void PlayerStopMove::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2(framePoint[frameCount], 1.f);

	++frameCount;
	frameCount = frameCount % 4;
	pPlayer.SetAnimationVec(tempVec, false);
}
