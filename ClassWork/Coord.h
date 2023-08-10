#pragma once
#include <iostream>
using namespace std;
class Coord
{
private:

	//const int MIN = -500;// ошибка при присвоении
	static int count; // количество созданных объектов

	// Специфическаие константы в классе:
	//static const int MIN = -500; // вариант 1
	
	enum { MIN = -500, MAX = 500 }; // вариант 2
	
	int x;
	int y;
	//int* k;
	
	//Coord(); // конструктор может быть private
	
	void correct();//private method

public:
	Coord();
	Coord(const int x,const int y);// конструктор с параметрами

	//Coord(const int x = 0, const int y = 0);// конструктор с параметрами по умолчанию

	explicit Coord(const int value); // конструктор с одним параметром(конструктор преобразования)
	explicit Coord(const char* str); // конструктор с одним параметром(конструктор преобразования)

	//конструктор копирования - принимает константную ссылку на объект
	Coord(const Coord& obj);// конструктор копирования

	void set_x(int val);
	void set_y(int val);

	int get_x()const;
	int get_y()const;

	static int get_count() {
		return count;
	}

	void reset_x_y(int x = 0, int y = 0);

	void init();

	void show()const;

	Coord add(const Coord& obj)const;

	Coord operator+(const Coord& obj)const;
	Coord operator+(const int val);
	Coord& operator+=(const Coord& obj);
	bool operator==(const Coord& obj) const;
	bool operator!=(const Coord& obj) const;
	bool operator>(const Coord& obj) const;
	Coord& operator++();
	Coord operator++(int);
	Coord operator-()const;
	void operator()(const int a, const int b);
	operator int();

	friend ostream& operator<<(ostream& out, const Coord& right);
	friend istream& operator>>(istream& in, Coord& right);
	friend Coord operator+(const int left, const Coord& right);

	~Coord();
};