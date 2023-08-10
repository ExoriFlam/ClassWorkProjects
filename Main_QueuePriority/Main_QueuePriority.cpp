#include <iostream>
#include "QueuePriority.h"
using namespace std;


int main()
{
    system("chcp 1251>nul");
    QueuePriority a(10);
   
    a.Add(10, 4);
    a.Add(5, 3);
    a.Add(5, 5);
    a.Add(8, 2);
    a.Add(1, 1);
    
    /*cout << a.Extract() << endl;
    cout << a.Extract() << endl;
    cout << a.Extract() << endl;
    cout << a.Extract() << endl;*/
    cout << a;

   /* a.Extract();
    a.Extract();
    a.Extract();
    a.Extract();
    a.Extract();
    cout << a << endl;

    QueuePriority b(10);
    b = move(a);
    cout << b<<endl;
    QueuePriority c(move(b));
    cout << c << endl;*/
    system("pause");

}