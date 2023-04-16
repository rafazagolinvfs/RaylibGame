#pragma once

#include <raylib.h>
#include "Actor.h"

class Controller : public Actor
{
	friend class FactoryActor;
public:

	~Controller();

	void Possess(class Actor* pawn);
	virtual void Update() override;

private:
	Controller();
	void Move();
	Actor* possessedPawn;
};

