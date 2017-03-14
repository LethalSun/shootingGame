#include <iostream>
#include "Clock.h"
#include "GameClass.h"

#define szWindowClass	TEXT("ShootingHash")
#define szTitle			TEXT("ShootingHash")

LRESULT CALLBACK WndProc(HWND hWnd
	, UINT message
	, WPARAM wParam
	, LPARAM lParam);

int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam,
	int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = (WNDPROC)WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;

	if (!RegisterClassEx(&wcex))
	{
		return 0;
	}

	HWND	hWnd = CreateWindowEx(WS_EX_APPWINDOW
		, szWindowClass
		, szTitle
		, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, 800
		, 600
		, NULL
		, NULL
		, hInstance
		, NULL);

	if (!hWnd)
		return 0;

	ShowWindow(hWnd, nCmdShow);

	//TODO: //NOT timer init
	Clock timer;
	if (timer.Init() == false)
	{
		MessageBoxA(hWnd, "timer problem!!", "error!", MB_OK);
		return 0;
	}
	float time = 0.f;

	//TODO: //NOT getcurrentdirectory
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);

	//TODO: //NOT HDC init
	HDC hDC = GetDC(hWnd);

	//TODO: //NOT message init
	MSG			msg;

	//TODO: //NOT init GameClass
	GameClass gameManager(hWnd);

	//deltatime
	float dt;
	 
	while (1)
	{
		timer.ProcessTime();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

			if (timer.isOneFrame(&dt))
			{
				
				gameManager.Run(dt);

			}
		}

	}

	ReleaseDC(hWnd, hDC);
	return (int)msg.wParam;
}

// 메시지 처리 함수
LRESULT CALLBACK WndProc(HWND hWnd
	, UINT message
	, WPARAM wParam
	, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	switch (message)
	{
	case WM_CREATE:

		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}


//프레임계산코드

//int frame = 0;
//float time2 = 0.f;

//while (1)
//{
//	timer.ProcessTime();
//	time += timer.GetElapsedTime();
//
//	time2 += timer.GetElapsedTime();
//	if (time2 >= 1.0f)
//	{
//		time2 = 0.f;
//		char t[100];
//		sprintf_s(t, "%d", frame);
//		TextOutA(hDC, 100, 100, t, 100);
//		frame = 0;
//	}
//	char t[100];
//	sprintf_s(t, "%f", time);
//	TextOutA(hDC, 100, 100, t, 100);

//	if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//	{
//		if (msg.message == WM_QUIT)
//		{
//			break;
//		}
//
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	else
//	{
//		if (time >= 0.016666)
//		{
//			time = 0.f;
//			frame++;
//		}
//	}
//
//}