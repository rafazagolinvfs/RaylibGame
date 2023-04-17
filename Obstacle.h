#pragma once
#include "Actor.h"


template <typename T>
class FactoryActor;

class Actor;

class Obstacle : public Actor
{
	template<typename T>
	friend class FactoryActor;

private:
	Obstacle(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Obstacle_1.png");
	}
	Obstacle()
	{

	}

	virtual void Update() override;
	
};

