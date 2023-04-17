#pragma once

#include <raylib.h>
#include <vector>
#include <string>


class Actor;
class Breakable;
class Player;

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
};

