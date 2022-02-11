#include "Bullet.hpp"
#include "Application.hpp"
#include <iostream>
#include <cmath>
#include <core/print.hpp>

Bullet::Bullet(Vector2f Position, Vector2f Direction)
{
	this->Direction = Direction / (float)sqrt(Direction.x * Direction.x + Direction.y * Direction.y);
	FillColor = Color::Red;
	this->Position = Position;
	Rotation = atan2(this->Direction.y, this->Direction.x) * 180.0f / 3.14159265f;
	Size = Vector2f(10.0f, 10.0f);
	Origin = Vector2f(Size.x / 2, Size.y / 2);
}

void Bullet::Update(float dt)
{
	m_LifeTime += dt;
	if (m_LifeTime > m_DeathTime || IsCrashed)
	{
		Application::Get().CurLevel().Remove(this);
	}
	FillColor = Color(255, (uint8_t)(255 * (m_LifeTime / m_DeathTime)), 0, 255);
	Position += Direction * m_Speed * dt;
}