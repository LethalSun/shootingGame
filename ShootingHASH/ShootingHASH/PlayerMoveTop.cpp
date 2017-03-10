#include "pch.h"
#include "PlayerMoveTop.h"
#include "PlayerChageRight.h"
#include "PlayerChangeLeft.h"
#include "PlayerMoveBottom.h"
#include "PlayerStopMove.h"
#include "PlayerClass.h"

PlayerMoveTop::PlayerMoveTop()
	:frameCount(0)
{
}


PlayerMoveTop::~PlayerMoveTop()
{
}

PlayerState * PlayerMoveTop::HandleInput(PlayerClass & pPlayer, int pInput)
{
	switch (pInput)
	{
		case State::TOP:
		{
			return nullptr;
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
			return new PlayerStopMove();
			break;
		}
		default:
		{
			break;
		}
	}
	
}

void PlayerMoveTop::update(PlayerClass & pPlayer)
{
	vec2 tempVec = vec2(framePoint[frameCount], 1.f);
	++frameCount;
	frameCount = frameCount % 4;

	pPlayer.SetAnimationVec(tempVec, false);
}
