#include <iostream>
#include "Date.h"
using namespace std;

int main()
{
    system("chcp 1251>nul");
    
    
   /* cout << "\nТест класса Date\n";
    Date a("9, 3,1998");
    Date b("12, 3,1998");
    int days = (int)a;
    cout << "\n operator int() Дней начиная с 1 янавря 1 года до 9 апреля 1998: " << days;
    cout  << "\n operator- Разница в днях 9.03.1998 - 12.03.1998 : " << a - b;
    cout << "\n operator++  a++: "<<  a++;
    cout << "\n operator++  ++a: " << ++a;
    cout << "\n a = " << a;
    cout << "\n operator += (int) + 1000 дней :" << (a+=1000);
    cout << "\n operator a>b a<b a==b a!=b  " << (a > b)<<" " << (a < b) <<" "<< (a == b) <<" "<< (a != b);
    cout << "\n\n\n\n\n\n";
    Date c("1. 3. 2000");*/
    //++days++;
    //cout << ++a++;
   // cout << ++a;
    Date a("8,7,2023");
    Date b("18,5,1961");
    cout << a - b;
    cin >> a;

    system("pause");
}
