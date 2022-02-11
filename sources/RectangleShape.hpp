#pragma once

#include <graphics/color.hpp>
#include <core/math/vector2.hpp>
#include "core/print.hpp"

struct RectangleShape
{
	Vector2f Position;
	Color FillColor;
	Vector2f Size;
	Vector2f Origin;
	float Rotation = 0;

	bool FindIntersection(RectangleShape *Object);
};