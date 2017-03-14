#include "pch.h"
#include "Player.h"
#include "Loading.h"
Player::Player(HDC pMemoryDC)
	:memoryDC(pMemoryDC)
	,positionX(325)
	,positionY(475)
	,inputBitFlag(0)
	,attackFlag(0)
	,skill1Flag(0)
	,skill2Flag(0)
{
} 


Player::~Player()
{
}

int Player::setInputFlag(int pBitflag)
{
	inputBitFlag = pBitflag;
	return 0;
}

int Player::Logic(float dt)
{
	return 0;
}

int Player::MoveBy(int px, int py)
{
	positionX += px;
	positionY += py;
	return 0;
}

int Player::MoveTo(int px, int py)
{
	positionX = px;
	positionY = py;
	return 0;
}

int Player::GetPosition(int *px, int *py)
{
	*px = positionX;
	*py = positionY;
	return 0;
}

int Player::Draw(float)
{

	return 0;
}

int Player::LoadCImage()
{
	//WCHAR path[256];
	//GetCurrentDirectory(sizeof(path), path);
	//
	//WCHAR temp[256];
	//
	//wcscpy_s(temp, path);
	//wcscat_s(temp, Plane);
	//
	//imgPlane.Load(temp);
	//
	//wcscpy_s(temp, path);
	//wcscat_s(temp, PlaneMask);
	//
	//imgPlaneMasking.Load(temp);
	//
	//wcscpy_s(temp, path);
	//wcscat_s(temp, EngineGlow);
	//
	//imgEngineGlow.Load(temp);
	//
	//wcscpy_s(temp, path);
	//wcscat_s(temp, EngineGlowMask);
	//
	//imgEngineGlowMasking.Load(temp);
	return 0;
}

int Player::interpretInput()
{
	SetDirectionByInput();

	SetActionFlagByInput();
	return 0;
}

int Player::Animation()
{
	//imgPlaneMasking.BitBlt(memoryDC,
	//	100,
	//	100,
	//	150,
	//	125,
	//	0,
	//	0,
	//	SRCAND);
	//
	//imgPlane.BitBlt(memoryDC,
	//	100,
	//	100,
	//	150,
	//	125,
	//	0,
	//	0,
	//	SRCPAINT);
	//
	//imgEngineGlowMasking.BitBlt(memoryDC,
	//	200,
	//	100,
	//	150,
	//	125,
	//	0,
	//	0,
	//	SRCAND);
	//
	//imgEngineGlow.BitBlt(memoryDC,
	//	200,
	//	100,
	//	150,
	//	125,
	//	0,
	//	0,
	//	SRCPAINT);
	//
	//
	//return 0;
	return 0;
}

int Player::SetDirectionByInput()
{
	if (isTop())
	{
		if (isYmin())
		{
			positionY = 0;
		}
		else
		{
			--positionY;
		}
	}
	else if (isBottom())
	{
		if (isYMax())
		{
			positionY = 600;
		}
		else
		{
			++positionY;
		}
	}
	else {}

	if (isRight())
	{
		if (isXMax())
		{
			positionX = 800;
		}
		else
		{
			++positionX;
		}
	}
	else if (isLeft())
	{
		if (isXMin())
		{
			positionX = 0;
		}
		else
		{
			--positionX;
		}
	}
	else {}
	return 0;
}

bool Player::isTop()
{
	if (inputBitFlag & State::TOP == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Player::isBottom()
{
	if (inputBitFlag & State::BOTTOM == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::isRight()
{
	if (inputBitFlag & State::RIGHT == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::isLeft()
{
	if (inputBitFlag & State::LEFT == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Player::isXMax()
{
	if (positionX < 800)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::isXMin()
{
	if (positionX > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
	
}

bool Player::isYMax()
{
	if (positionY < 600)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Player::isYmin()
{
	if (positionY > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int Player::SetActionFlagByInput()
{
	if (inputBitFlag & State::ATTACK)
	{
		attackFlag = 1;
	}

	if (inputBitFlag & State::SKILL1)
	{
		skill1Flag = 1;
	}

	if (inputBitFlag & State::SKILL2)
	{
		skill2Flag = 1;
	}
	return 0;
}
