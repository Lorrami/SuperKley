#include "Application.hpp"

Application *Application::s_Instance = nullptr;

Application::Application() {
	m_Window.SetEventsHanlder({this, &Application::OnEvent});
}

void Application::Run()
{
	Semaphore acqure, present;
	while (m_Window.IsOpen())
	{
		float dt = m_GameClock.GetElapsedTime().AsSeconds();
		m_GameClock.Restart();

		m_LastMousePosition = Mouse::RelativePosition(m_Window);

		m_Window.AcquireNextFramebuffer(&acqure);
		m_Renderer.BeginDrawing(&acqure, m_Window.CurrentFramebuffer());
		m_Renderer.DrawRect({0,0}, m_Window.Size(),Color::Black);
		m_Level.Draw(&m_Renderer);
		m_Renderer.EndDrawing(&present);
		m_Window.PresentCurrentFramebuffer(&present);
		
		m_Level.Update(dt);

		m_Window.DispatchEvents();
		//Sleep(Milliseconds(12));
	}
}

Vector2s Application::MousePosition()
{
	return m_LastMousePosition;
}

Level& Application::CurLevel()
{
	return m_Level;
}

void Application::OnEvent(const Event& e) {
	if (e.Type == EventType::WindowClose)
		m_Window.Close();
}

Application& Application::Get()
{
	if(s_Instance == nullptr)
		s_Instance = new Application();
	return *s_Instance;
}

