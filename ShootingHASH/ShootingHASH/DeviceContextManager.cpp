#include "pch.h"
#include "DeviceContextManager.h"


DeviceContextManager::DeviceContextManager(HWND phWnd)
	: hWnd(phWnd)
	, hDC(GetDC(hWnd))
	, memoryDC(CreateCompatibleDC(hDC))
	, memoryBitmap(CreateCompatibleBitmap(hDC, 800, 600))
	, oldBitmap{(HBITMAP)SelectObject(memoryDC,memoryBitmap)}
{

}


DeviceContextManager::~DeviceContextManager()
{
	SelectObject(memoryDC, oldBitmap);
	DeleteObject(memoryBitmap);
	DeleteDC(memoryDC);
	ReleaseDC(hWnd, hDC);
}

HDC DeviceContextManager::GetHDC()
{
	return hDC;
}

HDC DeviceContextManager::GetMemoryDC()
{
	return memoryDC;
}

int DeviceContextManager::DrawMemoryDCtoHDC()
{
	BitBlt(hDC, 0, 0, ScreenSizeX, ScreenSizeY, memoryDC, 0, 0, SRCCOPY);
	return 0;
}
