#pragma once

#include "FactoryActor.h"

class Level;

template <typename T>
class FactoryActor;


template <class T>
class Singleton
{
public:
	static Singleton<T>* GetInstance();
	static FactoryActor<T>* GetFactoryActor();
	static void DestroyFactoryActor();

private:
	Singleton();

	static Singleton* mMainInstance;
	static FactoryActor<T>* mFactoryActorClass;	

};


