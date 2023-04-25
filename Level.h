#pragma once

#include "EngineUtils.h"
#include "Utils.h"
#include "GameplayParams.h"



//Forward declaration
class Actor;
class Breakable;
class Player;
class Controller;
class UserInterface;

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

private:
	std::vector<Actor*> entities;
	std::vector<Actor*> actorsForThePlayerActorToCollideWith;
	std::array<Actor*, COLUMNS_AMOUNT> breakables;
	std::array<Actor*, COLUMNS_AMOUNT * ROWS_AMOUNT> enemies;
	Player* player;

	UserInterface* ui;
	Controller* controller;
};

