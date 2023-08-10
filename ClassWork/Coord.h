#pragma once
#include <iostream>
using namespace std;
class Coord
{
private:

	//const int MIN = -500;// ������ ��� ����������
	static int count; // ���������� ��������� ��������

	// �������������� ��������� � ������:
	//static const int MIN = -500; // ������� 1
	
	enum { MIN = -500, MAX = 500 }; // ������� 2
	
	int x;
	int y;
	//int* k;
	
	//Coord(); // ����������� ����� ���� private
	
	void correct();//private method

public:
	Coord();
	Coord(const int x,const int y);// ����������� � �����������

	//Coord(const int x = 0, const int y = 0);// ����������� � ����������� �� ���������

	explicit Coord(const int value); // ����������� � ����� ����������(����������� ��������������)
	explicit Coord(const char* str); // ����������� � ����� ����������(����������� ��������������)

	//����������� ����������� - ��������� ����������� ������ �� ������
	Coord(const Coord& obj);// ����������� �����������

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