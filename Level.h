#pragma once

#include <raylib.h>
#include <vector>
#include <string>
#include "UserInterface.h"


class Actor;
class Breakable;
class Player;
class Controller;

class Level
{
public:
	void Update();
	Level();
	~Level();
	std::vector<Actor*> entities;

private:
	std::vector<Actor*> ActorsForThePlayerActorToCollideWith;
	Player* player;
	UserInterface* ui;
	Controller* controller;
};

