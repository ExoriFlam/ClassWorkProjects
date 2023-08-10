#include <iostream>
#include "StackD.h"
using namespace std;


int main()
{
    system("chcp 1251>nul");
    StackD a, c;
    
    cout << a << endl;
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    
    cout << a << endl;
    StackD b(a);
    cout << b << endl;
   
    c = b;
    cout << c;
    cout << endl;
    system("pause");
}
