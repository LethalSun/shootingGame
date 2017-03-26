#include "pch.h"
#include "BackgroundClass.h"


BackgroundClass::BackgroundClass(HDC phDC)
	: memoryDC{phDC}
	, bgMemoryDCStartX{0}
	, bgMemoryDCStartY{0}
	, bgImageStartX{0}
	, bgImageStartY{0}
	, bgImageEndX{700}
	, bgImageEndY{0}
	, bgScrollSpeed{BgScrollSpeed}
{
	Loading();
}


BackgroundClass::~BackgroundClass()
{
	backgroundImg.Destroy();
}

int BackgroundClass::SetBgScrollSpeed(float pSpeed)
{

	bgScrollSpeed = pSpeed;

	return 0;
}

int BackgroundClass::Render(float dt)
{
	
	bgImageStartY = bgImageStartY - bgScrollSpeed*dt;

	if (bgImageStartY <= 0.f)
	{
		bgImageStartY = 800.f;
	}

	if (isStartY0to200())
	{
		bgImageEndY = bgImageStartY + 600.f;
		backgroundImg.BitBlt
		(	
			memoryDC
			, (int)bgMemoryDCStartX
			, (int)bgMemoryDCStartY
			, (int)bgImageEndX
			, (int)bgImageEndY
			, (int)bgImageStartX
			, (int)bgImageStartY
			, SRCCOPY
		);
	}
	else
	{
		bgImageEndY = bgImageStartY - 200.f;
		float secondStartY = 800.f - bgImageStartY;

		backgroundImg.BitBlt
		(
			memoryDC
			, (int)bgMemoryDCStartX
			, (int)bgMemoryDCStartY
			, (int)bgImageEndX
			, (int)secondStartY
			, (int)bgImageStartX
			, (int)bgImageStartY
			, SRCCOPY
		);
		backgroundImg.BitBlt
		(
			memoryDC
			, (int)bgImageStartX
			, (int)secondStartY
			, (int)bgImageEndX
			, (int)bgImageEndY
			, 0
			, 0
			, SRCCOPY
		);
	}


	return 0;
}

int BackgroundClass::Loading()
{
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	
	WCHAR temp[256];

	wcscpy_s(temp, path);
	wcscat_s(temp, PartialBG);

	backgroundImg.Load(temp);

	return 0;
}

bool BackgroundClass::isStartY0to200()
{
	if (0.f <= bgImageStartY && bgImageStartY < 200.f)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
