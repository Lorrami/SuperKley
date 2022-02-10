#include "Wall.hpp"

Wall::Wall(float Position)
{
	this->Position = {Position, Position};
	Size = {300, 300};
	FillColor = Color::Blue;
	Origin = {Size.x/2, Size.y/2};
}