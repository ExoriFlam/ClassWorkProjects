#include <iostream>
#include "List_1.h"
#include "List_one_T.h"
#include "ListTwo.h"
using namespace std;


int main()
{
    
    system("chcp 1251>nul");

    
    List_1 a;
    a.push_back('a');
    a.push_back('a');
    a.push_back('a');
    a.push_back('a');
    a.push_back('a');
    a.push_back('a');
    a.insert_data_before_index(0, 'z');
    cout << a;
    cin >> a;
    cout << a;




    system("pause");
}