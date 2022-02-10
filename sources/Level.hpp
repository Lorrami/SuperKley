#pragma once

#include <core/list.hpp>
#include <2d/rect_renderer.hpp>
#include <graphics/render_window.hpp>
#include "Player.hpp"

class Level
{
private:
	List<GameObject*> m_Objects;
	List<GameObject*> m_Walls;
	List<GameObject*> m_PendingAddObjects;
	List<GameObject*> m_PendingRemoveObjects;
public:
	Level();
	void Add(GameObject* Object);
	void Remove(GameObject* Object);
	void Update(float dt);
	void Draw(RectRenderer *Renderer);
};