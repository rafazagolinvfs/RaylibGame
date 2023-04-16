#pragma once
#include "Actor.h"

class Obstacle : public Actor
{
	friend class FactoryActor;
private:
	Obstacle(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Obstacle_1.png");
	}
	
};

