#pragma once
#include "Actor.h"
class Player : public Actor
{
	friend class FactoryActor;
private:
	Player(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Ralph.png");
	}	
	
	virtual void Move(Vector2 dir) override;

};

