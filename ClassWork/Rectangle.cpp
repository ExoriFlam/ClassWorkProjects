#include "Rectangle.h"
#include <iostream>
#include <cstring>
using namespace std;




void Rectangle::dyn_str_copy(char*& destination, const char* source)
{
	if (source)
	{
		destination = new char[strlen(source) + 1];
		if (destination)
		{
			strcpy_s(destination, strlen(source) + 1, source);
		}
		else
		{
			cout << "������! ������ �� ��������.";
			destination = nullptr;
			strcpy_s(this->color_name, "no_color");
			this->width = 0;
			this->height = 0;
			this->symbol = '\0';
		}
	}
	else
	{

		destination = nullptr;
		strcpy_s(this->color_name, "no_color");
		this->width = 0;
		this->height = 0;
		this->symbol = '\0';

	}

	


}

Rectangle::Rectangle() :
	width{ 0 }, height{ 0 }, symbol{ '*' }
{
	strcpy_s(color_name, "no color");
	dyn_str_copy(this->name, "no_name");
}

Rectangle::Rectangle(const int width, const int height, const char symbol, const char* name, const char* cn) :
	width{ width }, height{ height }, symbol{ symbol }
{
	strcpy_s(color_name, cn);
	dyn_str_copy(this->name, name);
}

Rectangle::Rectangle(const char* cn, const char* name) : 
	width{ 10 }, height{ 10 }, symbol{ '#'}
{
	strcpy_s(color_name, cn);
	dyn_str_copy(this->name, name);
}

Rectangle::Rectangle(const Rectangle& other) :
	width{ other.width }, height{ other.height }, symbol{ other.symbol }
{
	strcpy_s(this->color_name, other.color_name);
	dyn_str_copy(this->name, other.name);
}

///////////////////////////////////////////////////////////////////////
Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this == &other) return *this;

	if (strlen(this->name) != strlen(other.name))
	{
		delete[]this->name;
		
	}
	strcpy_s(this->color_name, other.color_name);
	this->width = other.width;
	this->height = other.height;
	this->symbol = other.symbol;
	dyn_str_copy(this->name, other.name);
}

ostream& operator<<(ostream& out, const Rectangle& obj)
{
	out << "\n������ : " << obj.width;
	out << "\n������ : " << obj.height;
	out << "\n������ : " << obj.symbol;
	out << "\n����   : " << obj.color_name;
	out << "\n�������:  " << obj.area() << endl;

	return out;
}

istream& operator>>(istream& in, Rectangle& obj)
{
	char buf[64];
	int input;

	cout << "\n������ :       ";
	in >> input;
	while (in.fail())
	{
		cout << "\n������� �����.";
		in.clear();
		in.ignore(256, '\n');
		in >> input;
	}
	obj.width = input;

	cout << "������ :       ";
	in >> input;
	while (in.fail())
	{
		cout << "\n������� �����.";
		in.clear();
		in.ignore(256, '\n');
		in >> input;
	}
	obj.height = input;

	cout << "\n������������ : ";
	in.get();
	in.getline(buf, sizeof(buf));
	if (obj.name)
	{
		delete[]obj.name;
	}
	obj.dyn_str_copy(obj.name, buf);

	cout << "���� :           ";
	in.getline(obj.color_name, sizeof(obj.color_name));

	cout << "������ :         ";

	in >> obj.symbol;


	return in;
}

//////////////////////////////////////////////////////////////////////
void Rectangle::set_width(const int width)
{
	this->width = width;
}

int Rectangle::get_width() const
{
	return width;
}

void Rectangle::set_height(const int h)
{
	height = h;
}

int Rectangle::get_height()const
{
	return this->height;
}

void Rectangle::set_symbol(const char s)
{
	symbol = s;
}

char Rectangle::get_symbol()const
{
	return symbol;
}

void Rectangle::set_color(const char* cn)
{
	
	strcpy_s(color_name, cn);
}

const char* Rectangle::get_color()const
{
	return color_name;
}

void Rectangle::set_name(const char* name)
{
	if (this->name)
	{
		delete[]this->name;
	}
	dyn_str_copy(this->name, name);
}



int Rectangle::area()const
{
	
	return (height * width);
}

int Rectangle::perimetr()const
{
	
	return (2 * (this->width + height));
}

void Rectangle::show(const Rectangle* mas, const int size)
{
	
	for (int i = 0; i < size; i++)
	{
		cout << mas[i];
	}
}


Rectangle::~Rectangle()
{
	delete[]this->name;
	name = nullptr;
	
	
}

