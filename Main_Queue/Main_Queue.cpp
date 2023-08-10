#include <iostream>
#include "Queue.h"
using namespace std;



int main()
{
    system("chcp 1251>nul");
    Queue a,b;
    cout << a << endl;
    a.Add(1);
    a.Add(2);
    a.Add(3);
    a.Add(4);
    a.Add(5);
    a.Add(6);
    a.Add(7);
    a.Add(8);
    a.Add(9);
    cout << a << endl;
    b = (a);
    cout << b << endl;
    Queue c(b);
    cout << c << endl;
    system("pause");
}

