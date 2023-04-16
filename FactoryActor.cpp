#include "FactoryActor.h"
#include "Actor.h"
#include "Controller.h"

#include <time.h>
#include <stdlib.h>

FactoryActor* FactoryActor::sInstance = nullptr;
int FactoryActor::sUniqueIDCounter = 0;

FactoryActor::FactoryActor()
{
    srand(time(NULL));
}

FactoryActor* FactoryActor::GetInstance()
{
    if (!sInstance)
    {
        sInstance = new FactoryActor();
    }
    return sInstance;
}

Actor* FactoryActor::SpawnActor()
{
    return new Actor();
}

Controller* FactoryActor::SpawnController()
{
    return new Controller();
}

Actor* FactoryActor::SpawnActor(Vector2 position, Vector2 size)
{
    return new Actor(position, size);
}

