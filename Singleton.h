#pragma once

#include <string>

class FactoryActor;

class Singleton
{
public:
	static Singleton* GetInstance();
	static FactoryActor* GetFactoryActor();
	static void DestroyFactoryActor();

private:
	Singleton();

	static Singleton* mMainInstance;
	static FactoryActor* mFactoryActorClass;
};
