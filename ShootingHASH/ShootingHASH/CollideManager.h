#pragma once
class ProjectileClass;
class EnemyShipClass;
class PlayerClass;

class CollideManager
{
public:
	CollideManager(HDC);
	~CollideManager();

	int Render(float);
	int Logic(int);

	int SetPlayer(PlayerClass*);
	int SetPlayerBullet(std::vector<ProjectileClass*>*);
	int SetEnemy(std::array<EnemyShipClass*, 50>*);
	int SetEnemyBullet(std::array<ProjectileClass*, 50>*);
private:

	HDC hDC;

	PlayerClass* player = nullptr;
	std::vector<ProjectileClass*>* playerBulletvector = nullptr;
	std::array<EnemyShipClass*, 50>* enemyArray = nullptr;
	std::array<ProjectileClass*, 50>* enemyBulletArray = nullptr;

	int CheckPlayerEnemyBulletCollide();
	int CheckEnemyPlayerBulletCollide();
	bool IsCollide(vec2 pos1, int radius1, vec2 pos2, int radius2);
};

