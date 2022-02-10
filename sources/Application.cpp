#pragma once

#include "Application.hpp"

Application Application::s_Instance;

void Application::Run()
{
	Semaphore think;
	while (m_Window.IsOpen())
	{
		float dt = m_GameClock.GetElapsedTime().AsSeconds();
		m_GameClock.Restart();

		m_Window.AcquireNextFramebuffer(&think);
		m_Window.PresentCurrentFramebuffer(&think);
		
		m_Level.Update(dt);
		m_Level.Draw(&m_Window);

		m_Window.DispatchEvents();
	}
}

Vector2s Application::MousePosition()
{
	return Mouse::RelativePosition(m_Window);
}
Level& Application::CurLevel()
{
	return m_Level;
}

Application& Application::Get()
{
	return s_Instance;
}

