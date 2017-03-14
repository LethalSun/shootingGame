#pragma once
class vec2
{
public:
	vec2(float, float);
	vec2();
	~vec2();

	vec2 operator+(vec2&);
	vec2 operator-(vec2&);
	vec2 operator*(float);
	void operator+=(vec2&);
	void operator-=(vec2&);

	float x;
	float y;
private:


};
