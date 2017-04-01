#pragma once
#include "GameObjectClass.h"
class EffectManagerClass :
	public GameObjectClass
{
public:
	EffectManagerClass(HDC phDC, vec2 pVec2, float pSpeed);
	~EffectManagerClass();
};

