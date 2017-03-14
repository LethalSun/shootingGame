#pragma once
class GameObjectClass
{
public:
	GameObjectClass(HDC,vec2);
	virtual ~GameObjectClass();
	int LoadCImage(const WCHAR * pPartialImgPath, const WCHAR * pPartialMaskingPath);

	int BitBlt(vec2 pImgStart, vec2 pImgEnd, vec2 pPosition, bool isLeft);

	int MoveTo(vec2);
	int MoveBy(vec2);

	vec2 GetPosition();
	int SetPosition(vec2);

	float GetHP();
	int SetHP(float);

	virtual int Logic(int) = 0;
	virtual int Render(float) = 0;

private:
	//member
	HDC memoryDC;
	CImage objectImg;
	CImage objectMaskingImg;

	vec2 position;
	float HP;

};

