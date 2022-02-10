#pragma once

#include "GameObject.hpp"
#include <iostream>

void GameObject::OnColliderEnter(GameObject* NextObject)
{
	
	std::cout << NextObject << std::endl;
} 