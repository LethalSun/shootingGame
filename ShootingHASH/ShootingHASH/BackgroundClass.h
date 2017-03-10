#pragma once
class BackgroundClass
{
public:
	BackgroundClass(HDC);
	~BackgroundClass();

	int SetBgScrollSpeed(float);
	int Render(float);

private:
	//member
	HDC memoryDC;
	CImage backgroundImg;

	//member for bitblt
	float bgMemoryDCStartX;
	float bgMemoryDCStartY;
	float bgImageStartX;
	float bgImageStartY;
	float bgImageEndX;
	float bgImageEndY;
	float bgScrollSpeed;

	//method
	int Loading();

	//bool type method
	bool isStartY0to200();

};

