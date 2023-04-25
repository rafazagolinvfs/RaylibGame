#pragma once

#include "Utils.h"
#include "EngineUtils.h"

class Actor;


class ItemsManager
{

public:
	ItemsManager();
	~ItemsManager();
	void RegisterPositions();
	void PlaceActor(int spot, Actor* actor);
	void Update();

public:
	//Row Position for entities
	float initialPosX;
	std::vector<std::pair<Vector2, bool>> columnPosition;


private:
	void ManageItems();
};

