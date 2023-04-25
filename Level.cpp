#include "Level.h"
#include "Player.h"
#include "Controller.h"
#include "Scenario.h"
#include "Obstacle.h"
#include "UserInterface.h"

#include "Singleton.h"
#include "FactoryActor.h"
#include "ItemsManager.h"
#include "Utils.h"

Level::Level()
{
	/*------------------- LOADING EVERYTHING -------------------*/


	//Scenario
	Scenario* scenario = Singleton<Scenario>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (390.f / 2.f), 0.f },
		Vector2{ 390.f, SCREEN_Y }
	);
	scenario->IgnoreCollision = true;
	entities.push_back(&*(Actor*)scenario);

	//Scenario2 for parallax
	Scenario* scenario1 = Singleton<Scenario>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (390.f / 2.f), -SCREEN_Y },
		Vector2{ 390.f, SCREEN_Y }
	);
	scenario1->IgnoreCollision = true;
	entities.push_back(&*(Actor*)scenario1);

	//Assigning scenario for items manager class 
	ItemsManager* itemsManager = new ItemsManager();
	itemsManager->initialPosX = scenario->GetPosition().x;
	itemsManager->RegisterPositions();

	
	//Breakable things
	//Breakable* item = Singleton<Breakable>::GetFactoryActor()->SpawnActor
	//(
	//	Vector2{ 75.f, 100.f },
	//	Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
	//);
	//entities.push_back(&*(Actor*)item);


	for (int i = 0; i < enemies.size(); ++i)
	{
		//let's start placing the enemy from the left side of the building 		
		const float posX = itemsManager->columnPosition[i].first.x;
		const float posY = itemsManager->columnPosition[i].first.y;
		itemsManager->columnPosition[i].second = true;//flag that spot as occupied

		Obstacle* obstacle = Singleton<Obstacle>::GetFactoryActor()->SpawnActor	
		(
			Vector2{ posX , posY },
			Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
		);
		enemies[i] = obstacle;
	}
	//Registering entities in level master update!
	for (const auto& itr : enemies)
	{
		entities.push_back(&*(Actor*)itr);
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
	}
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
			//Tell every registered entity to update and render itself
			for (int i = 0; i < entities.size(); ++i)
			{
				if (!&entities[i] || !entities[i])
					return;

				entities[i]->Render(RED);
				entities[i]->Update();

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