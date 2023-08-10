#pragma once
//#include "Car.h"

class Car;

class Track {
private:
	int weight;
	int speed;


public:
	Track();
	Track(int _weight, int _speed);

	void show() const;
	friend int speed_compare(const Car& c, Track& t);
};
