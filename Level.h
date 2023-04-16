#pragma once

#include <raylib.h>
#include <vector>
#include <string>


class Actor;
class Breakable;

class Level
{
public:
	void Update();
	Level();
	~Level();

private:
	std::vector<Actor*> entities;
};

