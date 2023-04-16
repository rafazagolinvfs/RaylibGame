#pragma once

#include <iostream>
#include <raylib.h>

//forward declaration
class Actor;
class Controller;
class Obstacle;
class Breakable;

class FactoryActor
{
	friend class Singleton;
public:
	static int sUniqueIDCounter;	
	static Actor* SpawnActor(Vector2 position, Vector2 size);
	static Controller* SpawnController();
	static Obstacle* SpawnObstacle(Vector2 position, Vector2 size);
	static Breakable* SpawnBreakable(Vector2 position, Vector2 size);



	~FactoryActor()
	{
		std::cout << "Destroyed factory actor" << std::endl;
	}
private:
	FactoryActor();
	static FactoryActor* GetInstance();
	static FactoryActor* sInstance;
};