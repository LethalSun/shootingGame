#include "pch.h"
#include "EnemyClass.h"
#include "GunClass.h"

EnemyClass::EnemyClass(HDC phDC, vec2 pVec2,float pSpeed)
	:GameObjectClass{ phDC ,pVec2 }
	, planeSpeed{ pSpeed }
{
	gun = new GunClass(phDC, BulletSpeed);
}


EnemyClass::~EnemyClass()
{
}

int EnemyClass::Render(float)
{
	return 0;
}

int EnemyClass::Logic(int)
{
	return 0;
}

int EnemyClass::init(vec2 pVec2, float pSpeed)
{
	SetPosition(pVec2);
	planeSpeed = pSpeed;
	return 0;
}

int EnemyClass::SetMovementAndAttack(int pMovement, int pAttack, float pAppearTime)
{
	movement = pMovement;
	attackType = pAttack;
	return 0;
}

int EnemyClass::CheckIsDead()
{
	vec2 position = GetPosition();

	if (position.x >= 700 || position.x <= 0)
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
