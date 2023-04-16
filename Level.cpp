#include "Level.h"
#include "Actor.h"
#include "Controller.h"

#include "Singleton.h"
#include "FactoryActor.h"

Level::Level()
{
	
	//Player
	Actor* player = Singleton::GetFactoryActor()->SpawnActor(Vector2{0.f, 500.f}, Vector2{ 50.f, 100.f });
	if (player)
	{
		entities.push_back(&*player);
	}
	

	//Controller
	Controller* controller = Singleton::GetFactoryActor()->SpawnController();
	if (controller)
	{
		entities.push_back(&*controller);
		controller->Possess(player);
	}


	//Obstacles

	//Breakable things

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
		if (!entities[i])
		{
			return;
		}
		entities[i]->Render(RED);
		entities[i]->Update();
	}
}


