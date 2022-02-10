#pragma once

class GameObject: public sf::RectangleShape
{
public:
	virtual void OnColliderEnter(GameObject *Object);
	virtual void Update(float dt) = 0;
};