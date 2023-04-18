#pragma once

#include <raylib.h>
#include "Actor.h"

template <typename T>
class FactoryActor;

class Controller : public Actor
{
	template <typename T>
	friend class FactoryActor;
public:

	

	~Controller();

	void Possess(class Actor* pawn);
	virtual void Update() override;

private:
	Controller();
	Controller(Vector2 position, Vector2 size) : Actor(position, size)
	{

	}
	void Move();
	void Smash();
	Actor* possessedPawn;
};

