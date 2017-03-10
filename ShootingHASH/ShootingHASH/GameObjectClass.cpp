#include "pch.h"
#include "GameObjectClass.h"


GameObjectClass::GameObjectClass(HDC phDC,vec2 pPosition)
	:memoryDC{phDC}
	, position{pPosition}
{
}


GameObjectClass::~GameObjectClass()
{
	objectImg.Destroy();
	objectMaskingImg.Destroy();
}

int GameObjectClass::LoadCImage(const WCHAR * pPartialImgPath, const WCHAR * pPartialMaskingPath)
{
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);

	WCHAR temp[256];

	wcscpy_s(temp, path);
	wcscat_s(temp, pPartialImgPath);

	objectImg.Load(temp);

	wcscpy_s(temp, path);
	wcscat_s(temp, pPartialMaskingPath);

	objectMaskingImg.Load(temp);
	return 0;
}

int GameObjectClass::BitBlt(vec2 pImgStart, vec2 pImgEnd, vec2 pPosition, bool isLeft)
{
	if (isLeft == true)
	{
		objectMaskingImg.BitBlt
		(memoryDC
			, (int)pPosition.x
			, (int)pPosition.y
			, (int)pImgEnd.x
			, (int)pImgEnd.y
			, (int)pImgStart.x
			, (int)pImgStart.y
			, SRCAND
		);
		objectImg.BitBlt
		(memoryDC
			, (int)pPosition.x
			, (int)pPosition.y
			, (int)pImgEnd.x
			, (int)pImgEnd.y
			, (int)pImgStart.x
			, (int)pImgStart.y
			, SRCPAINT
		);
	}
	else
	{
		vec2 newImgStart = vec2(pImgStart.x + 150.f, pImgStart.y);
		vec2 newImgEnd = vec2(-pImgEnd.x, pImgEnd.y);

		objectMaskingImg.StretchBlt
		(memoryDC
			, (int)pPosition.x
			, (int)pPosition.y
			, 150
			, 125
			, (int)newImgStart.x
			, (int)newImgStart.y
			, (int)newImgEnd.x
			, (int)newImgEnd.y
			, SRCAND
		);

		objectImg.StretchBlt
		(memoryDC
			, (int)pPosition.x
			, (int)pPosition.y
			, 150
			, 125
			, (int)newImgStart.x
			, (int)newImgStart.y
			, (int)newImgEnd.x
			, (int)newImgEnd.y
			, SRCPAINT
			);
	}
	
	return 0;
}

int GameObjectClass::MoveTo(vec2 pPosition)
{
	position = pPosition;
	return 0;
}

int GameObjectClass::MoveBy(vec2 pPosition)
{
	position += pPosition;
	return 0;
}

vec2 GameObjectClass::GetPosition()
{
	return vec2(position.x,position.y);
}

int GameObjectClass::SetPosition(vec2 pPosition)
{
	position = pPosition;
	return 0;
}

float GameObjectClass::GetHP()
{
	return HP;
}

int GameObjectClass::SetHP(float pHP)
{
	HP = pHP;
	return 0;
}