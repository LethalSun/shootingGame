#pragma once
#include "GameObjectClass.h"
class ProjectileClass :
	public GameObjectClass
{
public:
	enum class BulletType {
		DiaBlue = 0,
		DiaRed = 4,
		FlowerBlue = 8,
		FlowerOrenge = 12,
		FlowerPurple = 16,
		MediumPurple = 20,
		MediumBlue = 24,
		MediumRed = 28,
		QuadBlue = 32,
		QuadPurple = 36,
		QuadRed = 40
	};
public:
	ProjectileClass(HDC pHDC, vec2 pPos, bool);
	~ProjectileClass();

	int SetDPos(vec2);
	virtual int Render(float);
	virtual int Logic(int);

	bool IsDead();
	int CheckDead();
	int CheckLive();

	int SetSpeed(float);
	int SetAnimationVec(vec2, vec2);
	int SetBulletType(int);
	int SetAppearTime(float);
	int SetIsNotDead();
	int SetIsDead();
	int SetCollideRadius(int);
	int GetCollideRadius();
	int SetDPosition(vec2 dPos);
private:
	bool isFromPlayer;
	bool isDead;
	float projectileSpeed;

	vec2 dPosition;
	float appearTime = 0.f;
	vec2 imgStart;
	vec2 imgEnd;
	int collideRadius;
	int CheckIsDead();
};

