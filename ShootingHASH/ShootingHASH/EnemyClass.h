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

	int init(vec2 pVec2, float pSpeed);

	int SetMovementAndAttack(int pMovement,int pAttack, float pAppearTime);
private:

	int movement = 0;
	int attackType = 0;
	bool isDead = true;
	float appearTime;

	float planeSpeed;
	vec2 dPosition;

	int CheckIsDead();

	//MoveMentFunc
	int MoveStraight(vec2);
	//AttackFunc
	int AttackStraight(vec2);
	//Gun
	GunClass* gun;
};

