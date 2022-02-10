#pragma once

#include "GameObject.hpp"
#include <core/os/keyboard.hpp>
#include <core/os/mouse.hpp>

class Player : public GameObject
{
private:
	float m_Speed = 200.0f;
	void KeyboardUpdate(float dt);
	void RotationUpdate();
	void Movement(float dx, float dy);
	void Shooting();
public:
	Player(float m_Size);
	void Update(float dt) override;
};