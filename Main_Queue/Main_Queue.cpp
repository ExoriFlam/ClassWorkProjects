#include <iostream>
#include "Queue.h"
#include "QueueTemplate.h"
using namespace std;



int main()
{
    system("chcp 1251>nul");
    QueueTemplate<int> a;
    cout << a;
    a.Add(10);
    a.Add(11);
    a.Add(12);
    cout << a;
    a.Extract();
   
    cout << a;
    system("pause");
}

