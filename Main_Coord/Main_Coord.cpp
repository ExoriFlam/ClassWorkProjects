#include <iostream>
#include "Coord.h"
#include <stdarg.h>
using namespace std;

enum { INT = 0, DOUBLE, COORD };

double AnyType(int count, int typeof, ...);

int main()
{
	system("chcp 1251>nul");
	/*Coord a;
    
    cout << a;
    Coord c = a;
    cout << Coord::get_count();
    cout << c;
    cin >> c;*/

    cout << AnyType(3, DOUBLE, 1.1,2.2,3.3);


    system("pause");
}

double AnyType(int count, int typeof, ...)
{
    int sum_int = 0;     

    double sum_double = 0.0;

    Coord sum_coord = {0,0};

    va_list arg_ptr;    

    va_start(arg_ptr, count);

    va_arg(arg_ptr, int);

    while (count--) {

        switch (typeof)
        {
        case INT:
            sum_int += va_arg(arg_ptr, int);
            break;
        case DOUBLE:
            sum_double += va_arg(arg_ptr, double);
            break;
        case COORD:
            sum_coord += va_arg(arg_ptr, Coord);
            break;
        default:
            return 0;
        }
    }

    va_end(arg_ptr);

    switch (typeof)
    {
    case INT:
        return sum_int;
    case DOUBLE:
        return sum_double;
    case COORD:
        return sum_coord;
    default:
        return 0.0;
    }

}



