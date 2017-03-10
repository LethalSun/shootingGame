#include "pch.h"
#include "PlayerMoveBottom.h"
#include "PlayerMoveTop.h"
#include "PlayerChageRight.h"
#include "PlayerChangeLeft.h"
#include "PlayerStopMove.h"
#include "PlayerClass.h"
PlayerMoveBottom::PlayerMoveBottom()
	:frameCount(0)
{
}


PlayerMoveBottom::~PlayerMoveBottom()
{
}

PlayerState * PlayerMoveBottom::HandleInput(PlayerClass & pPlayer, int pInput)
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
		return nullptr;
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
		return new PlayerStopMove();
	}
	default:
	{
		break;
	}
	}
	return nullptr;
}

void PlayerMoveBottom::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2(framePoint[frameCount], 1.f);

	++frameCount;
	frameCount = frameCount % 4;
	pPlayer.SetAnimationVec(tempVec, false);
}
