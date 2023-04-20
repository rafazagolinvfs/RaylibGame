#include "Singleton.h"
#include "FactoryActor.h"


#include "Utils.h"

template class Singleton<Actor>;
template class Singleton<Vector2>;
template class Singleton<Controller>;
template class Singleton<Player>;
template class Singleton<Obstacle>;
template class Singleton<Breakable>;
template class Singleton<Scenario>;

template <class T>
Singleton<T>* Singleton<T>::mMainInstance = nullptr;

template <class T>
FactoryActor<T>* Singleton<T>::mFactoryActorClass = nullptr;

template <class T>
Singleton<T>::Singleton()
{

}

template <class T>
Singleton<T>* Singleton<T>::GetInstance()
{
	if (!mMainInstance)
	{
		mMainInstance = new Singleton();
	}
	return mMainInstance;
}

template <class T>
FactoryActor<T>* Singleton<T>::GetFactoryActor()
{
	if (!mFactoryActorClass)
	{
		mFactoryActorClass = new FactoryActor<T>();
	}
	return mFactoryActorClass;
}


template <class T>
void Singleton<T>::DestroyFactoryActor()
{
	if (GetFactoryActor())
	{
		delete GetFactoryActor();
	}
}
