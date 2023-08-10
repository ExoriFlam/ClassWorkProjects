#include <iostream>
#include "QueuePriority.h"
using namespace std;


int main()
{
    system("chcp 1251>nul");
    QueuePriority a(10);
   
    a.Add(10, 3);
    a.Add(9, 2);
    a.Add(8, 1);
    a.Add(7, 3);
    a.Add(6, 2);
    a.Add(5, 1);
    a.Add(4, 3);
    a.Add(3, 2);
    a.Add(2, 1);
    a.Add(1, 1);
    cout << a<<endl;
  
    a.Extract();
    a.Extract();
    a.Extract();
    a.Extract();
    a.Extract();
    cout << a << endl;

    QueuePriority b(10);
    b = move(a);
    cout << b<<endl;
    QueuePriority c(move(b));
    cout << c << endl;
    system("pause");

}