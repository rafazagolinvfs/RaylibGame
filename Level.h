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

private:
	std::vector<Actor*> entities;
	std::vector<Actor*> notPlayerTEMP;
	Player* player;
};

