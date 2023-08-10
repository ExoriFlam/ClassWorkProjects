#pragma once
#include <iostream>
using namespace std;

class Rectangle {


	enum{N = 30};

	int width; 
	int height;
	char symbol;
	char color_name[N];
	char* name;

	void dyn_str_copy(char*& destination, const char* source);

public:
	
	Rectangle();
	
	Rectangle(const int _width, const int height, const char symbol, const char* name, const char* cn);

	Rectangle(const char* cn, const char* name);

	Rectangle(const Rectangle& obj);

	Rectangle& operator=(const Rectangle& other);
	friend ostream& operator<<(ostream& out,const Rectangle& obj);
	friend istream& operator>>(istream& in, Rectangle& obj);

	void set_width(const int width);
	int get_width()const;

	void set_height(const int h);
	int get_height()const;

	void set_symbol(const char s);
	char get_symbol()const;

	void set_color(const char* cn);
	const char* get_color()const;

	void set_name(const char* name);


	
	
	int area()const;
	int perimetr()const;
	
	
	static void show(const Rectangle* mas, const int size);

	
	~Rectangle();
};




