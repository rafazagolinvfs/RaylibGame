#include "Level.h"
#include "Player.h"
#include "Controller.h"
#include "Scenario.h"
#include "Obstacle.h"
#include "Breakable.h"
#include "UserInterface.h"
#include "ItemsManager.h"

#include "Singleton.h"
#include "FactoryActor.h"
#include "Utils.h"

//int FactoryActor<int>::sUniqueIDCounter = 0;
std::array<Obstacle*, COLUMNS_AMOUNT* ROWS_AMOUNT> Level::obstacles;
std::array<Breakable*, COLUMNS_AMOUNT* ROWS_AMOUNT> Level::breakables;


Level::Level()
{
	/*------------------- LOADING EVERYTHING -------------------*/


	//Scenario
	Scenario* scenario = Singleton<Scenario>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (390.f / 2.f), 0.f },
		Vector2{ 390.f, SCREEN_Y }
	);
	scenario->ignoreCollision = true;
	entities.push_back(&*(Actor*)scenario);

	//Scenario2 for parallax
	Scenario* scenario1 = Singleton<Scenario>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (390.f / 2.f), -SCREEN_Y },
		Vector2{ 390.f, SCREEN_Y }
	);
	scenario1->ignoreCollision = true;
	entities.push_back(&*(Actor*)scenario1);

	//ItemsManager
	itemsManager = new ItemsManager();

	//Assigning scenario for items manager class 
	itemsManager->initialPosX = scenario->GetPosition().x;
	itemsManager->RegisterPositions();

	
	//Breakable things
	for (int i = 0; i < Level::breakables.size(); ++i)
	{
		//let's start placing the enemy from the left side of the building 		
		//const float posX = itemsManager->columnPosition[i].first.x;
		//const float posY = itemsManager->columnPosition[i].first.y;
		//itemsManager->columnPosition[i].second = true;//flag that spot as occupied

		Breakable* br = Singleton<Breakable>::GetFactoryActor()->SpawnActor
		(
			Vector2{ -100.f , -100.f },
			Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
		);
		Level::breakables[i] = br;
	}


	//Enemies
	for (int i = 0; i < Level::obstacles.size(); ++i)
	{
		//let's start placing the enemy from the left side of the building 		
		//const float posX = itemsManager->columnPosition[i].first.x;
		//const float posY = itemsManager->columnPosition[i].first.y;
		//itemsManager->columnPosition[i].second = true;//flag that spot as occupied

		Obstacle* obstacle = Singleton<Obstacle>::GetFactoryActor()->SpawnActor	
		(
			Vector2{ -100.f , -100.f },
			Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
		);
		Level::obstacles[i] = obstacle;
	}

	//Registering entities in level master update!
	for (Breakable* const& itr : Level::breakables)
	{
		if (itr != NULL)
		{
			entities.push_back(&*(Actor*)itr);
		}
	}

	//Registering entities in level master update!
	for (Obstacle* const& itr : Level::obstacles)
	{		
		if (itr != NULL)
		{
			entities.push_back(&*(Actor*)itr);
		}		
	}	

	//Player
	Player* player = Singleton<Player>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (50.f / 2.f), SCREEN_Y - ACTOR_SIZE_Y },
		Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
	);

	if (player)
	{
		player->level = this;
		entities.push_back(&*player);

		//Player User interface
		ui = new UserInterface();
		player->ui = ui;
	}

	//Controller
	controller = Singleton<Controller>::GetFactoryActor()->Spawn();
	if (controller)
	{
		entities.push_back(&*controller);
		controller->Possess(player);
		controller->ui = ui;
		controller->itemsManager = itemsManager;
	}

	if (itemsManager)
		itemsManager->PlaceActorsOnGrid();
}

Level::~Level()
{
	//Clean memory
	for (int i = 0; i < entities.size(); ++i)
	{
		delete& entities[i];
	}
}

void Level::Update()
{
	controller->Update();
	switch (ui->GetCurrentScreen())
	{
		case EScreen::Menu: {
			//TODO: Render menu screen, process input
			if (ui)
			{
				DrawTexture(ui->menuScreen, SCREEN_X / 2 - ui->menuScreen.width /2, 0, WHITE);
			}
		}
			break;

		case EScreen::Game: {

			//Tell every registered actor to update and render itself
			for (int i = 0; i < entities.size(); ++i)
			{
				if (!&entities[i] || !entities[i])
					return;

				entities[i]->Render(RED);
				entities[i]->Update();
				if (itemsManager)
					itemsManager->Update();
			}
			ui->OutputScore();
		}
			break;

		case EScreen::GameOver: {
			//TODO: Render game over screen, process input
			if (ui)
			{
				DrawTexture(ui->gameOverScreen, 0, 0, WHITE);
			}
		}
			break;
	}
};