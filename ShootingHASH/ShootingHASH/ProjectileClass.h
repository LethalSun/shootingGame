#pragma once
#include "GameObjectClass.h"
class ProjectileClass :
	public GameObjectClass
{
public:
	ProjectileClass(HDC pHDC, vec2 pPos, bool);
	~ProjectileClass();

	int init(vec2);
	virtual int Render(float);
	virtual int Logic(int);

	bool IsDead();
	int CheckDead();
	int CheckLive();

	int SetSpeed(float);
	int SetAnimationVec(vec2, vec2);
private:
	bool isFromPlayer;
	bool isDead;
	float projectileSpeed;

	vec2 dPosition;

	vec2 imgStart;
	vec2 imgEnd;
	
	int CheckIsDead();
};

