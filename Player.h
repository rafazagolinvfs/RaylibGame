#pragma once
#include "Actor.h"

template <typename T>
class FactoryActor;


class Player : public Actor
{
	template <typename T>
	friend class FactoryActor;
private:
	Player(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Ralph.png");
		movSpeed = 100.f;
	}	
	Player()
	{

	}
	
	virtual void Move(Vector2 dir) override;

};

