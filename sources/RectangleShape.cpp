#include "RectangleShape.hpp"

bool RectangleShape::FindIntersection(RectangleShape *Object)
{
	if (this->Position - this->Origin == Object->Position - Object->Origin)
	{
		return true;
	}
}