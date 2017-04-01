#pragma once
#include "ProjectileClass.h"
class GunClass
{
public:
	GunClass(HDC, float);
	~GunClass();

	int Shot(vec2 pos);
	int SetSpeed(float);
	int Render(float);
	int Logic(int);

private:

	HDC hDC;

	float bulletSpeed;

	int countForDelay;

	int MakeBullet();
	int CheckBullets();
	std::vector<ProjectileClass*> bullets;

};

