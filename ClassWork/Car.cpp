#include <iostream>
#include "Car.h"
#include "Track.h"
using namespace std;

Car::Car()
{
	this->passageCap = 0;
	this->speed = 0;
}

Car::Car(int _passageCap, int _speed)
{
	this->passageCap = _passageCap;
	this->speed = _speed;
}

void Car::show() const
{
	cout << "\nКоличество пассажиров:     " << this->passageCap;
	cout << "\nСкорость:                  " << this->speed;
	cout << "\n\n";
}

int speed_compare(const Car& c, Track& t)
{
	return c.speed - t.speed;
}
