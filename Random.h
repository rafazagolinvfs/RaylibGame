#pragma once

#include<cstdlib>
#include <time.h>
#include <vector>

template<class T>
class Random
{
public:
	Random();
	~Random();
	static T RandomRange(T min, T max);
	//static std::vector<T> ListNonRepetitiveNumbers(T amount, T min, T max)
	static std::vector<T> ListNonRepetitiveNumbers(T amount, T min, T max);


private:

};

