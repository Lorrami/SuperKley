#pragma once

#include "GameObject.hpp"

class Bullet : public GameObject
{
private:
	float m_Speed = 400.0f;
	float m_LifeTime = 0, m_DeathTime = 3;
	Vector2f Direction;
public:
	Bullet(Vector2f Position, Vector2f Direction);
	void Update(float dt) override;
};