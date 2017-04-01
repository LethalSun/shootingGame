#include "pch.h"
#include "UIManagerClass.h"


UIManagerClass::UIManagerClass(HDC phDC, vec2 pVec2)
	: GameObjectClass{ phDC ,pVec2 }
{
}


UIManagerClass::~UIManagerClass()
{
}

int UIManagerClass::Logic(int)
{
	SetBarImageByHp();
	CalculateBloodBarPos();
	return 0;
}

int UIManagerClass::Render(float)
{
	BitBlt(vec2(UiBackGround[0], UiBackGround[1])
		, vec2(UiBackGround[2],UiBackGround[3])
		, vec2(UiBackGroundPos[0], UiBackGroundPos[1])
		, true);
	
	BitBlt(vec2(UiBarBlack[0], UiBarBlack[1])
		, vec2(UiBarBlack[2], UiBarBlack[3])
		, vec2(UiHpBarPos[0], UiHpBarPos[1])
		, true);
	BitBlt(vec2(UIBlood[0], UIBlood[1])
		, vec2(UIBlood[2], UIBlood[3])
		, vec2(UIBlood[4], UIBlood[5])
		, true);

	BitBlt(vec2(UIBar[0], UIBar[1])
		, vec2(UIBar[2], UIBar[3])
		, vec2(UiHpBarPos[0], UiHpBarPos[1])
		, true);





	return 0;
}

int UIManagerClass::SetHpBar(float pHP)
{
	SetHP(1);
	return 0;
}

int UIManagerClass::SetBarImageByHp()
{
	int i = 0;
	if (GetHP() == 0)
	{

		for (auto& iter : UIBar)
		{
			iter = UiBarZero[i];
			++i;
		}
	}
	else
	{
		for (auto& iter : UIBar)
		{
			iter = UiBarOne[i];
			++i;
		}
	}
	return 0;
}

int UIManagerClass::CalculateBloodBarPos()
{
	//TODO: 값을 입력 받아서 비율계산하는것 필요.
	float ratio = 1.f;
	float hpBarLen = 267 * ratio;
	float startYpos = 80 + 268 - hpBarLen;
	UIBlood[3] = { hpBarLen };
	UIBlood[5] = { startYpos };
	return 0;
}
