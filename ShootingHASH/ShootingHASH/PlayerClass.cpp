#include "pch.h"
#include "PlayerClass.h"
#include "PlayerState.h"
#include "PlayerStopMovement.h"
#include "PlayerYDirectionMovement.h"
#include "PlayerXDirectionMovement.h"
#include "PlayerChangeMovement.h"
#include "PlayerChageRight.h"
#include "PlayerChangeLeft.h"
#include "PlayerMoveBottom.h"
#include "PlayerMoveLeft.h"
#include "PlayerMoveRight.h"
#include "PlayerMoveTop.h"
#include "PlayerStopMove.h"
#include "GunClass.h"

PlayerClass::PlayerClass(HDC phDC, vec2 pVec2,float pSpeed)
	:GameObjectClass{ phDC ,pVec2 }
	, inputFlag{ 0 }
	, OxF(15)
	, dPosition()
	, planeSpeed{pSpeed}
	, imgEnd{ 150.f,125.f }
	, isLeft(false)
{
	state = new PlayerStopMove();
	gun = new GunClass(phDC, PlaneSpeed);
}


PlayerClass::~PlayerClass()
{
}

int PlayerClass::TakeInputFlag(int pInputFlag)
{
	inputFlag = pInputFlag;
	return 0;
}

int PlayerClass::Render(float dt)
{
	vec2 pos = GetPosition();
	pos += dPosition;
	BitBlt(imgStart, imgEnd, pos,isLeft);
	gun->Render(dt);
	return 0;
}

int PlayerClass::Logic(int pInputBitFlag)
{
	TakeInputFlag(pInputBitFlag);
	HandleInput();
	StateUpdate();
	CalculateNextPosition();
	gun->Logic(int(0));

	return 0;
}

int PlayerClass::CalculateNextPosition()
{
	direction = inputFlag & OxF;

	dPosition = vec2(0.f, 0.f);

	switch (direction)
	{
		case State::TOP:
		{
			dPosition += vec2(0.f, -planeSpeed);
			break;
		}
		case State::TOP_RIGHT:
		{
			dPosition += vec2(planeSpeed, -planeSpeed);
			break;
		}
		case State::RIGHT:
		{
			dPosition += vec2(planeSpeed, 0.f);
			break;
		}
		case State::BOTTOM_RIGHT:
		{
			dPosition += vec2(planeSpeed, planeSpeed);
			break;
		}
		case State::BOTTOM:
		{
			dPosition += vec2(0.f, planeSpeed);
			break;
		}
		case State::BOTTOM_LEFT:
		{
			dPosition += vec2(-planeSpeed, planeSpeed);
			break;
		}
		case State::LEFT:
		{
			dPosition += vec2(-planeSpeed, 0.f);
			break;
		}
		case State::TOP_LEFT:
		{
			dPosition += vec2(-planeSpeed, -planeSpeed);
			break;
		}
		default:
		{
			break;
		}
			
	}

	MoveBy(dPosition);

	return 0;
}

int PlayerClass::HandleInput()
{
	PlayerState* pTempState = state->HandleInput(*this, direction);
	if (pTempState != NULL)
	{
		delete state;
		state = pTempState;
	}

	return 0;
}

int PlayerClass::StateUpdate()
{
	state->update(*this);
	return 0;
}

int PlayerClass::CheckActionFlag()
{
	action = inputFlag & int(112);

	return 0;
}

int PlayerClass::SetAnimationVec(vec2 pPos ,bool pIsleft)
{
	imgStart = pPos;
	isLeft = pIsleft;
	return 0;
}
