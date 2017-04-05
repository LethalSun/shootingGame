#include "pch.h"
#include "EnemyManagerClass.h"
#include "EnemyShipClass.h"
#include "ProjectileClass.h"

EnemyManagerClass::EnemyManagerClass(HDC phDC)
	:hDC{phDC}
{
	for (auto& enemy : enemyArray)
	{
		enemy = new EnemyShipClass(hDC, vec2{ 0.f,600.f });
		enemy->LoadCImage(PartialEnemy2, PartialEnemyMasking2);
	}

	for (auto& bullet : bulletArray)
	{
		bullet = new ProjectileClass(hDC, vec2{ 0.f,200.f }, false);
		bullet->LoadCImage(PartialEnemyBullet2, PartialEnemyBulletMasking2);
	}
	
}

EnemyManagerClass::~EnemyManagerClass()
{
	for (auto& enemy : enemyArray)
	{
		delete enemy;
	}

	for (auto& bullet : bulletArray)
	{
		delete bullet;
	}
}

int EnemyManagerClass::Render(float dt)
{
	for (auto& bullet : bulletArray)
	{
		bullet->Render(dt);
	}

	for (auto& enemy : enemyArray)
	{
		enemy->Render(dt);
	}


	return 0;
}

int EnemyManagerClass::Logic(int pInput)
{
	for (auto& bullet : bulletArray)
	{
		bullet->Logic(pInput);
	}

	for (auto& enemy : enemyArray)
	{
		enemy->Logic(pInput);
	}

	return 0;
}

int EnemyManagerClass::initEnemyAndBullet()
{
	//MakeOneEnemy(3.f, vec2{100.f,100.f}
	//	,static_cast<int>(EnemyShipClass::Enemytype::SpiderShip)
	//	, int{EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::SpiderShip)/4]}
	//, vec2{0.f,1.0f});
	//MakeBullets(3.f, vec2{ 110.f,200.f }
	//	, static_cast<int>(ProjectileClass::BulletType::DiaRed)
	//	, int{ EnemyShipRadius[static_cast<int>(ProjectileClass::BulletType::DiaRed) / 4] }
	//, vec2{ 0.f,1.0f });
	//MakeBullets(3.2f, vec2{ 169.f,300.f }
	//	, static_cast<int>(ProjectileClass::BulletType::DiaBlue)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::HeabyShip) / 4] }
	//, vec2{ 0.f,1.0f });
	//MakeBullets(3.4f, vec2{ 169.f,300.f }
	//	, static_cast<int>(ProjectileClass::BulletType::DiaBlue)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::HeabyShip) / 4] }
	//, vec2{ 0.f,1.0f });
	//MakeBullets(3.6f, vec2{ 169.f,300.f }
	//	, static_cast<int>(ProjectileClass::BulletType::DiaBlue)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::HeabyShip) / 4] }
	//, vec2{ 0.f,1.0f });
	//MakeBullets(3.8f, vec2{ 169.f,300.f }
	//	, static_cast<int>(ProjectileClass::BulletType::DiaBlue)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::HeabyShip) / 4] }
	//, vec2{ 0.f,1.0f });
	//MakeBullets(4.f, vec2{ 169.f,300.f }
	//	, static_cast<int>(ProjectileClass::BulletType::DiaBlue)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::HeabyShip) / 4] }
	//, vec2{ 0.f,1.0f });
	////
	//MakeEnemyLineFormation(4,3.f, vec2{ 100.f,100.f }
	//	, static_cast<int>(EnemyShipClass::Enemytype::SpiderShip)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::SpiderShip) / 4] }
	//, vec2{ 0.f,1.0f });
	//MakeBulletsLineFormation(4, 3.f, vec2{ 100.f,100.f }
	//	, static_cast<int>(EnemyShipClass::Enemytype::SpiderShip)
	//	, int{ EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::SpiderShip) / 4] }
	//, vec2{ 0.f,1.0f });;

	MakeEnemyDiamondFormation(3.f, vec2{ 100.f,100.f }
			,static_cast<int>(EnemyShipClass::Enemytype::SpiderShip)
			, int{EnemyShipRadius[static_cast<int>(EnemyShipClass::Enemytype::SpiderShip)/4]}
		, vec2{0.f,1.0f});
	MakeBulletsDiamondFormation(3.f, vec2{ 110.f,100.f }
			, static_cast<int>(ProjectileClass::BulletType::DiaRed)
			, int{ EnemyShipRadius[static_cast<int>(ProjectileClass::BulletType::DiaRed) / 4] }
		, vec2{ 0.f,1.0f });

	return 0;
}

int EnemyManagerClass::MakeOneEnemy(float pAppearTime
	, vec2 pAppearPos, int pShipType
	, int pCollideRadius
	, vec2 dPos)
{
	for (auto& enemy : enemyArray)
	{
		if (enemy->IsDead() == true)
		{
			enemy->SetAppearTime(pAppearTime);
			enemy->SetPosition(pAppearPos);
			enemy->SetEnemyType(pShipType);
			enemy->SetCollideRadius(pCollideRadius);
			enemy->SetDPosition(dPos);
			enemy->SetIsNotDead();
			return 1;
		}
	}
	return 0;
}

int EnemyManagerClass::MakeEnemyLineFormation(int pShipNumfloat
	, float pAppearTime
	, vec2 pAppearPos, int pShipType
	, int pCollideRadius
	, vec2 dPos)
{
	auto count = 0;
	auto isNotAvailable = false;
	for (auto& enemy : enemyArray)
	{
		if (enemy->IsDead() == true)
		{
			++count;
			isNotAvailable = false;
			if (count >= pShipNumfloat)
			{
				isNotAvailable = true;
				break;
			}

		}
	}

	if (isNotAvailable == true)
	{
		count = 0;
		auto margin = vec2{40.f,0.f};
		for (auto& enemy : enemyArray)
		{
			if (enemy->IsDead() == true)
			{
				enemy->SetAppearTime(pAppearTime);
				enemy->SetPosition(pAppearPos + margin*((float)count));
				enemy->SetEnemyType(pShipType);
				enemy->SetCollideRadius(pCollideRadius);
				enemy->SetDPosition(dPos);
				enemy->SetIsNotDead();
				++count;
				if (count >= pShipNumfloat)
				{
					break;
				}
			}
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

int EnemyManagerClass::MakeEnemyDiamondFormation(float pAppearTime
	, vec2 pAppearPos, int pShipType
	, int pCollideRadius
	, vec2 dPos)
{
	auto count = 0;
	auto isNotAvailable = false;
	for (auto& enemy : enemyArray)
	{
		if (enemy->IsDead() == true)
		{
			++count;
			isNotAvailable = false;
			if (count >= 4)
			{
				isNotAvailable = true;
				break;
			}

		}
	}

	if (isNotAvailable == true)
	{
		count = 0;
		vec2 margin[4]{ vec2{ 0.f,0.f },vec2{ 40.f,40.f },vec2{ 80.f,0.f },vec2{ 40.f,-40.f } };
		for (auto& enemy : enemyArray)
		{
			if (enemy->IsDead() == true)
			{
				enemy->SetAppearTime(pAppearTime);
				enemy->SetPosition(pAppearPos + margin[count]);
				enemy->SetEnemyType(pShipType);
				enemy->SetCollideRadius(pCollideRadius);
				enemy->SetDPosition(dPos);
				enemy->SetIsNotDead();
				++count;
				if (count >= 4)
				{
					break;
				}
			}
		}
	}
	else
	{
		return 0;
	}

	return 0;
}

int EnemyManagerClass::MakeBullets(float pAppearTime
	, vec2 pAppearPos, int pBulletType
	, int pCollideRadius
	, vec2 dPos)
{
	for (auto& bullet : bulletArray)
	{
		if (bullet->IsDead() == true)
		{
			bullet->SetAppearTime(pAppearTime);
			bullet->SetPosition(pAppearPos);
			bullet->SetBulletType(pBulletType);
			bullet->SetCollideRadius(pCollideRadius);
			bullet->SetDPosition(dPos);
			bullet->SetSpeed(BulletSpeed/ 20);
			bullet->SetIsNotDead();
			return 1;
		}
	}

	return 0;
}

int EnemyManagerClass::MakeBulletsLineFormation(int pBulletNumfloat,float pAppearTime
		, vec2 pAppearPos, int pBulletType
		, int pCollideRadius
		, vec2 dPos)
{
	auto count = 0;
	auto isNotAvailable = false;
	for (auto& bullet : bulletArray)
	{
		if (bullet->IsDead() == true)
		{
			++count;
			isNotAvailable = false;
			if (count >= pBulletNumfloat)
			{
				isNotAvailable = true;
				break;
			}

		}
	}

	if (isNotAvailable == true)
	{
		count = 0;
		auto margin = vec2{ 40.f,0.f };
		for (auto& bullet : bulletArray)
		{
			if (bullet->IsDead() == true)
			{
				bullet->SetAppearTime(pAppearTime);
				bullet->SetPosition(pAppearPos + margin*((float)count));
				bullet->SetBulletType(pBulletType);
				bullet->SetCollideRadius(pCollideRadius);
				bullet->SetDPosition(dPos);
				bullet->SetSpeed(BulletSpeed / 40);
				bullet->SetIsNotDead();
				++count;
				if (count >= pBulletNumfloat)
				{
					break;
				}
			}
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

int EnemyManagerClass::MakeBulletsDiamondFormation(float pAppearTime
	, vec2 pAppearPos, int pBulletType
	, int pCollideRadius
	, vec2 dPos)
{
	auto count = 0;
	auto isNotAvailable = false;
	for (auto& bullet : bulletArray)
	{
		if (bullet->IsDead() == true)
		{
			++count;
			isNotAvailable = false;
			if (count >= 4)
			{
				isNotAvailable = true;
				break;
			}

		}
	}

	if (isNotAvailable == true)
	{
		count = 0;
		vec2 margin[4]{ vec2{ 0.f,0.f },vec2{ 40.f,40.f },vec2{ 80.f,0.f },vec2{ 40.f,-40.f } };
		for (auto& bullet : bulletArray)
		{
			if (bullet->IsDead() == true)
			{
				bullet->SetAppearTime(pAppearTime);
				bullet->SetPosition(pAppearPos + margin[count]);
				bullet->SetBulletType(pBulletType);
				bullet->SetCollideRadius(pCollideRadius);
				bullet->SetDPosition(dPos);
				bullet->SetSpeed(BulletSpeed / 40);
				bullet->SetIsNotDead();
				++count;
				if (count >= 4)
				{
					break;
				}
			}
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

std::array<EnemyShipClass*, 50>* EnemyManagerClass::GetEnemyArray()
{
	return &enemyArray;
}

std::array<ProjectileClass*, 50>* EnemyManagerClass::GetBulletArray()
{
	return &bulletArray;
}
