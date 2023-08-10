#pragma once
//#include "Track.h"

class Track;

class Car {

private:
	int passageCap;
	int speed;

public:
	Car();
	Car(int _passageCap, int _speed);

	void show() const;

	friend int speed_compare(const Car& c, Track& t);
};