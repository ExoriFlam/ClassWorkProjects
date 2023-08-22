#pragma once
#include <iostream>
using namespace std;


struct Element
{
	char data;       // данные
	Element* next;   // адрес следующего элемента

};

class List_1
{
private:
	Element* head;
	int count;

public:
	List_1();
	List_1(const List_1& other);
	List_1(List_1&& other)noexcept;
	List_1& operator=(const List_1& other);
	List_1& operator=(List_1&& other)noexcept;
	void push_back(const char& data);
	void push_front(const char& data);

	void pop_back();
	void pop_front();

	void insert_after_data(const char& after, const char& src);
	
	void clear();
	void show()const;


	int get_index_by_data(const char& data);
	char get_data_by_index(const int& index)const;
	void insert_elem_by_index(const int& index);
	void insert_data_before_index(const int& index, const char& data);
	void erase_by_index(const int& index);

	int get_count()const { return count; }

	bool containe(const char& data)const;

	bool operator<(const List_1& other)const;
	bool operator>(const List_1& other)const;

	bool operator==(const List_1& other)const;
	bool operator!=(const List_1& other)const;
	bool operator>=(const List_1& other)const;
	bool operator<=(const List_1& other)const;

	List_1 operator+(const List_1& other)const;
	List_1 operator-()const;
	List_1 operator*(const List_1& other)const;

	friend ostream& operator <<(ostream& out, const List_1& obj);
	friend istream& operator >>(istream& in, List_1& obj);
	~List_1();
};