#include "pch.h"
#include "NpcManagerClass.h"
#include "ProjectileClass.h"
//TODO : 이거는 그냥 적과 적의 총알의 위치를 관리하는 클래스, 그리고 각 플레이어나 적에게 애드하면 총알을 발사할수 있는 클래스를 만들자. 
NpcManagerClass::NpcManagerClass(int pMaxBulletNum)
	:maxBulletNumber{pMaxBulletNum}
	,playerBullet{}
{
	playerBullet.reserve(maxBulletNumber);
}


NpcManagerClass::~NpcManagerClass()
{
}

int NpcManagerClass::Logic()
{
	DeleteBullet();
	return 0;
}

int NpcManagerClass::Render()
{
	return 0;
}

int NpcManagerClass::FireBullet(HDC pHDC, vec2 pPosition, bool pIsFromPlayer)
{	
	if (pIsFromPlayer == true)
	{
		int currentBulletNum = playerBullet.size();

		if (currentBulletNum == maxBulletNumber)
		{
			return maxBulletNumber;
		}

		auto tempBullet = new ProjectileClass(pHDC, pPosition, pIsFromPlayer);
		
		playerBullet.push_back(tempBullet);

		return currentBulletNum;	
	}
	else
	{

	}
}

int NpcManagerClass::DeleteBullet()
{
	return 0;
}
