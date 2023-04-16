#pragma once

#include <raylib.h>
#include <vector>
#include <string>

class Actor;

class Level
{
public:
	Level();
	~Level();
	std::vector<Actor*> entities;

	void Update();
};

