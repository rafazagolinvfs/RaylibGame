#include "ItemsManager.h"
#include "Scenario.h"
#include <random>
#include "GameplayParams.h"



ItemsManager::ItemsManager()
{
	initialPosX = 0;
	for (int i = 0; i < COLUMNS_AMOUNT * ROWS_AMOUNT; ++i)
	{
		const std::pair<Vector2, bool> hello;
		columnPosition.push_back(hello);
	}
}


ItemsManager::~ItemsManager()
{
}

void ItemsManager::RegisterPositions()
{
	/*We are operating a single-dimensional array as if it was a multi-dimensional array, that actually
	is less costly, but we will have to perform arithmetic operations to treat as if it was a multi-dimensional
	array...
	
	Also the reason why we have a separate 'RegisterPositions' method for registering actors positions is because
	we get the size of the scenario from the Scenario class to have a parameter for the initial position...*/
	
	//Save x coordinates
	float xPos[COLUMNS_AMOUNT];
	for (int i = 0; i < COLUMNS_AMOUNT; i++)
	{
		xPos[i] = initialPosX + i * ACTOR_SIZE_X * OFFSET_X;
	}

	for (int i = 0; i < ROWS_AMOUNT; i++)
	{
		const int test = i * COLUMNS_AMOUNT;
		for (int j = test;
			j < test + COLUMNS_AMOUNT; j++)
		{
			//let's start placing objects from the left side of the building
			//float posX = initialPosX + j * ACTOR_SIZE_X * 1.4f;
			int index = 0;

			//This will pretty (reset) the index that we want, no matter how far we are in our loop
			index = j % COLUMNS_AMOUNT; 

			//This will offset the actors y position everytime we get into a new row
			float posY = OFFSET_Y + i * OFFSET_Y; 
			columnPosition[j].first = Vector2{ xPos[index], posY};
			columnPosition[j].second = false;
		}
	}
}

void ItemsManager::PlaceActor(int spot, Actor* actor)
{
	if (spot > columnPosition.size())
		return;

	if (!columnPosition[spot].second)
		return;

	if (!actor)
		return;



}


void ItemsManager::Update()
{
	ManageItems();
}


void ItemsManager::ManageItems()
{

}
