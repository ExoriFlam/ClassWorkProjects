#include <iostream>
#include "Track.h"

using namespace std;


Track::Track()
{
	this->weight = 0;
	this->speed = 0;
}

Track::Track(int _weight, int _speed)
{
	this->weight = _weight;
	this->speed = _speed;
}

void Track::show() const
{
	
	cout << "\nГрузовместимость:          " << this->weight;
	cout << "\nСкорость:                  " << this->speed;
	cout << "\n\n";
}
