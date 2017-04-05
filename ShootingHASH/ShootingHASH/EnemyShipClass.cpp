#include "pch.h"
#include "EnemyShipClass.h"


EnemyShipClass::EnemyShipClass(HDC phDC, vec2 pVec2)
	:GameObjectClass{ phDC ,pVec2 }
{
}


EnemyShipClass::~EnemyShipClass()
{
}

int EnemyShipClass::Render(float dt)
{
	if (isDead == true)
	{
		return 0;
	}

	appearTime -= dt;


	if (appearTime > 0.f)
	{
		return 0;
	}

	vec2 pos = GetPosition();
	pos += dPos;
	BitBlt(vec2{ EnemyShipFrame[imgStartFrame] ,EnemyShipFrame[imgStartFrame + 1] }
		, vec2{ EnemyShipFrame[imgStartFrame + 2] ,EnemyShipFrame[imgStartFrame + 3] },
		pos, true);
	return 0;
}

int EnemyShipClass::Logic(int)
{
	if (isDead == true)
	{
		return 0;
	}

	if (appearTime > 0.f)
	{
		return 0;
	}

	MoveBy(dPos);

	CheckIsDead();
	return 0;
}

int EnemyShipClass::SetEnemyType(int pStartFrame)
{
	imgStartFrame = pStartFrame;
	return 0;
}

int EnemyShipClass::SetAppearTime(float pAppearTime)
{
	appearTime = pAppearTime;
	return 0;
}

int EnemyShipClass::SetDPosition(vec2 pDPos)
{
	dPos = pDPos;
	return 0;
}

int EnemyShipClass::SetIsNotDead()
{
	isDead = false;
	return 0;
}

int EnemyShipClass::SetIsDead()
{
	isDead = true;
	return 0;
}

int EnemyShipClass::SetCollideRadius(int pCollideRadius)
{
	collideRadius = pCollideRadius;
	return 0;
}

int EnemyShipClass::GetCollideRadius()
{
	return collideRadius;
}

bool EnemyShipClass::IsDead()
{
	return isDead;
}

int EnemyShipClass::GetHp()
{
	return hp;
}

int EnemyShipClass::SetHp(int pHP)
{
	hp = pHP;
	return 0;
}

int EnemyShipClass::CheckIsDead()
{
	vec2 position = GetPosition();

	if (position.x >= 700 || position.x <= 0)
	{
		isDead = true;
		return 0;
	}

	if (position.y <= 0 || position.y >= 600)
	{
		isDead = true;
		return 0;
	}
	
	if (hp == 0)
	{
		isDead = true;
		return 0;
	}

	return 0;
}

