#pragma once
class DeviceContextManager
{
public:
	DeviceContextManager(HWND);
	~DeviceContextManager();

	HDC GetHDC();
	HDC GetMemoryDC();

	int DrawMemoryDCtoHDC();
private:

	HWND hWnd;
	HDC hDC;
	HDC memoryDC;
	HBITMAP memoryBitmap;
	HBITMAP oldBitmap;

};

