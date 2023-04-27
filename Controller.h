#pragma once

#include <raylib.h>
#include "Actor.h"

template <typename T>
class FactoryActor;

class UserInterface;
class ItemsManager;

class Controller : public Actor
{
	template <typename T>
	friend class FactoryActor;
public:
	~Controller();
	void Possess(class Actor* pawn);
	virtual void Update() override;

	UserInterface* ui;
	ItemsManager* itemsManager;

private:
	Controller();
	Controller(Vector2 position, Vector2 size) : Actor(position, size){}	
	void Move();
	void GridMovement();
	void Smash();
	Actor* possessedPawn;
	int desiredGridPosX;
	bool dKeyOnce;
	bool aKeyOnce;

};

