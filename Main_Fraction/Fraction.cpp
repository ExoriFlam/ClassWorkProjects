#include <iostream>
#include "Fraction.h"

using namespace std;

int Fraction::gcd(int num, int denom)
{
	if (denom == 0) return num;
	else return gcd(denom, num % denom);
	
}

void Fraction::short_fraction()
{
	Fraction temp{ this->numerator,this->denominator };
	numerator /= gcd(temp.numerator, temp.denominator);
	denominator /= gcd(temp.numerator, temp.denominator);
}

void Fraction::correct()
{
	denominator = (denominator < 1) ? 1 : denominator;
}

Fraction::Fraction() : numerator{0}, denominator{1} {}
Fraction::Fraction(int num, int denom) :
	numerator{ num }, denominator{ (denom < 1) ? 1 : denom } {}

Fraction::Fraction(const char* str_to_fraction) :
	numerator{ 0 }, denominator{ 1 }
{
	char str[40];
	strcpy_s(str, str_to_fraction);
	if (str[0] == '\0')
	{
		cout << "\nВы ввели пустую строку.\nОбъект будет проинициализирован по умолчанию...\n";

	}
	else
	{
		bool nume_found = false;
		int result = 0;


		int i = 0;                      // Перебираем всю строку, если попадеется символ не цифра то меняем его на \0. 
		while (str[i] != '\0')          // В дльнейшем int i будет использоваться как длина строки.
		{
			if (!((str[i] - 0) > 47 && (str[i] - 0) < 58))
			{
				str[i] = '\0';

			}
			i++;
		}

		for (int j = 0; (j <= i); j++)  // В этом цикле мы формируем число пока не доходим до разделителя \0, после этого записываем число в числитель 
		{                               // и ставим флаг, что числитель найден. Следующее сформированное число попадет в знаменатель.
										// Признаком, что число найдено и нужно его записать является \0. Поэтому мы двигаемся до сайз + 1 или <=  
			if (str[j] != '\0')         // ,так как если после второго числа небыло никаких разделительных символов, то не сработает условие else if
			{                           // и оно не запишется.

				result *= 10;
				result += (str[j] - 48);

			}
			else if (result > 0)
			{
				if (!nume_found)
				{
					this->numerator = result;
					result = 0;
					nume_found = true;
				}
				else
				{

					this->denominator = result;
					break;
				}
			}

		}
	}
}

void Fraction::set_numerator(const int val)
{
	numerator = val;
}

int Fraction::get_numerator() const
{
	return numerator;
}

void Fraction::set_denominator(const int val)
{

	denominator = (val < 1 ? val : 1);
}

int Fraction::get_denominator() const
{
	return denominator;
}

Fraction Fraction::operator+(const Fraction& other) const
{
	Fraction temp_fr{ numerator * other.denominator + denominator * other.numerator, denominator * other.denominator };
	temp_fr.short_fraction();
	return temp_fr;
}

Fraction Fraction::operator-(const Fraction& other) const
{
	Fraction temp_fr{ numerator * other.denominator - denominator * other.numerator, denominator * other.denominator };
	temp_fr.short_fraction();
	return temp_fr;
}

Fraction Fraction::operator*(const Fraction& other) const
{
	Fraction temp_fr{ numerator * other.numerator ,denominator * other.denominator };
	temp_fr.short_fraction();
	return temp_fr;
}

Fraction Fraction::operator/(const Fraction& other) const
{
	Fraction temp_fr{ numerator * other.denominator, denominator * other.numerator };
	temp_fr.short_fraction();
	return temp_fr;
}



ostream& operator<<(ostream& out, const Fraction& obj)
{
	return (out << obj.numerator << " / " << obj.denominator);
}

istream& operator>>(istream& in, Fraction& obj)
{
	
	cout << "\nВведите чеслитель : ";
	obj.numerator = obj.check_input<int>();
	cout << "\nВведите знаменатель : ";
	obj.denominator = obj.check_input<int>();
	obj.correct();
	obj.short_fraction();
	return in;
}
