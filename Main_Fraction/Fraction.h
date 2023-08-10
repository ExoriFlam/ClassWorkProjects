#pragma once
#include <iostream>
using namespace std;

class Fraction
{
private:

	int numerator;
	int denominator;

	int gcd(int num, int denom);
	void short_fraction();
	void correct();
	template<typename T>
	T check_input();

public:

	Fraction();
	Fraction(int num, int denom);
	Fraction(const char* str_to_fraction);

	void set_numerator(const int val);
	int get_numerator()const;

	void set_denominator(const int val);
	int get_denominator()const;


	Fraction operator+(const Fraction& other)const;
	Fraction operator-(const Fraction& other)const;
	Fraction operator*(const Fraction& other)const;
	Fraction operator/(const Fraction& other)const;

	friend ostream& operator<<(ostream& out, const Fraction& obj);
	friend istream& operator>>(istream& in,Fraction& obj);


};

template<typename T>
T Fraction::check_input()
{
	T temp;
	cin >> temp;
	while (cin.fail())
	{
		cout << "\nÎøèáêà ââîäà!";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> temp;
	}

	return temp;
}
