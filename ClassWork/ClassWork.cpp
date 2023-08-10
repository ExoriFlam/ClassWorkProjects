#include <iostream>
#include "Coord.h"
#include "Rectangle.h"
#include "Car.h"
#include "Track.h"
#include <stdarg.h>
#include "Stack.h"
#include "StackD.h"
using namespace std;

template <typename T>
T any_type(int count, ...)
{
    T sum{};

    va_list arg_ptr;

    va_start(arg_ptr, count);

    while (count--)
    {

        sum = sum + va_arg(arg_ptr, T);

    }

    va_end(arg_ptr);


    return sum;
}

template<typename T>
T summa(int k, ...)
{
    int* ptr = &k;
    ptr++;

    T* ptr_T = reinterpret_cast<T*>(ptr);//
    T sum{};
  
    while (k != 0 )
    {

        sum += *(ptr_T++);
        k--;
    }

    return sum;
}

char summ(int k, ...)
{
    va_list args;
    va_start(args, k);

    char sum = 0;
    for (int i = 0; i < k; i++)
    {
        int arg = va_arg(args, int);
        char* ptr_T = reinterpret_cast<char*>(&arg);
        sum += *ptr_T;
    }

    va_end(args);

    return sum;
}

double AnyType(int count, bool typeof, ...);
int main()
{
    system("chcp 1251>nul");
    //char* ptr;

    cout << summa<double>(5, 2.2, 2.3, 2.4, 2.5, 2.6);

    //cout << "\n sizeof char* = " << sizeof(ptr); // = 4 байта
                                                                          //   \/                  \/                  \/                  \/  
    //cout << "\n 16 symbols '1' Ascci 49 " << summa<char>(2, '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1');
   // cout << "\n 16 symbols '1' Ascci 49 " << (int)summ(2, '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1');
    /*char str1[3] = "11";
    char sum = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        sum += str1[i];
    }
    cout << "\n\n\n\n" << sum << "\n\n\n\n";*/

   /* Stack st;

    st.Show();

    st.Push('+');
    st.Push('@');
    st.Push('a');
    st.Push('#');
    st.Show();*/
    
    system("pause");

}






double AnyType(int count, bool typeof, ...)

{

    int sumi = 0;     //сумма для целочисленных параметров

    double sumd = 0.0;//сумма для вещественных параметров



    // Переменная типа va_list (переопределённый char*) 

    // хранит указатель на список параметров  функции.


    va_list arg_ptr;    //Создаём указатель на список параметров

    //получаем этот указатель, отталкиваясь от первого фактического параметра



    va_start(arg_ptr, count);



    //пропускаем второй фактический параметр

    va_arg(arg_ptr, bool);



    //count раз считываем последующие параметры

    while (count--) {

        //если typeof - true, то считываем параметры типа int

        //если typeof - false, то считываем параметры типа double

        (typeof) ? sumi += va_arg(arg_ptr, int) :

            sumd += va_arg(arg_ptr, double);

    }

    va_end(arg_ptr);//закрываем список параметров



    //если typeof - true, то показываем сумму типа int

    //если typeof - false, то показываем сумму типа double


    return (typeof ? sumi : sumd);

}



/*

1.-------------------------------------------

void va_start( va_list arg_ptr, prev_param );



Первый параметр — созданная заранее переменная

типа va_list, в неё запишется указатель на список параметров,

созданный данной функцией.



Второй параметр нашей функции, что бы va_list могла

от чего-то оттолкнуться при связывании arg_ptr и

списка.



2.-------------------------------------------

Анализируем параметры с помощью многократного

вызова функции:

type va_arg( va_list arg_ptr, type );



Данная функция получает параметр из списка,

указатель на который передан в неё в качестве первого

параметра, и переставляет этот указатель на следующий элемент.





3.-------------------------------------------

Заканчиваем анализ параметров и очищаем внутренний указатель,

устанавливая его в нуль с помощью

функции:

void va_end( va_list arg_ptr );

*/
