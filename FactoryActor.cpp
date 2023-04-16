#include "FactoryActor.h"
#include "Actor.h"
#include "Controller.h"
#include "Obstacle.h"
#include "Breakable.h"
#include "Player.h"

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

Controller* FactoryActor::SpawnController()
{
    return new Controller();
}

Actor* FactoryActor::SpawnActor(Vector2 position, Vector2 size)
{
    return new Actor(position, size);
}

Obstacle* FactoryActor::SpawnObstacle(Vector2 position, Vector2 size)
{
    return new Obstacle(position, size);
}

Breakable* FactoryActor::SpawnBreakable(Vector2 position, Vector2 size)
{
    return new Breakable(position, size);
}

Player* FactoryActor::SpawnPlayer(Vector2 position, Vector2 size)
{
    return new Player(position, size);
}
