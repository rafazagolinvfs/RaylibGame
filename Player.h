#pragma once
#include "Actor.h"
#include "UserInterface.h"

template <typename T>
class FactoryActor;


class Player : public Actor
{
	template <typename T>
	friend class FactoryActor;

public:
	
private:
	Player(Vector2 position, Vector2 size) : Actor(position, size)
	{
		sprite = LoadTexture("resources/Ralph.png");
		movSpeed = 250.f;
		collisionOverlapBind = &Actor::OnOverlap;// binding the delegate
	}	
	Player() {}
	
	virtual void Move(Vector2 dir) override;
	virtual void OnOverlap(Actor* collidedActor) override;

};

