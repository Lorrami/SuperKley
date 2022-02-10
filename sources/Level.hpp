#pragma once

#include <core/list.hpp>
#include <graphics/render_window.hpp>
#include "Player.hpp"

class Level
{
private:
	List<GameObject*> m_Objects;
	List<GameObject*> m_PendingAddObjects;
	List<GameObject*> m_PendingRemoveObjects;
public:
	Level();
	void Add(GameObject* Object);
	void Remove(GameObject* Object);
	void Update(float dt);
	void Draw(RenderWindow *window);
};