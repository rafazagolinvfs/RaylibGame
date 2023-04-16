#pragma once

#include "Actor.h"

class Breakable : public Actor
{
	friend class FactoryActor;
private:

	Breakable(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Breakable.png");
	}

	
};

