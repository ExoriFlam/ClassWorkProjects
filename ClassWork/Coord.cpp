#include "Coord.h"
#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

#define DEBUG

// ������������� ����������� ���������� ������
int Coord::count = 0; // ���������� ��������� ��������

Coord::Coord() : x(0), y { 0 }
{
#ifdef DEBUG
	cout << "\n����������� �� ���������";
#endif // DEBUG
	
	this->count++;
}

Coord::Coord(const int x, const int y) 
{
#ifdef DEBUG
	cout << "\n����������� � �����������";
#endif // DEBUG
	
	this->x = x;
	this->y = y;
	this->count++;
	correct();
}

Coord::Coord(const int value)
{
#ifdef DEBUG
	cout << "\n����������� ��������������";
#endif // DEBUG
	this->x = this->y = value;
	this->count++;
	correct();
}

Coord::Coord(const char* str) : x{ 0 }, y{ 0 }
{
#ifdef DEBUG
	cout << "\n����������� ��������������";
#endif // DEBUG

	char* copy{nullptr};
	copy = new char[strlen(str) + 1];
	if (copy)
	{
		strcpy_s(copy, strlen(str) + 1, str);

		char* t2 = nullptr;
		char* t1 = strtok_s(copy, ", :/_.\\;", &t2);

		this->x = atoi(t1);
		
		if (t2)
		{
			this->y = atoi(t2);
		}
		

		correct();
		this->count++;

		delete[] copy;
		copy = nullptr;
	}
	else
	{
		cout << "������! ������ �� ��������.";
		copy = nullptr;
	}
	
	
}

Coord::Coord(const Coord& obj)// ����������� �����������
{
#ifdef DEBUG
	cout << "\n����������� �����";
#endif // DEBUG
	this->x = obj.x;
	this->y = obj.y;
	this->count++;
}


void Coord::set_x(int val)
{
	this->x = val;
	correct();
}

void Coord::set_y(int val)
{
	this->y = val;
	correct();
}

int Coord::get_x() const
{
	//this->x = 2;
	return x;
}

int Coord::get_y() const
{
	return y;
}

void Coord::reset_x_y(int x, int y)
{
	this->x = x;
	this->y = y;
	correct();
}

void Coord::init()
{
	
	cout << "\nEnter X : ";
	cin >> x;
	cout << "\nEnter Y : ";
	cin >> y;
	this->correct();
}

void Coord::show()const
{
	cout << "\n X : " << x;
	cout << "\n Y : " << y<< endl;
}

Coord Coord::add(const Coord& obj) const
{
	Coord res;

	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	res.correct();

	return res;
}

Coord Coord::operator+(const Coord& obj) const
{
	Coord res;
	res.x = this->x + obj.x;
	res.y = this->y + obj.y;
	return res;
}

Coord Coord::operator+(const int val)
{
	Coord res{x+val,y+val};
	return res;
}

Coord& Coord::operator+=(const Coord& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	
	return *this;
}

bool Coord::operator==(const Coord& obj) const
{
	return this->x == obj.x && this->y == obj.y ? true : false;
}

bool Coord::operator!=(const Coord& obj) const
{
	
	return (!(*this == obj));
}

bool Coord::operator>(const Coord& obj) const
{
	return (this->x > obj.x && this->y > obj.y);
}

Coord& Coord::operator++()
{
	this->x++;
	this->y++;
	return *this;
}

Coord Coord::operator++(int)
{
	Coord res = *this;
	this->x++;
	this->y++;
	return res;
}

Coord Coord::operator-() const
{
	Coord result(-x,-y);
	return result;
}

void Coord::operator()(const int a, const int b)
{
	this->x = a;
	this->y = b;

}

Coord::operator int()
{
	return this->x * this->y;
}


Coord::~Coord()
{
	count--;
#ifdef DEBUG
	cout << "\n���������� "<< count;
	//_getch();
#endif // DEBUG

	
}

void Coord::correct()
{
	if (this->x < MIN)
		this->x = MIN;
	if (this->y < MIN)
		this->y = MIN;
	if (x > MAX)
		x = MAX;
	if (y > MAX)
		y = MAX;

}

ostream& operator<<(ostream& out, const Coord& right)
{
	out << "{" << right.x << ";" << right.y << "}";
	return out;
}

istream& operator>>(istream& in,Coord& right)
{
	cout << "\n������� x:\n";
	in >> right.x;
	cout << "\n������� y:\n";
	in >> right.y;
	return in;
}

Coord operator+(const int left, const Coord& right)
{
	return Coord(right.x+left,right.y+left);
}
