#pragma once
class Draw
{
public:
	Draw(HWND);
	~Draw();
	int DrawHDC(float);

	HDC GetMemoryDC();
private:
	int DrawBackground(float);
	int DrawPlane(float);
	int LoadCImage();
	int DeleteCImage();

	//배경그리기변수
	int bgMemoryDCStartX;
	int bgMemoryDCStartY;
	int bgImageStartX;
	int bgImageStartY;
	int bgImageEndX;
	int bgImageEndY;
	float bgScrollSpeed;

	//그리기 위해 필요한 것들
	HWND hWnd;				  //초기화완료,딜리트 완료
	HDC hDC;				  //초기화완료,딜리트 완료
	HDC memoryDC;			  //초기화완료,딜리트 완료
	HBITMAP memoryBitmap;	  //초기화완료,딜리트 완료
	HBITMAP oldBitmap;		  //초기화완료,딜리트 완료
	CImage imgBG;
	CImage imgPlane;
	CImage imgPlaneMasking;
	CImage imgEngineGlow;
	CImage imgEngineGlowMasking;
};

