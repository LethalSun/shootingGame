#include "pch.h"
#include "ProjectileClass.h"


ProjectileClass::ProjectileClass(HDC pHDC, vec2 pPos, bool pIsFromPlayer)
	:GameObjectClass(pHDC, pPos)
	,isDead(false)
	,isFromPlayer(pIsFromPlayer)
	, dPosition{0.f,-1.0f}
{
}


ProjectileClass::~ProjectileClass()
{
}

int ProjectileClass::Render(float dt)
{
	if (isDead == true)
	{
		return 0;
	}
	auto vec = GetPosition();
	BitBlt(imgStart, imgEnd, vec, true);
	return 0;
}

int ProjectileClass::Logic(int param)
{
	if (isDead == true)
	{
		return 0;
	}
	auto tempPos = GetPosition();
	tempPos = tempPos + dPosition * projectileSpeed;
	SetPosition(tempPos);
	return 0;
}

bool ProjectileClass::IsDead()
{
	return isDead;
}

int ProjectileClass::CheckDead()
{
	isDead = true;
	return 0;
}

int ProjectileClass::CheckLive()
{
	isDead = false;
	return 0;
}

int ProjectileClass::SetSpeed(float pProjectileSpeed)
{
	projectileSpeed = pProjectileSpeed;
	return 0;
}

int ProjectileClass::SetAnimationVec(vec2 pImgStart, vec2 pImgEnd)
{
	imgStart = pImgStart;
	imgEnd = pImgEnd;
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
