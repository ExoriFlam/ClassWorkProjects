#include <iostream>
#include <iomanip>
#include "Fraction.h"
using namespace std;


int main()
{
	system("chcp 1251>nul");
	
	Fraction a1(5, 5), b1(5, 5),d1,e1,f1,g1,c1;

	d1 = a1 + b1;
	e1 = a1 - b1;
	f1 = a1 * b1;
	g1 = a1 / b1;
	cout << d1 << ", " << e1 << ", " << f1 << ", " << g1 <<endl;
	cin >> c1;
	cout << c1;
	


	cout << endl;
	system("pause");
}
