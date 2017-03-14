#pragma once
#include "GameObjectClass.h"
class ProjectileClass :
	public GameObjectClass
{
public:
	ProjectileClass(HDC pHDC, vec2 pPos, bool);
	~ProjectileClass();

	virtual int Render(float);
	virtual int Logic(int);
private:
	bool isFromPlayer;
	bool isDead;

	int CheckIsDead();
};

