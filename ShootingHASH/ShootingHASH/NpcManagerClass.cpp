#include "pch.h"
#include "NpcManagerClass.h"
#include "ProjectileClass.h"
//TODO : �̰Ŵ� �׳� ���� ���� �Ѿ��� ��ġ�� �����ϴ� Ŭ����, �׸��� �� �÷��̾ ������ �ֵ��ϸ� �Ѿ��� �߻��Ҽ� �ִ� Ŭ������ ������. 
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
