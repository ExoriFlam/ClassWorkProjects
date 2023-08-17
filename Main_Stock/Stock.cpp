#include "Stock.h"
#include <cstring>
#include <iomanip>


void Stock::dyn_str_copy(char*& destination, const char* source)
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

Stock::Stock(const char* _name, const char* _platform, int count, double price) : count{ count }, price{ price }
{
	strcpy_s(name, _name);
	dyn_str_copy(this->platform, _platform);
	total_price = this->count * price;

}

Stock::Stock()
{
	strcpy_s(name, "no name");
	dyn_str_copy(this->platform, "no platform");
	count = 0;
	this->price = 0;
	this->total_price = count * price;
}

Stock::Stock(const Stock& other) : count{other.count}, price{other.price}
{
	strcpy_s(name, other.name);
	dyn_str_copy(this->platform, other.platform);
	
	this->total_price = other.total_price;
}



void Stock::show() const
{
	cout << setprecision(2) << fixed;
	cout << "\nНазвание             :" << name;
	cout << "\nПлатформа            :" << platform;
	cout << "\nКол-во               :" << count;
	cout << "\nЦена                 :" << price;
	cout << "\nОбщая цена           :" << total_price;
	cout << endl;
}

void Stock::set_name(const char* name)
{
	strcpy_s(this->name, name);
}

void Stock::set_platform(const char* platform)
{
	dyn_str_copy(this->platform, platform);
}

void Stock::set_count(int count)
{
	this->count = count;
	this->total_price = this->price * this->count;
}

void Stock::set_price(double price)
{
	this->price = price;
	this->total_price = this->price * count;
}

const char* Stock::get_name()const
{
	return name;
}

const char* Stock::get_platform()const
{
	return platform;
}

int Stock::get_count()const
{
	return count;
}

double Stock::get_price()const
{
	return price;
}

double Stock::get_total_price() const
{
	return this->total_price;
}

void Stock::buy_stock(int count)
{
	this->count += count;
	this->total_price = this->count * this->price;
}

bool Stock::sell_stock(int count)
{
	if (count <= this->count)
	{
		this->count -= count;
		this->total_price = this->count * this->price;
		return true;
	}
}

void Stock::input()
{
	cout << "\nВведите название фирмы : ";
	cin.getline(name, sizeof(name));
	cout << "\nВведите название платформы : ";
	char buf[64];

	cin.getline(buf, sizeof(buf));
	dyn_str_copy(this->platform, buf);

	cout << "\nВведите колличество: ";
	cin >> count;
	cout << "\nВведите стоимость одной акции : ";
	cin >> price;
	cin.get();
	this->total_price = this->price * this->count;

}

Stock::~Stock()
{
	delete[]this->platform;
	this->platform = nullptr;
}
