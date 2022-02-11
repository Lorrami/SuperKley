#pragma once

#include "RectangleShape.hpp"

class GameObject: public RectangleShape
{
public:
	virtual void Update(float dt);
};