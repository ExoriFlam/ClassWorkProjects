#include <iostream>
#include "Student.h"
#include "My_Array.h"
#include <stdarg.h>
using namespace std;



int main()
{
    system("chcp 1251>nul");
   
    Student a("Иванов", "Игорь", 1999, "079089987", "Школа 5", 6, 15, 5, 6, 7, 8, 9, 8, 7, 6, 5, 6,6,7,8,9,6);
    cout << a << endl;
    system("pause");
}   

