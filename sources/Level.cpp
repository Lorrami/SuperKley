#include "Level.hpp"

Level::Level()
{
	m_Objects.Add(new Player(60.0f));
	m_Walls.Add(new Wall(300.0f));
}
void Level::Add(GameObject* Object)
{
	m_PendingAddObjects.Add(Object);
}
void Level::Remove(GameObject* Object)
{
	m_PendingRemoveObjects.Add(Object);
}
void Level::Update(float dt)
{
    for (GameObject *Object: m_Objects)
	{
        Object->Update(dt);
		for (GameObject* Wall : m_Walls)
		{
			if (Object->FindIntersection(Wall))
			{
				Object->OnColliderEnter(Wall);
			}
		}
	}
	m_Objects.Append(m_PendingAddObjects);
	m_PendingAddObjects.Clear();

	for (GameObject* Object : m_PendingRemoveObjects)
	{ 
		m_Objects.UnorderedRemove(Object);
	}
	m_PendingRemoveObjects.Clear();
}
void Level::Draw(RectRenderer *Renderer)
{
	for(GameObject *Object: m_Objects)
	{
		Renderer->DrawRect(Object->Position, Object->Size, Object->Origin, Object->Rotation, Object->FillColor);
	}
	for (RectangleShape* Object : m_Walls)
	{
		Renderer->DrawRect(Object->Position, Object->Size, Object->Origin, Object->Rotation, Object->FillColor);
	}
}