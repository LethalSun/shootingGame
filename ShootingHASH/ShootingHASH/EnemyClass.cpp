#include "pch.h"
#include "EnemyClass.h"
#include "GunClass.h"

EnemyClass::EnemyClass(HDC phDC, vec2 pVec2,float pSpeed)
	:GameObjectClass{ phDC ,pVec2 }
	, planeSpeed{ pSpeed }

{
	gun = new GunClass(phDC, BulletSpeed, vec2{0.f,1.f},false);
}


EnemyClass::~EnemyClass()
{
}

int EnemyClass::Render(float dt)
{
	if (isDead == true)
	{
		BitBlt(imgStart, imgEnd, vec2{100,100}, isLeft);
		return 0;
	}

	appearTime -= dt;

	gun->Render(dt);
	vec2 pos = GetPosition();
	pos += dPosition;
	BitBlt(imgStart, imgEnd, pos, isLeft);
	return 0;
}

int EnemyClass::Logic(int)
{
	
	if (isDead == true)
	{
		return 0;
	}

	if (appearTime > 0.f)
	{
		return 0;
	}

	++frameCount;

	if (movement == 0)
	{
		MoveStraight();
	}
	else if (movement == 1)
	{
		MoveStopMove();
	}

	if (attackType == 0)
	{
		AttackStraight();
	}
	else if (attackType == 1)
	{
		AttackStopAttack();
	}

	CheckIsDead();
	return 0;
}

int EnemyClass::init(vec2 pVec2, float pSpeed)
{
	SetPosition(pVec2);
	planeSpeed = pSpeed;
	return 0;
}

int EnemyClass::SetMovementAndAttack(int pMovement, vec2 pMoveVec, int pAttack, vec2 pAttackVec, int pBulletNum, float pAppearTime)
{
	movement = pMovement;
	unitVec = pMoveVec;
	attackType = pAttack;
	appearTime = pAppearTime;
	bulletNum = pBulletNum *10;
	return 0;
}

int EnemyClass::SetIsNotDead()
{
	isDead = false;
	return 0;
}

int EnemyClass::SetIsDead()
{
	isDead = true;
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

int EnemyClass::MoveStraight()
{

	dPosition = vec2{ unitVec.x*planeSpeed,unitVec.y*planeSpeed };

	int frameNum = 0;
	if (unitVec.x == 0)
	{
		if (unitVec.y == 1)
		{
			frameNum = 9;
		}
		else if (unitVec.y == -1)
		{
			frameNum = 3;
		}
	}
	else if (unitVec.x == 1)
	{
		if (unitVec.y == 1)
		{
			frameNum = 10;
		}
		else if (unitVec.y == -1)
		{
			frameNum = 1;
		}
		else if (unitVec.y == 0)
		{
			frameNum = 0;
		}
	}
	else if(unitVec.x == -1)
	{
		if (unitVec.y == 1)
		{
			frameNum = 8;
		}
		else if (unitVec.y == -1)
		{
			frameNum = 4;
		}
		else if (unitVec.y == 0)
		{
			frameNum = 6;
		}
	}

	imgStart = vec2{ EnemySmallX[frameNum],EnemySmallRest [0]};
	imgEnd = vec2{ EnemySmallRest[1],EnemySmallRest[2] };

	MoveBy(dPosition);

	return 0;
}

int EnemyClass::Stop()
{
	dPosition = vec2{ 0.f,0.f};

	int frameNum = 9;

	imgStart = vec2{ EnemySmallX[frameNum],EnemySmallRest[0] };
	imgEnd = vec2{ EnemySmallRest[1],EnemySmallRest[2] };
	MoveBy(dPosition);
	return 0;
}

int EnemyClass::MoveStopMove()
{
	auto frame = frameCount % 180;

	if (frame == 0)
	{
		moveFlag = !moveFlag;
	}

	if (moveFlag == true)
	{
		MoveStraight();
	}
	else
	{
		Stop();
	}

	return 0;
}

int EnemyClass::AttackStraight()
{
	gun->Shot(GetPosition() +
		vec2{ ProjectileMarginForEnemyPlane[0]
		,ProjectileMarginForEnemyPlane[1] });

	gun->Logic(int(0));
	return 0;
}

int EnemyClass::StopAttack()
{
	gun->Logic(int(0));
	return 0;
}

int EnemyClass::AttackStopAttack()
{
	auto frame = frameCount % 180;

	if (frame == 0)
	{
		attackFlag = !attackFlag;
	}

	if (attackFlag == true)
	{
		AttackStraight();
	}
	else
	{
		StopAttack();
	}
	return 0;
}
