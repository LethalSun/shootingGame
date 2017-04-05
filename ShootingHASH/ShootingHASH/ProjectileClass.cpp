#include "pch.h"
#include "ProjectileClass.h"


ProjectileClass::ProjectileClass(HDC pHDC, vec2 pPos, bool pIsFromPlayer)
	:GameObjectClass(pHDC, pPos)
	,isDead(true)
	,isFromPlayer(pIsFromPlayer)
	, dPosition{0.f,1.f}
{
}


ProjectileClass::~ProjectileClass()
{
}

int ProjectileClass::SetDPos(vec2 pUnitVec)
{
	dPosition = pUnitVec;
	return 0;
}

int ProjectileClass::Render(float dt)
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

	if (appearTime > 0.f)
	{
		return 0;
	}
	auto tempPos = GetPosition();
	tempPos = tempPos + dPosition * projectileSpeed;
	SetPosition(tempPos);
	CheckIsDead();
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

int ProjectileClass::SetBulletType(int pFrame)
{
	imgStart = vec2{ EnemyBulletFrame[pFrame] ,EnemyBulletFrame[pFrame + 1] };
	imgEnd = vec2{ EnemyBulletFrame[pFrame + 2] ,EnemyBulletFrame[pFrame + 3] };
	return 0;
}

int ProjectileClass::SetAppearTime(float pAppearTime)
{
	appearTime = pAppearTime;
	return 0;
}

int ProjectileClass::SetIsNotDead()
{
	isDead = false;
	return 0;
}

int ProjectileClass::SetIsDead()
{
	isDead = true;
	return 0;
}

int ProjectileClass::SetCollideRadius(int pCollideRadius)
{
	collideRadius = pCollideRadius;
	return 0;
}

int ProjectileClass::GetCollideRadius()
{
	return collideRadius;
}

int ProjectileClass::SetDPosition(vec2 dPos)
{
	dPosition = dPos;
	return 0;
}

int ProjectileClass::CheckIsDead()
{
	vec2 position = GetPosition();

	if(position.x >= 700 || position.x<=0)
	{
		isDead = true;
		return 0;
	}

	if (position.y <= 0 || position.y >= 600)
	{
		isDead = true;
		return 0;
	}
	return 0;
}
