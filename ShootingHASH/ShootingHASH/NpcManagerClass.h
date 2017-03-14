#pragma once

class ProjectileClass;

class NpcManagerClass
{
public:
	NpcManagerClass(int);
	~NpcManagerClass();
	int Logic();
	int Render();


private:

	int maxBulletNumber;

	std::vector<ProjectileClass*> playerBullet;

	int FireBullet(HDC,vec2,bool);

	int DeleteBullet();
};

