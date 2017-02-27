#include "pch.h"
#include "GameLogic.h"


GameLogic::GameLogic()
	:inputBitFlag(0)
{
}


GameLogic::~GameLogic()
{
}

int GameLogic::SetinputFromKeyboard(int pInput)
{
	inputBitFlag = pInput;

	return 0;
}

int GameLogic::Logic()
{
	return 0;
}
