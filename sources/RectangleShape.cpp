#include "RectangleShape.hpp"
#include <core/print.hpp>

void RectangleShape::FindIntersection(RectangleShape *Wall)
{
	if (this->Position.x + this->Origin.x > Wall->Position.x - Wall->Origin.x
	 && this->Position.y + this->Origin.y > Wall->Position.y - Wall->Origin.y

	 && this->Position.x - this->Origin.x < Wall->Position.x + Wall->Origin.x
	 && this->Position.y - this->Origin.y < Wall->Position.y + Wall->Origin.y)
	{
		IsCrashed = true;
		Println("Crashed");
	}
}