#pragma once

#include <graphics/color.hpp>
#include <core/math/vector2.hpp>

struct RectangleShape
{
	Vector2f Position;
	Color FillColor;
	Vector2f Size;
	Vector2f Origin;
	float Rotation = 0;
	//void GetGlobalBounds(){}
	bool FindIntersection(RectangleShape *Object);
};