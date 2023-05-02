#pragma once

#include "Utils.h"
#include "EngineUtils.h"
#include "GameplayParams.h"

class Actor;
class Breakable;
class Obstacle;


class ItemsManager
{

public:
	ItemsManager();
	~ItemsManager();
	void RegisterPositions();
	void PlaceActorsOnGrid();
	void Update();

public:
	//Row Position for entities
	float initialPosX;
	float xPos[COLUMNS_AMOUNT];
	std::vector<std::pair<Vector2, bool>> columnPosition; // store positions (grid) and if it's ocuppied
	
	int rowsAmount; //rows amount to be used

private:
	void ManageItems();
	Obstacle* GetAvailableObstacle();
	Breakable* GetAvailableBreakable();
	void PlaceSeats();


private:
	int randMin;
	int randMax;
	std::vector<std::pair<Actor*, int>> placedActors;

	int actorsAmount;
	std::vector<int> seats;
};

