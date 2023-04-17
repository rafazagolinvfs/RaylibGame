#pragma once

#include <iostream>
#include <raylib.h>
#include "Utils.h"

//forward declaration
class Actor;
class Controller;
class Obstacle;
class Breakable;
class Player;
class Scenario;

template <typename T>
class Singleton;

template <class T>
class FactoryActor
{
	template <typename T>
	friend class Singleton;

public:
	static int sUniqueIDCounter;

	static T* Spawn();
	static T* SpawnActor(Vector2 pos, Vector2 size);


	~FactoryActor();
private:
	FactoryActor();
	static FactoryActor* GetInstance();
	static FactoryActor* sInstance;
};