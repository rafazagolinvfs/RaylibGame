#pragma once
#include "Actor.h"


template <typename T>
class FactoryActor;

class Actor;

class Scenario : public Actor
{
	template<typename T>
	friend class FactoryActor;

private:
	Scenario(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/EnvironmentBase2.png");
		
	}
	Scenario()
	{

	}

	virtual void Update() override;

};

