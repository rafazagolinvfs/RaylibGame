#include "Level.h"
#include "Player.h"
#include "Controller.h"

#include "Singleton.h"
#include "FactoryActor.h"
#include "Utils.h"

void CollisionBehaviour(Level &currentLevel, Actor* actor)
{
	currentLevel.entities.erase(std::find(currentLevel.entities.begin(), currentLevel.entities.end(), actor));
	LOG("Hit");
};

Level::Level()
{	
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
	player = Singleton<Player>::GetFactoryActor()->SpawnActor
	(
		Vector2{ SCREEN_X / 2.f - (50.f / 2.f), SCREEN_Y - 100.f },
		Vector2{ ACTOR_SIZE_X, ACTOR_SIZE_Y }
	);

	if (player)
	{
		player->isPlayerActor = true;
		entities.push_back(&*player);
	}

	//Controller
	//Controller* controller = Singleton<Controller>::GetFactoryActor()->SpawnController();
	Controller* controller = Singleton<Controller>::GetFactoryActor()->Spawn();
	if (controller)
	{
		entities.push_back(&*controller);
		controller->Possess(player);
	}

	for (auto actor : entities)
	{
		if (actor->isPlayerActor) continue;
		ActorsForThePlayerActorToCollideWith.push_back(actor);
	}

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
		if (!&entities[i])
		{
			return;
		}
		entities[i]->Render(RED);
		entities[i]->Update();

		player->Collide(CollisionBehaviour, *this, ActorsForThePlayerActorToCollideWith);
	}
};