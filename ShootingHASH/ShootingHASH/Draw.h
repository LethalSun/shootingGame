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

	//���׸��⺯��
	int bgMemoryDCStartX;
	int bgMemoryDCStartY;
	int bgImageStartX;
	int bgImageStartY;
	int bgImageEndX;
	int bgImageEndY;
	float bgScrollSpeed;

	//�׸��� ���� �ʿ��� �͵�
	HWND hWnd;				  //�ʱ�ȭ�Ϸ�,����Ʈ �Ϸ�
	HDC hDC;				  //�ʱ�ȭ�Ϸ�,����Ʈ �Ϸ�
	HDC memoryDC;			  //�ʱ�ȭ�Ϸ�,����Ʈ �Ϸ�
	HBITMAP memoryBitmap;	  //�ʱ�ȭ�Ϸ�,����Ʈ �Ϸ�
	HBITMAP oldBitmap;		  //�ʱ�ȭ�Ϸ�,����Ʈ �Ϸ�
	CImage imgBG;
	CImage imgPlane;
	CImage imgPlaneMasking;
	CImage imgEngineGlow;
	CImage imgEngineGlowMasking;
};

