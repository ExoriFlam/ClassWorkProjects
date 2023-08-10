#pragma once
#include<iostream>
using namespace std;

class MyArray
{
private:

	unsigned int size;
	int* arr;

public:
	MyArray();
	MyArray(int size, int init_val);
	MyArray(int size, int* other_arr);
	MyArray(const MyArray& other);
	MyArray(int size, int range_begin, int range_end);

	
	MyArray& operator=(const MyArray& other);
	int& operator[](const int index);
	const int operator[](const int index)const;
	MyArray operator+(const MyArray& other)const;
	MyArray operator+(const int)const;
	MyArray& operator+=(int val);
	MyArray& operator+=(MyArray& other);
	friend MyArray operator+(int val, const MyArray& other);
	friend ostream& operator<<(ostream& out, const MyArray& obj);
	friend istream& operator>>(istream& in, MyArray& obj);

	unsigned int get_size()const;

	int get_avg()const;


	void push_back(int val);

	
	~MyArray();
};