#pragma once

#include "EngineUtils.h"
#include "Utils.h"
#include "GameplayParams.h"



//Forward declaration
class Actor;
class Breakable;
class Obstacle;
class Player;
class Controller;
class UserInterface;
class ItemsManager;

class Level
{
public:
	void Update();
	Level();
	~Level();

	inline std::vector<Actor*> GetEntities() const
	{
		return entities;
	}

	static std::array<Breakable*, ACTORS_AMOUNT> breakables;
	static std::array<Obstacle*, ACTORS_AMOUNT> obstacles;
	ItemsManager* itemsManager;
	

private:
	std::vector<Actor*> entities;
	std::vector<Actor*> actorsForThePlayerActorToCollideWith;
	Player* player;

	UserInterface* ui;
	Controller* controller;
};

