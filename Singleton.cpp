#include "Singleton.h"
#include "FactoryActor.h"


Singleton* Singleton::mMainInstance = nullptr;
FactoryActor* Singleton::mFactoryActorClass = nullptr;

Singleton::Singleton()
{

}

Singleton* Singleton::GetInstance()
{
	if (!mMainInstance)
	{
		mMainInstance = new Singleton();
	}
	return mMainInstance;
}

FactoryActor* Singleton::GetFactoryActor()
{
	if (!mFactoryActorClass)
	{
		mFactoryActorClass = new FactoryActor();
	}
	return mFactoryActorClass;
}

void Singleton::DestroyFactoryActor()
{
	if (GetFactoryActor())
	{
		delete GetFactoryActor();
	}
}
