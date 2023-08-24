#include <iostream>
#include "List_1.h"
#include "List_one_T.h"
//#include "ListTwo.h"
#include "ListTwoTemplate.h"
using namespace std;

//Задание 2. В уже существующий класс Двунаправленного списка(ListTwo) добавьте реализацию
//   следующих методов :
//  − добавление элемента в начало списка; +
//  − добавление элемента(значение передается вторым параметром) после элемента списка +
//    со значением первого параметра;
//  − удаление первого элемента списка; +
//  − удаление последнего элемента списка;+
//  − удаление всех элементов списка;+
//  − конструктор копирования;
//  − конструктор с перемещением;
//  − перегрузку оператора присваивания(= );
//  − перегрузку оператора присваивания(= ) с перемещением;
//  − перегрузку операторов << , >> ;
//  − перегрузку оператора + для двух списков(конкатенация);
//Продемонстрируйте работу добавленных методов на примерах.
int main()
{
    
    system("chcp 1251>nul");

    
   /* ListTwo a,b;*/
    //a.push_back(1);
    //a.push_back(2);
    //a.push_back(3);
    //a.push_back(4);
    //a.push_back(5);
    //a.push_back(6);    


  /*  a.push_front(1);
    a.push_front(2);
    a.push_front(3);
    a.push_front(4);
    a.push_front(5);*/

    /*b.push_front(1);
    b.push_front(2);
    b.push_front(3);
    b.push_front(4);
    b.push_front(5);*/
    
   // a.show(1);
   /* a.pop_front();
    a.pop_front();
    a.pop_front();
    a.show(1);
    a.pop_back();*/
    //a.show(1);
    /*a.insert_before_found_data(3,1);
    a.insert_after_found_data(3, 1);*/
    //a.clear();
   // cout << a;
   // cin >> a;
   // a = a + b;
   /* cout << a;
    a.erase_by_data(2);
    cout << a;
    a.erase_by_index(11);
    cout << a;*/
   // a.show();
   /* a.insert_after_index(1);
    a.insert_after_index(2);
    a.insert_after_index(3);*/
    ListTwoTemplate<double> a;

    a.push_back(1.2);
    a.push_back(2.2);
    a.pop_back();
    a.pop_back();
    a.push_front(1.2);
    a.push_front(2.2);
    cout << a;
    system("pause");
}