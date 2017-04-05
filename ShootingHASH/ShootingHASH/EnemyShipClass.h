#pragma once
#include "GameObjectClass.h"
class EnemyShipClass :
	public GameObjectClass
{
public:
	enum class Enemytype {
		HeabyShip = 0,
		MediumShip = 4,
		SmallShip = 8,
		SpiderShip = 12,
	};

public:
	EnemyShipClass(HDC phDC, vec2 pVec2);
	~EnemyShipClass();

	virtual int Render(float);
	virtual int Logic(int);

	//설정 함수.
	int SetEnemyType(int);
	int SetAppearTime(float);
	int SetDPosition(vec2);
	int SetIsNotDead();
	int SetIsDead();
	int SetCollideRadius(int);
	int GetCollideRadius();
	bool IsDead();
	int GetHp();
	int SetHp(int);
private:
	bool isDead = true;
	int CheckIsDead();
	int imgStartFrame = 0;
	float appearTime = 0.f;
	vec2 dPos{0.f,0.f};
	int collideRadius;
	int hp = 10;
	int MaxHp = 10;
};

