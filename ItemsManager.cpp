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
	for (int i = 0; i < ACTORS_AMOUNT; ++i)
	{
		const std::pair<Actor*, int> hello;
		placedActors.push_back(hello);
	}

	RandomActors(1, 20);
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

			//This will it (reset) to the index that we want, no matter how far we are in our loop
			index = j % COLUMNS_AMOUNT;

			//This will offset the actors y position every time we get into a new row
			float posY = INITIAL_Y_POS + i * OFFSET_Y;
			columnPosition[j].first = Vector2{ xPos[index], posY };
			columnPosition[j].second = false;
		}
	}
}

void ItemsManager::RowCheck()
{

}

void ItemsManager::PlaceActorsOnGrid()
{
	int placedRowsN = 0; // keeps track of placed rows amount
	const int rowsAmount = Random<int>::RandomRange(1, 3);
	PlaceSeats();

	/*This will work for one row only.
	TODO: Make it work with multiple rows. Prob we will have to have one more while loop (nested while loops)*/
	while (placedRowsN < rowsAmount)
	{

		// Place actors on the grid based on the desired row amount

		int desiredWindowsAmount = Random<int>::RandomRange(1, 4);		


		//	while (columnController < COLUMNS_AMOUNT)
		//	{
				// Check If the spot it's not occupied
				//if (!columnPosition[chosenSeat].second)
				//{
				//	Actor* actor = GetAvailableObstacle();
				//	if (actor)
				//	{
				//		actor->SetPosition({ columnPosition[chosenSeat].first });
				//		actor->isPlaced = true;
				//		columnPosition[chosenSeat].second = true;
				//		placedActors[chosenSeat].first = actor;
				//		placedActors[chosenSeat].second = chosenSeat;
				//		if (indexToRemove - 1 < seats.size())
				//			seats.erase(seats.begin() + indexToRemove - 1);
				//	}
				//}
		//	}


		//Place breakables
		while (desiredWindowsAmount > 0)
		{

			int indexToRemove = Random<int>::RandomRange(placedRowsN, placedRowsN + (COLUMNS_AMOUNT - 1));
			int chosenSeat = seats[indexToRemove];

			if (!columnPosition[chosenSeat].second)
			{
				Actor* actor = GetAvailableBreakable();
				if (actor)
				{
					actor->SetPosition({ columnPosition[chosenSeat].first });
					actor->isPlaced = true;
					columnPosition[chosenSeat].second = true;
					placedActors[chosenSeat].first = actor;
					placedActors[chosenSeat].second = chosenSeat;

					if (indexToRemove - 1 < seats.size())
						seats.erase(seats.begin() + indexToRemove - 1);

				}
			}

			if(placedRowsN > 0)
			{
				// check either if it's empty or placed with a breakable
				// the reason why we minus 5 is to get the row above at exact on the same column
				Actor* actor = placedActors[chosenSeat - 5].first;				
				if (Breakable* br = dynamic_cast<Breakable*>(actor))
				{
				}
				else if(!actor) // that means there is no actor there
				{
				}
			}

			desiredWindowsAmount--;
		}

		//Place obstacles
		placedRowsN++;

#pragma region Old Way
		//int indexToRemove = Random<int>::RandomRange(1, seats.size());
		//int chosenSeat = seats[indexToRemove - 1];

		//// Check If the spot it's not occupied
		//if (!columnPosition[chosenSeat].second)
		//{
		//	Actor* actor = GetAvailableObstacle();

		//	if (actor)
		//	{
		//		actor->SetPosition({ columnPosition[chosenSeat].first });
		//		actor->isPlaced = true;
		//		columnPosition[chosenSeat].second = true;
		//		placedActors[chosenSeat].first = actor;
		//		placedActors[chosenSeat].second = chosenSeat;

		//		if (indexToRemove - 1 < seats.size())				
		//			seats.erase(seats.begin() + indexToRemove - 1);
		//		
		//		itr++;
		//	}
		//}
#pragma endregion
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
	for (auto& itr : placedActors)
	{
		if (itr.first)
		{
			if (itr.first->IsNotBelowScreen())
			{
				return;
			}
		}
	}

	// LOG("All actors reached the bottom");

	// hacky way to make some randomness for our game
	RandomActors(1, 20);


	//Resetting things
	for (auto& itr : placedActors)
	{
		if (itr.first)
		{
			columnPosition[itr.second].second = false;
			itr.first->isPlaced = false;
			itr.first = NULL;
		}
	}

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

Breakable* ItemsManager::GetAvailableBreakable()
{
	for (auto itr : Level::breakables)
	{
		if (!itr->isPlaced)
			return itr;
	}
	return nullptr;
}

void ItemsManager::PlaceSeats()
{
	if (seats.size() > 0)
		seats.clear();


	for (int i = 0; i < ACTORS_AMOUNT; i++)
	{
		seats.push_back(i);
	}
}

void ItemsManager::RandomActors(int min, int max)
{
	actorsAmount = Random<int>::RandomRange(min, max);
}