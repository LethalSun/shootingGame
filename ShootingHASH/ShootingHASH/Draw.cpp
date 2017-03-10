#include "pch.h"
#include "Draw.h"
//#include "Loading.h"

Draw::Draw(HWND phWnd)
	: hWnd(phWnd)
	, hDC(GetDC(hWnd))
	, memoryDC(CreateCompatibleDC(hDC))
	//TODO: 800x600 is magic number
	, memoryBitmap(CreateCompatibleBitmap(hDC, 800, 600))
	, oldBitmap((HBITMAP)SelectObject(memoryDC, memoryBitmap))
	, bgMemoryDCStartX(0)
	, bgMemoryDCStartY(0)
	, bgImageStartX(0)
	, bgImageStartY(0)
	//TODO: 700은 배경이미지에서 오는 매직넘버
	, bgImageEndX(700)
	//TODO: 600은 매직넘버 위에서 해상도의 600과 같은값
	, bgImageEndY(bgImageStartY + 600)
	//TODO: 속도도 매직넘버
	, bgScrollSpeed(3.f)
{
	LoadCImage();
}


Draw::~Draw()
{
	ReleaseDC(hWnd, hDC);
	SelectObject(hDC, oldBitmap);
	DeleteObject(memoryBitmap);
	DeleteDC(memoryDC);
	DeleteCImage();
}

int Draw::LoadCImage()
{
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);

	WCHAR temp[256];
	wcscpy_s(temp, path);
	wcscat_s(temp, PartialBG);
	
	imgBG.Load(temp);

	wcscpy_s(temp, path);
	wcscat_s(temp, PartialPlane);

	imgPlane.Load(temp);

	wcscpy_s(temp, path);
	wcscat_s(temp, PartialPlaneMask);

	imgPlaneMasking.Load(temp);

	wcscpy_s(temp, path);
	wcscat_s(temp, PartialEngineGlow);

	imgEngineGlow.Load(temp);

	wcscpy_s(temp, path);
	wcscat_s(temp, PartialEngineGlowMask);

	imgEngineGlowMasking.Load(temp);
	
	return 0;
}

int Draw::DeleteCImage()
{
	//TODO: CImage 삭제
	imgBG.Destroy();
	return 0;
}

int Draw::DrawBackground(float dt)
{
	int dy = bgScrollSpeed*dt*60;

	bgImageStartY = bgImageStartY + dy;
	


	if (bgImageStartY >= 800)
	{
		bgImageStartY = 0;
	}
	
	bgImageEndY = bgImageStartY + 600;
	
	//1400 >=  bgImageEndY > 800
	if (bgImageEndY >= 800)
	{
		int firstEndY = 800 - bgImageStartY;
		imgBG.BitBlt(memoryDC, 
			bgMemoryDCStartX, 
			bgMemoryDCStartY, 
			bgImageEndX,
			firstEndY,
			bgImageStartX,
			bgImageStartY,
			SRCCOPY);
		int secondEndY = bgImageEndY % 800;
		imgBG.BitBlt(memoryDC,
			bgMemoryDCStartX,
			firstEndY,
			bgImageEndX,
			secondEndY,
			bgImageStartX,
			0,
			SRCCOPY);
	
	}
	//800 >= bgImageEndY > 600
	else
	{
		imgBG.BitBlt(memoryDC,
			bgMemoryDCStartX,
			bgMemoryDCStartY,
			bgImageEndX,
			bgImageEndY,
			bgImageStartX,
			bgImageStartY,
			SRCCOPY);
	}
	
	
	
	
	//imgBG.BitBlt(memoryDC, 0, 0, 700, 600, 0, 0, SRCCOPY);
	return 0;
}

int Draw::DrawPlane(float dt)
{
	imgPlaneMasking.BitBlt(memoryDC,
		100,
		100,
		150,
		125,
		0,
		0,
		SRCAND);

	imgPlane.BitBlt(memoryDC,
		100,
		100,
		150,
		125,
		0,
		0,
		SRCPAINT);

	imgEngineGlowMasking.BitBlt(memoryDC,
		200,
		100,
		150,
		125,
		0,
		0,
		SRCAND);

	imgEngineGlow.BitBlt(memoryDC,
		200,
		100,
		150,
		125,
		0,
		0,
		SRCPAINT);


	return 0;
}

int Draw::DrawHDC(float dt)
{

	
	DrawBackground(dt);
	
	DrawPlane(dt);

	BitBlt(hDC, 0, 0, 800, 600, memoryDC,0,0, SRCCOPY);
	return 0;
}

HDC Draw::GetMemoryDC()
{
	return memoryDC;
}
