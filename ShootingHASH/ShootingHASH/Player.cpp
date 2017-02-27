#include "pch.h"
#include "Player.h"


Player::Player(HDC pMemoryDC)
	:memoryDC(pMemoryDC)
	,positionX(325)
	,positionY(475)
	,inputBitflag(0)
{
} 


Player::~Player()
{
}

int Player::setInputFlag(int pBitflag)
{
	inputBitflag = pBitflag;
	return 0;
}

int Player::bitToState()
{
	return 0;
}
