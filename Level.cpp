#include "Level.h"
#include "Player.h"
#include "Controller.h"
#include "Scenario.h"
#include "Obstacle.h"

#include "Singleton.h"
#include "FactoryActor.h"
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

	//scenario2
	Scenario* scenario1 = Singleton<Scenario>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (390.f / 2.f), -SCREEN_Y },
		Vector2{ 390.f, SCREEN_Y }
	);
	scenario1->IgnoreCollision = true;
	entities.push_back(&*(Actor*)scenario1);


	//Breakable things
	Breakable* item = Singleton<Breakable>::GetFactoryActor()->SpawnActor
	(
		Vector2{ 0.f, 100.f }, 
		Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
	);
	entities.push_back(&*(Actor*)item);


	//Obstacles
	Obstacle* obstacle = Singleton<Obstacle>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (50.f / 2.f), 100.f },
		Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
	);
	entities.push_back(&*(Actor*)obstacle);

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
	}

	//Controller
	Controller* controller = Singleton<Controller>::GetFactoryActor()->Spawn();
	if (controller)
	{
		entities.push_back(&*controller);
		controller->Possess(player);
	}

	ui = new UserInterface();
	player->ui = ui;
}

Level::~Level()
{
	//Clean memory
	for (int i = 0; i < entities.size(); ++i)
	{
		delete &entities[i];
	}
}

void Level::Update()
{
	for (int i = 0; i < entities.size(); ++i)
	{
		if (!&entities[i] || !entities[i])
			return;
		
		entities[i]->Render(RED);
		entities[i]->Update();
	}

	ui->OutputScore();
};