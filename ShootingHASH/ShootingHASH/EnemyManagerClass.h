#pragma once
class EnemyClass;
class ProjectileClass;
class EnemyShipClass;
class EnemyManagerClass
{
public:
	enum class EnemyBulletMargin
	{
		HD = 0,
		HF = 1,
		HM = 2,
		HQ = 3,
		MD = 4,
		MF = 5,
		MM = 6,
		MQ = 7,
		SD = 8,
		SF = 9,
		SM = 10,
		SQ = 11,
		PD = 12,
		PF = 13,
		PM = 14,
		PQ = 15
	};
public:
	EnemyManagerClass(HDC phDC);
	~EnemyManagerClass();
	
	int Render(float);
	int Logic(int);

	int initEnemyAndBullet();

	//적을 만드는 함수들.
	int MakeOneEnemy(float pAppearTime
		,vec2 pAppearPos,int ShipType
		,int pCollideRadius
		,vec2 dPos);
	int MakeEnemyLineFormation(int pShipNumfloat,float pAppearTime
		, vec2 pAppearPos, int ShipType
		, int pCollideRadius
		, vec2 dPos);
	int MakeEnemyDiamondFormation(float pAppearTime
		, vec2 pAppearPos, int ShipType
		, int pCollideRadius
		, vec2 dPos);

	//총알을 만드는 함수들
	int MakeBullets(float pAppearTime
		, vec2 pAppearPos, int BulletType
		, int pCollideRadius
		, vec2 dPos);
	int MakeBulletsLineFormation(int pShipNumfloat, float pAppearTime
		, vec2 pAppearPos, int pBulletType
		, int pCollideRadius
		, vec2 dPos);
	int MakeBulletsDiamondFormation(float pAppearTime
		, vec2 pAppearPos, int BulletType
		, int pCollideRadius
		, vec2 dPos);

	std::array<EnemyShipClass*, 50>* GetEnemyArray();
	std::array<ProjectileClass*, 50>* GetBulletArray();
private:
	HDC hDC;
	//CImage EnemyImage;
	//CImage EnemyImageMasking;
	//CImage EnemyBulletImage;
	//CImage EnemyBulletImageMasking;

	std::array<EnemyShipClass*, 50> enemyArray;
	std::array<ProjectileClass*, 50> bulletArray;
};

