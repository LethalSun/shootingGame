#pragma once
#include "GameObjectClass.h"
class UIManagerClass :
	public GameObjectClass
{
public:
	UIManagerClass(HDC phDC, vec2 pVec2);
	~UIManagerClass();

	int Logic(int) override;
	int Render(float) override;

	int SetHpBar(float);
private:

	std::array<float, 4> UIBar{0};
	std::array<float, 6> UIBlood{ 37,1,34,267,689,81 };
	int SetBarImageByHp();
	int CalculateBloodBarPos();
};

