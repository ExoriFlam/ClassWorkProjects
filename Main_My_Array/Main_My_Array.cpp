#include "My_Array.h"
#include <iostream>
#include <ctime>
#include "My_Array_Template.h"
using namespace std;


int main()
{
	srand(time(nullptr));
	system("chcp 1251>nul");

	MyArrayTemplate<char> a(5,'a');
	
	a[0] = 'b';
	a[1] = 'c';
	//cout << a;
	a.push_back('c');
	a.push_back('d');
	cout << a;
	system("pause");
}

