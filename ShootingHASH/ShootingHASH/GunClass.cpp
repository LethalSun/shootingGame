#include "pch.h"
#include "GunClass.h"
#include "ProjectileClass.h"

GunClass::GunClass(HDC phDC, float pBulletSpeed)
	:hDC{phDC}
	,bulletSpeed{pBulletSpeed}
{
	MakeBullet();
}


GunClass::~GunClass()
{
}

int GunClass::Shot(vec2 pPos)
{
	for (auto available : bullets)
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

	for (auto available : bullets)
	{
		available->Render(dt);
	}

	return 0;
}

int GunClass::Logic(int pInt)
{
	for (auto available : bullets)
	{
		available->Logic(pInt);
	}

	return 0;
}

int GunClass::MakeBullet()
{
	for (int i = 0; i < NumBullet; i++)
	{
		auto tempBullet = new ProjectileClass(hDC, vec2{800,600},true);
		tempBullet->LoadCImage(PartialPlayerProjectile, PartialPlayerProjectileMasking);
		tempBullet->SetAnimationVec(vec2{ 1,1 }, vec2{ 45,98 });
		bullets.push_back(tempBullet);
	}

	return 0;
}

int GunClass::CheckBullets()
{
	return 0;
}
