#include "RectangleShape.hpp"
#include "core/print.hpp"

bool RectangleShape::FindIntersection(RectangleShape *Wall)
{
	if (this->Position.x + this->Origin.x > Wall->Position.x - Wall->Origin.x
	 && this->Position.y + this->Origin.y > Wall->Position.y - Wall->Origin.y
	 && this->Position.y - this->Origin.y > Wall->Position.y - Wall->Origin.y

	 && this->Position.x + this->Origin.x < Wall->Position.x + Wall->Origin.x
	 && this->Position.x - this->Origin.x < Wall->Position.x + Wall->Origin.x
	 && this->Position.y - this->Origin.y < Wall->Position.y + Wall->Origin.y)
	{
		//Println("Crashed");
		return true;
	}
}