#include "ItemsManager.h"
#include "Scenario.h"
#include "Obstacle.h"
#include "Breakable.h"
#include "Random.h"
#include "Level.h"


ItemsManager::ItemsManager()
{
	randMin = 1;
	randMax = 3;
	initialPosX = 0;
	rowsAmount = 1;
	for (int i = 0; i < COLUMNS_AMOUNT * ROWS_AMOUNT; ++i)
	{
		const std::pair<Vector2, bool> hello;
		columnPosition.push_back(hello);
	}
	for (int i = 0; i < COLUMNS_AMOUNT * ROWS_AMOUNT; ++i)
	{
		const std::pair<Actor*, int> hello;
		placedActors.push_back(hello);
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
	we get the size of the scenario from the Scenario class to have a parameter for the initial position...

	Oh yes, this is just laying out the 'grid' for us to use later. It is not placing any actor.
	*/

	//Save x coordinates	
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
			float posY = INITIAL_Y_POS + i * OFFSET_Y;
			columnPosition[j].first = Vector2{ xPos[index], posY };
			columnPosition[j].second = false;
		}
	}
}

void ItemsManager::PlaceActorsOnGrid()
{
	while (actorsAmount < 3)
	{
		//We can figure it out later 
		//int desiredRow = 1; // row 1 == index of row is 0 to 4, row 2 == index of row is 5 to 9


		/*TODO: Finish implementing this method. Start with one row first then move to the others
			with the necessary checks
		*/
		//let's assume for now that we some spot in row 1, so we set the correct range (0 to 4)
		int randomPosition = Random<int>::RandomRange(0, 4);

		//If the spot it's occupied, return.
		if (!columnPosition[randomPosition].second)
		{
			//LOG("Attempt to place actor " << " position is ocuppied " << randomPosition);


			Actor* actor = GetAvailableObstacle();

			if (actor)
			{
				actor->SetPosition({ columnPosition[randomPosition].first });
				actor->isPlaced = true;
				columnPosition[randomPosition].second = true;
				placedActors[actorsAmount].first = actor;
				placedActors[actorsAmount].second = randomPosition;


				//LOG("placedActors[" << actorsAmount << "].second:" << placedActors[actorsAmount].second);
				//LOG("PlaceActorsOnGrid..." << " random number = " << randomPosition);
				actorsAmount++;
			}
		}
	}
}

void ItemsManager::Update()
{
	ManageItems();
}


void ItemsManager::ManageItems()
{
	/// <summary>
	/// The idea is to constantly check if all actors that were placed at this "round" are gone (Below of screen). 
	/// If they are gone, that means we can start another round (PlaceActors()).
	/// </summary>
	for (auto itr : placedActors)
	{
		if (itr.first)
		{
			//That means some actor is not below screen boundaries				
			if (itr.first->IsNotBelowScreen())
			{
				//LOG("Cannot reset position!");
				return;
			}

			if (!itr.first->IsNotBelowScreen())
			{
				columnPosition[itr.second].second = false;
				itr.first->isPlaced = false;
			}
		}
	}

	actorsAmount = 0;
	PlaceActorsOnGrid();
}

Obstacle* ItemsManager::GetAvailableObstacle()
{
	for (auto itr : Level::obstacles)
	{
		if (!itr->isPlaced)
			return itr;
	}
	return nullptr;
}