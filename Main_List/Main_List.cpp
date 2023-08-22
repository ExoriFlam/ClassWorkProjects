#include <iostream>
#include "List_1.h"
#include "List_one_T.h"
#include "ListTwo.h"
using namespace std;


int main()
{
    
    system("chcp 1251>nul");

    List_1 a,b;
    a.push_back('a');
    a.push_back('b');
    a.push_back('c');
    a.push_back('d');
    a.push_back('e');
    a.push_back('f');
    a.push_back('g');
    a.push_back('h');
    b.push_back('a');
    b.push_back('c');
    b.push_back('e');
    b.push_back('g');
    b.push_back('k');
    b.push_back('l');
    b.push_back('m');
    //List_1 c = a * b;
    //cout << c;
    //a.set_elem_by_index(2);
    a.erase_by_index(2);
    cout << a;
   // List_1 a;
   // a.push_back('+');
   // a.push_back('-');
   // a.push_back('/');
   // a.show();
   // cout << endl;
   // if (a.containe('='))
   // {
   //     cout << "Yes";
   // }
   // else
   // {
   //     cout << "NO";
   // }
   // cout << endl;
   // a.push_front('a');
   // a.push_front('b');
   // a.push_front('c');
   // a.show();
   // a.pop_front();
   // a.show();
   // a.push_front('d');
   // a.show();
   // a.pop_back();
   // 
   // a.show();
   //// cout << a.get_index_by_data('z');
   //// a.clear();
   // 
   // a.show();
   // cout << a.get_date_by_index(12);
   // cout << a;
   // cout << endl;
   // List_1 b,c;
   // b.push_back('z');
   // b.push_back('z');
   // b.push_back('z');
   // b.push_back('z');
   // b.push_back('z');
   // 
   // b = a;
   // cout << (a == b);
   // cout << (a != b);
   // c = a + b;
   // cout << c;
   // c = -c;
   // cout << endl;
   // cout << c;
 /*   ListOneType<int> list;
    list.push_back(125);
    list.push_back(125);
    list.push_back(125);
    list.show();*/
    //cout << list;
  /*  ListTwo a;
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.show();*/




    system("pause");
}