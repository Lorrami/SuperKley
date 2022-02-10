#pragma once

#include "Level.hpp"
#include <graphics/render_window.hpp>
#include <core/os/clock.hpp>
#include <core/math/vector2.hpp>

class Application
{
public:
	static Application *s_Instance;
private:
	RenderWindow m_Window{ 700, 700, "Shooter"};
	Level m_Level;
    Clock m_GameClock;
private:
	Application() = default;
public:
	void Run();
	Vector2s MousePosition();
	Level& CurLevel();

	static Application &Get();
};