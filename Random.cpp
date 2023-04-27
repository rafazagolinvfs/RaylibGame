#include "Random.h"

template class Random<int>;

template <class T>
Random<T>::Random()
{
	srand((unsigned)time(NULL));

}
template <class T>
Random<T>::~Random()
{
}


template <class T>
T Random<T>::RandomRange(T min, T max)
{
	return min + (rand() % max);
}


