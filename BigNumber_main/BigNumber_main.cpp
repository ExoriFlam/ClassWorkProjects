#include <iostream>
#include "BigNumber.h"
#include <iomanip>
using namespace std;

int main()
{
    system("chcp 1251>nul");
    int mas[20]={ 9, 6, 0, 5, 0, 0, 1, 1, 9, 1, 5, 4 , 6, 8, 9, 5, 3, 2, 1, 5 };
    BigNumber n1("9851353217554646509989979"), n2(mas,20), n3, n4(52156);
    cout << setw(80) << "----------вывод объектов---------\n";
    cout << endl << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
    cout << setw(80) << "---------сложение---------------\n\n";
    n3 = n1 + n2;
    cout << n1 << endl;
    cout << setw(79) << "+" << endl;
    cout << n2 << endl;
    cout << setw(79) << "---------------------------------\n";
    cout << n3;
    
           
    
            
    cout << "\n\n\n";
    system("pause");
}

