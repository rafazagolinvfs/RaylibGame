#pragma once

#include "Actor.h"

template <typename T>
class FactoryActor;

class Breakable : public Actor
{
	template <typename T>
	friend class FactoryActor;
private:

	Breakable(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Breakable.png");		
	}
	Breakable() : Actor()
	{

	}

	virtual void Update() override;

};

