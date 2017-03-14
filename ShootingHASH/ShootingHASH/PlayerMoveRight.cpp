#include "pch.h"
#include "PlayerMoveRight.h"
#include "PlayerMoveTop.h"
#include "PlayerMoveBottom.h"
#include "PlayerChangeLeft.h"
#include "PlayerStopMove.h"
#include "PlayerClass.h"
PlayerMoveRight::PlayerMoveRight()
	:frameCount(0)
{
}


PlayerMoveRight::~PlayerMoveRight()
{
}

PlayerState * PlayerMoveRight::HandleInput(PlayerClass & pPlayer, int pInput)
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
		break;
	}
	default:
	{
		break;
	}
	}
	return nullptr;
}

void PlayerMoveRight::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2((float)framePoint[frameCount], 1.f);
	++frameCount;
	frameCount = frameCount % 4;

	pPlayer.SetAnimationVec(tempVec, false);
}
