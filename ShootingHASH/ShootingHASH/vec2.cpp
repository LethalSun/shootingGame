#include "pch.h"
#include "vec2.h"

vec2::vec2(float pX = 0.f, float pY = 0.f)
	:x{ pX }
	, y{ pY }
{
}

vec2::vec2()
	: x{ 0.f }
	, y{ 0.f }
{
}

vec2::~vec2()
{
}

vec2 vec2::operator+(vec2 & other)
{
	return vec2(x + other.x, y + other.y);
}

vec2 vec2::operator-(vec2 & other)
{
	return vec2(x - other.x, y - other.y);
}

vec2 vec2::operator*(float  other)
{
	return vec2(x*other, y*other);
}

void vec2::operator+=(vec2 & other)
{
	x += other.x;
	y += other.y;
}

void vec2::operator-=(vec2 & other)
{
	x -= other.x;
	y -= other.y;
}

