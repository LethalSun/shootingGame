#include "pch.h"
#include "GunClass.h"
#include "ProjectileClass.h"

GunClass::GunClass(HDC phDC, float pBulletSpeed, vec2 pDpos,bool pIsPlayer)
	:hDC{phDC}
	,bulletSpeed{pBulletSpeed}
	, dPosition{ pDpos }
	, countForDelay{0}
	, isPlayer{ pIsPlayer }
{
	MakeBullet();
}


GunClass::~GunClass()
{
	for (auto& bullet : bullets)
	{
		delete bullet;
	}
}

int GunClass::Shot(vec2 pPos)
{
	if (countForDelay != 0)
	{
		return 1;
	}

	for (auto& available : bullets)
	{
		if (available->IsDead() == true)
		{
			available->SetPosition(pPos);
			available->SetSpeed(bulletSpeed);
			available->CheckLive();
			break;
		}
	}
	return 0;
}

int GunClass::SetSpeed(float pBulletSpeed)
{
	bulletSpeed = pBulletSpeed;
	return 0;
}

int GunClass::Render(float dt)
{

	for (auto& available : bullets)
	{
		available->Render(dt);
	}

	return 0;
}

int GunClass::Logic(int pInt)
{
	//TODO: ÃÑ µô·¹ÀÌ
	++countForDelay;
	countForDelay %= 10;

	for (auto& available : bullets)
	{
		available->Logic(pInt);
	}

	return 0;
}

int GunClass::SetCollideRadius(int pRadius)
{
	for (auto& bullet : bullets)
	{
		bullet->SetCollideRadius(pRadius);
	}
	return 0;
}

std::vector<ProjectileClass*>* GunClass::GetBulletVector()
{
	return &bullets;
}

int GunClass::MakeBullet()
{
	if (isPlayer == true)
	{
		for (int i = 0; i < NumBullet; i++)
		{
			auto tempBullet = new ProjectileClass(hDC, vec2{ 800,600 }, true);
			tempBullet->LoadCImage(PartialPlayerProjectile, PartialPlayerProjectileMasking);
			tempBullet->SetAnimationVec(vec2{ ProjectileFramePoint[0],ProjectileFramePoint[1] }, vec2{ ProjectileFramePoint[2],ProjectileFramePoint[3] });
			tempBullet->SetDPos(dPosition);
			bullets.push_back(tempBullet);
		}
	}
	else
	{
		for (int i = 0; i < NumBullet; i++)
		{
			auto tempBullet = new ProjectileClass(hDC, vec2{ 800,600 }, true);
			tempBullet->LoadCImage(PartialEnemyBullet, PartialEnemyBulletMasking);
			tempBullet->SetAnimationVec(vec2{ EnemyProjectileFramePoint[0],EnemyProjectileFramePoint[1] }, vec2{ EnemyProjectileFramePoint[2],EnemyProjectileFramePoint[3] });
			tempBullet->SetDPos(dPosition);
			bullets.push_back(tempBullet);
		}
	}


	return 0;
}

int GunClass::CheckBullets()
{
	return 0;
}
