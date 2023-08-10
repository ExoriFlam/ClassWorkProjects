//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <assert.h>
#include "MyString.h"
#include <cstring>
using namespace std;

#define DEBUG

int MyString::count = 0;

void MyString::dyn_str_copy(char*& destination, const char* source)
{


	if (source)
	{
		if (destination)
		{
			if (strlen(destination) != strlen(source))
			{
				delete[]destination;
				destination = new char[strlen(source) + 1];
			}

			if (destination)
			{
				strcpy_s(destination, strlen(source) + 1, source);
			}
			else
			{
				cout << "\nПамять не выделена.";
			}
		}
		else
		{
			destination = new char[strlen(source) + 1];

			if (destination)
			{
				strcpy_s(destination, strlen(source) + 1, source);
			}
			else
			{
				cout << "\nПамять не выделена.";
			}

		}

	}

}

MyString::MyString() : MyString("Hello")
{
#ifdef DEBUG
	cout << "\nКонструткор по умолчанию\n";
#endif // DEBUG

	count++;
}

MyString::MyString(const char* string)
{
#ifdef DEBUG
	cout << "\nКонструктор преобразования\n";
#endif // DEBUG

	length = strlen(string);
	dyn_str_copy(this->str, string);

	count++;
}

MyString::MyString(int len, char symbol) : length{ len }

{
#ifdef DEBUG
	cout << "\nКонструктор с двумя параметрами - длина и символ\n";
#endif // DEBUG
	str = new char[length + 1];
	if (str)
	{
		for (int i = 0; i < length; i++)
		{
			str[i] = symbol;
		}
		str[length] = '\0';
		count++;
	}
	else
	{
		cout << "Память не выделена";
		length = 0;
	}

}


MyString::MyString(const MyString& obj)
{
#ifdef DEBUG
	cout << "\nКонструктор копирования\n";
#endif // DEBUG

	dyn_str_copy(this->str, obj.str);
	length = obj.length;
	count++;
}

MyString::MyString(MyString&& obj)
{
	this->length = obj.length;
	this->str = obj.str;
	obj.str = nullptr;
	obj.length = 0;

	count++;
}


void MyString::init(const char* str)
{
	dyn_str_copy(this->str, str);
	this->length = strlen(str);
}



int MyString::get_length()const
{
	return length;
}


/*static */ int MyString::getCount() //статический метод
{
	return count;
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	dyn_str_copy(this->str, obj.str);
	this->length = obj.length;

	return *this;
}

MyString& MyString::operator=(MyString&& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (this->str) delete[]str;
	this->length = obj.length;
	this->str = obj.str;
	obj.length = 0;
	obj.str = nullptr;

	return *this;
}

const char MyString::operator[](const int index) const
{

	if (index < 0 || index > this->length)
	{
		cout << "\n Неверный индекс";
		return '\0';
	}

	return this->str[index];
}

char& MyString::operator[](const int index)
{
	return this->str[index];

}

bool MyString::operator==(const MyString& other)const
{
	return _strcmpi(this->str, other.str) == 0;
}

bool MyString::operator!=(const MyString& other)const
{
	return !(*this == other);
}

bool MyString::operator>(const MyString& other)const
{
	return _strcmpi(this->str, other.str) > 0;
}

bool MyString::operator<(const MyString& other)const
{
	return _strcmpi(this->str, other.str) < 0;
}

bool MyString::operator>=(const MyString& other)const
{
	return (*this > other || *this == other);
}

bool MyString::operator<=(const MyString& other)const
{
	return (*this < other || *this == other);
}

MyString MyString::operator+(const MyString& other) const
{
	int max_size = this->length + other.length;
	MyString temp(max_size, ' ');

	strcpy_s(temp.str, max_size + 1, this->str);
	strcat_s(temp.str, max_size + 1, other.str);

	return temp;
}

MyString& MyString::operator+=(const MyString& other)
{
	MyString temp = *this + other;
	*this = temp;
	return *this;
}

void MyString::operator()(const char* str)
{
	dyn_str_copy(this->str, str);
	this->length = strlen(str);
}

MyString::operator char* ()
{

	return this->str;

}


MyString::~MyString()
{
	count--;
#ifdef DEBUG
	cout << "\nДеструктор  " << count + 1 << endl;

#endif // DEBUG

	delete[]str;
	str = nullptr;
}

ostream& operator<<(ostream& out, const MyString& obj)
{
	out << obj.str;
	return out;
}

istream& operator>>(istream& in, MyString& obj)
{
	char buf[256];

	cin.getline(buf, sizeof(buf));
	obj.dyn_str_copy(obj.str, buf);
	obj.length = strlen(buf);

	return in;
}

