#include "My_Array.h"
#include <iostream>
#include <ctime>
using namespace std;

MyArray foo1(MyArray obj)
{
	return obj;
}

int main()
{
	srand(time(nullptr));
	system("chcp 1251>nul");

	/*Задание 1. В уже существующий класс MyArray добавьте следующие методы :
	    − конструктор перемещения,
		− оператор присваивания с перемещением,
		− преобразование типа MyArray к целому : возврат суммы значений массива,
		− преобразование типа MyArray к дробному : возврат среднего арифметического значения
		массива,
		− преобразование типа MyArray к char* : возврат значений элементов массива в виде
		строки(разделитель между значениями - пробел).
		Продемонстрируйте работу методов на примерах.*/

	int hh[10] = {0,0,-12314,125,16,1123157,118,11239,2120,21 };
	int jj[15] = { 245,1234,1,23,65,753,23456,214,567,8904,312,-12,-13,9876,-10 };
	MyArray a(10,hh);
	MyArray b(15, jj);
	//char* str = a;
	//const char* str = a;
	//int z = a;
	//cout << z;
	//double g = a;
	cout << (char*)a;
	a = b;
	cout << "\n\n\n\n";
	cout << (char*)a;
	cout << "\n\n\n\n";
	cout << (int)a;
	cout << "\n\n\n\n";
	cout << (double)a;
	//d = (a + b);
	//delete[]str;
	system("pause");
}

