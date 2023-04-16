#pragma once

#include <iostream>
#include <raylib.h>

class Actor;
class Controller;

class FactoryActor
{
	friend class Singleton;
public:
	static int sUniqueIDCounter;
	static Actor* SpawnActor();
	static Controller* SpawnController();
	static Actor* SpawnActor(Vector2 position, Vector2 size);

	~FactoryActor()
	{
		std::cout << "Destroyed factory actor" << std::endl;
	}
private:
	FactoryActor();
	static FactoryActor* GetInstance();
	static FactoryActor* sInstance;
};