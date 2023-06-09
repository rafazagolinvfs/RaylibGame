#include "FactoryActor.h"
#include "Actor.h"
#include "Controller.h"
#include "Obstacle.h"
#include "Breakable.h"
#include "Player.h"
#include "Scenario.h"

template class FactoryActor<Actor>;
template class FactoryActor<Vector2>;
template class FactoryActor<Controller>;
template class FactoryActor<Player>;
template class FactoryActor<Obstacle>;
template class FactoryActor<Breakable>;
template class FactoryActor<Scenario>;

int FactoryActor<int>::sUniqueIDCounter = 0;

template <class T>
FactoryActor<T>::~FactoryActor()
{
    std::cout << "Destroyed factory actor" << std::endl;
}

template <class T>
FactoryActor<T>::FactoryActor()
{
    srand(time(NULL));
}

template <typename T>
T* FactoryActor<T>::Spawn()
{
    return new T();
}

template<class T>
T* FactoryActor<T>::SpawnActor(Vector2 pos, Vector2 size)
{    
    return new T(pos, size);
}

