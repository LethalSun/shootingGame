#pragma once
class ProjectileClass;

class GunClass
{
public:
	GunClass(HDC, float,vec2,bool);
	~GunClass();

	int Shot(vec2 pos);
	int SetSpeed(float);
	int Render(float);
	int Logic(int);

	int SetCollideRadius(int);
	std::vector<ProjectileClass*>* GetBulletVector();

private:

	HDC hDC;

	float bulletSpeed;
	vec2 dPosition;

	int countForDelay;

	int MakeBullet();
	int CheckBullets();
	std::vector<ProjectileClass*> bullets;

	bool isPlayer;

};

