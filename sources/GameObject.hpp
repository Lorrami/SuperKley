#pragma once

#include "RectangleShape.hpp"

class GameObject: public RectangleShape
{
public:
	virtual void OnColliderEnter(GameObject *Object);
	virtual void Update(float dt);
};