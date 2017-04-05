#pragma once
#include "GameObjectClass.h"
class GunClass;

class EnemyClass :
	public GameObjectClass
{
public:
	EnemyClass(HDC phDC, vec2 pVec2, float pSpeed);
	~EnemyClass();

	virtual int Render(float);
	virtual int Logic(int);

	//TODO:temp
	int init(vec2 pVec2, float pSpeed);
	int SetMovementAndAttack(int pMovement, vec2 pMoveVec, int pAttack, vec2 pAttackVec,int pBulletNum, float pAppearTime);

	//설정 함수.
	int SetIsNotDead();
	int SetIsDead();
private:

	int movement = 0;
	int attackType = 0;
	bool isDead = true;
	int bulletNum;
	float appearTime;
	int frameCount = 0;

	float planeSpeed;
	vec2 dPosition;
	vec2 unitVec;

	int CheckIsDead();

	//MoveMentFunc
	int MoveStraight();

	int Stop();

	int MoveStopMove();
	
	bool moveFlag = true;

	//AttackFunc
	int AttackStraight();

	int StopAttack();
	
	int AttackStopAttack();

	bool attackFlag = true;
	//Gun
	GunClass* gun;
	//frame info
	vec2 imgStart{ 0.f,0.f };
	vec2 imgEnd{0.f,0.f};
	bool isLeft{ true };
};

