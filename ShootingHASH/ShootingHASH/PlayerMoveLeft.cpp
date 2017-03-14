#include "pch.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveTop.h"
#include "PlayerMoveBottom.h"
#include "PlayerChageRight.h"
#include "PlayerStopMove.h"
#include "PlayerClass.h"
PlayerMoveLeft::PlayerMoveLeft()
	:frameCount(0)
{
}


PlayerMoveLeft::~PlayerMoveLeft()
{
}

PlayerState * PlayerMoveLeft::HandleInput(PlayerClass & pPlayer, int pInput)
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

void PlayerMoveLeft::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2((float)framePoint[frameCount], 1.f);
	++frameCount;
	frameCount = frameCount % 4;

	pPlayer.SetAnimationVec(tempVec, true);
}
