#include "pch.h"
#include "ProjectileClass.h"


ProjectileClass::ProjectileClass(HDC pHDC, vec2 pPos, bool pIsFromPlayer)
	:GameObjectClass(pHDC, pPos)
	,isDead(false)
	,isFromPlayer(pIsFromPlayer)
{
}


ProjectileClass::~ProjectileClass()
{
}

int ProjectileClass::Render(float)
{

	return 0;
}

int ProjectileClass::Logic(int)
{

	return 0;
}

int ProjectileClass::CheckIsDead()
{
	vec2 position = GetPosition();

	if(position.x >= 700 && position.x<=0)
	{
		isDead = true;
		return 0;
	}

	if (position.y <= 0 && position.y >= 600)
	{
		isDead = true;
		return 0;
	}
	return 0;
}
