#pragma once
#include <iostream>
using namespace std;

class Stock
{
private:
	char name[50];
	char* platform;
	int count;
	double price;

	double total_price;

    void dyn_str_copy(char*& destination, const char* source);
public:
    Stock(const char* name, const char* platform, int count, double price);
	Stock();
    Stock(const Stock& other);
	void show()const;

    void set_name(const char* name);
    void set_platform(const char* platform);
    void set_count(int count);
    void set_price(double price);

    const char* get_name()const;
    const char* get_platform()const;
    int get_count()const;
    double get_price()const;
    double get_total_price()const;

    void buy_stock(int count);
    bool sell_stock(int count);

    void input();


	~Stock();

};

