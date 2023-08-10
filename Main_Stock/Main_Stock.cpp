#include <iostream>
#include "Stock.h"
using namespace std;

int main()
{
    system("chcp 1251>nul");
    Stock a;
    a.show();
    Stock b(a);
    b.show();
    b.set_platform("asdvb");
    b.show();
    system("pause");
}