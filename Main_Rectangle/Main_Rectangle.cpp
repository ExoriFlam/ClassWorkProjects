#include <iostream>
#include "Rectangle.h"
using namespace std;
int main()
{
    system("chcp 1251>nul");
    Rectangle a,b("green","rec_one"),c;
    cout << a;
    a = b;
    cout << a;
    cin >> c;
    cout << c;
    Rectangle d(c);
    cout << d;
    d = b;
    cout << d;

    system("pause");
}