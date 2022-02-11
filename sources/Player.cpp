#include "Player.hpp"

void Player::KeyboardUpdate(float dt)
{
	if (Keyboard::IsKeyPressed(Key::D))
	{
		Movement(m_Speed * dt, 0);
	}
	if (Keyboard::IsKeyPressed(Key::A))
	{
		Movement(-m_Speed * dt, 0);
	}
	if (Keyboard::IsKeyPressed(Key::S))
	{
		Movement(0, m_Speed * dt);
	}
	if (Keyboard::IsKeyPressed(Key::W))
	{
		Movement(0, -m_Speed * dt);
	}
}
void Player::RotationUpdate()
{
	float dx = -Application::Get().MousePosition().x + Position.x;
	float dy = -Application::Get().MousePosition().y + Position.y;
	float rotation = (atan2(dy, dx)) * 180.0f / 3.14159265f;
	Rotation = rotation;
}
void Player::Movement(float dx, float dy)
{
	Position += Vector2f(dx, dy);
}
void Player::Shooting()
{
	if (Mouse::IsButtonPressed(Mouse::Button::Left))
	{
		float dx = Application::Get().MousePosition().x - Position.x;
		float dy = Application::Get().MousePosition().y - Position.y;
		Application::Get().CurLevel().Add(new Bullet(Position, Vector2f(dx, dy)));
	}
}
Player::Player(float m_Size)
{
	Size = Vector2f(m_Size, m_Size);
	Position = Vector2f(60.0f, 60.0f);
	Origin = Vector2f(m_Size/2, m_Size/2);
	FillColor = Color::Red;
}
void Player::Update(float dt)
{
	KeyboardUpdate(dt);
	RotationUpdate();
	Shooting();
}