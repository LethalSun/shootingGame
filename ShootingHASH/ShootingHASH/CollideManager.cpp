#include "pch.h"
#include "CollideManager.h"
#include "PlayerClass.h"
#include "ProjectileClass.h"
#include "EnemyShipClass.h"

CollideManager::CollideManager(HDC phDC)
{
}


CollideManager::~CollideManager()
{
}

int CollideManager::Render(float dt)
{
	return 0;
}

int CollideManager::Logic(int pInput)
{
	CheckEnemyPlayerBulletCollide();
	CheckPlayerEnemyBulletCollide();
	return 0;
}

int CollideManager::SetPlayer(PlayerClass * pPlayer)
{
	player = pPlayer;
	return 0;
}

int CollideManager::SetPlayerBullet(std::vector<ProjectileClass*>* pProjectile)
{
	playerBulletvector = pProjectile;
	return 0;
}

int CollideManager::SetEnemy(std::array<EnemyShipClass*, 50>* pEnemy)
{
	enemyArray = pEnemy;
	return 0;
}

int CollideManager::SetEnemyBullet(std::array<ProjectileClass*, 50>* pEnemyBullet)
{
	enemyBulletArray = pEnemyBullet;
	return 0;
}

int CollideManager::CheckPlayerEnemyBulletCollide()
{
	auto playerRadius = player->GetCollideRadius();
	auto playerPos = player->GetPosition();
	for (auto& bullet : *enemyBulletArray)
	{
		auto bulletRadius = bullet->GetCollideRadius();
		auto bulletPos = bullet->GetPosition();
		if (IsCollide(playerPos, playerRadius, bulletPos, bulletRadius) == true)
		{
			//TODO: 1을 bullet의 데미지로
			auto newHp = player->GetHp() - 1;
			player->SetHp(newHp);
			bullet->SetIsDead();
		}
	}
	return 0;
}

int CollideManager::CheckEnemyPlayerBulletCollide()
{
	for (auto& bullet : *playerBulletvector)
	{
		auto bulletPos = bullet->GetPosition();
		auto bulletRadius = bullet->GetCollideRadius();
		for (auto& enemy : *enemyArray)
		{
			auto enemyPos = enemy->GetPosition();
			auto enemyRadius = enemy->GetCollideRadius();
			if (IsCollide(bulletPos, bulletRadius, enemyPos, enemyRadius) == true)
			{
				bullet->SetIsDead();
				auto newHp = enemy->GetHp() - 1;
				enemy->SetHp(newHp);
			}
		}
	}
	return 0;
}

bool CollideManager::IsCollide(vec2 pos1, int radius1, vec2 pos2, int radius2)
{
	auto distance = (pos1.x - pos2.x)*(pos1.x - pos2.x) 
					+ (pos1.y - pos2.y)*(pos1.y - pos2.y);
	auto distance2 = radius1 + radius2;

	auto dDistance = static_cast<int>(distance) - distance2;
	if (dDistance >= 0)
	{
		return false;
	}
	else
	{
		return true;
	}

}
