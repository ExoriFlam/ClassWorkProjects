#include <iostream>
#include "StudentAgr.h"
#include "ListTwoTemplate.h"
#include <list>
using namespace std;


bool comp_by_average(StudentAgr& obj1, StudentAgr& obj2)
{
    return obj1.get_avg() < obj2.get_avg();
}


int main()
{
    system("chcp 1251>nul");

    ListTwoTemplate<MyString>sub1;
    sub1.push_back("python");
    sub1.push_back("C++");
    sub1.push_back("C");
    sub1.push_back("ASM");
   
    StudentAgr s2("Astafieva", "Tatiana", 20, "Step", MyArray(5, 6, 12), sub1);
    StudentAgr s3("Borisov", "Vasilii", 25, "UTM", MyArray(5, 7, 11), sub1);
    StudentAgr s4("Ciobanu", "Serghei", 30, "ASEM", MyArray(5, 8, 10), sub1);
#if 0  
 /*   ListTwoTemplate<StudentAgr> listofstud;

    listofstud.push_back(a);
    listofstud.push_back(b);
    listofstud.push_back(c);*/

   // cout << listofstud;
   /* list<StudentAgr> lst;

    lst.push_back(a);
    lst.push_back(b);
    lst.push_back(c);
  
    for (const StudentAgr& v : lst)
    {
        cout << v;
    }
    cout << "\n--------------------------------------------------------------";
    lst.sort(comp_by_average);

    for (const StudentAgr& v : lst)
    {
        cout << v;
    }*/
  
    




    FILE* f;

    errno_t err, err1;

    err = fopen_s(&f, "Student.txt", "w");

    if (!err)
    {
        s2.save_txt(f);
        fclose(f);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }

    err1 = fopen_s(&f, "Student.txt", "r");
    if (!err1)
    {
        printf("\nДанные из файла\n");
        while (!feof(f))      
        {
            char str[256] = "";//{'\0'};

            fgets(str, sizeof(str), f);
            printf("%s", str);
        }
        fclose(f);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }
#endif // 0
    MyArray arr1(8, 0, 5);
    MyArray arr2(8, 6, 10);
    MyArray arr3(8, 11, 6);
    ListTwoTemplate<MyArray> list1, list2;
    ListTwoTemplate<double> list3, list4;
    list3.push_back(2.5);
    list3.push_back(2.8);
    list3.push_back(3.16);
    list3.push_back(4.77);

    list1.push_back(arr1);
    list1.push_back(arr2);
    list1.push_back(arr3);


    //MyString a("Hello, World!");

    FILE* f;
    errno_t err;
    err = fopen_s(&f, "str3.dat", "wb");

    if (!err)
    {
        s2.save_to_bin_file(f);
        //list1.save_to_bin_file(f);
        //list3.save_to_bin_file(f);
        printf("Ok");
        fclose(f);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }

    StudentAgr tmp;
    cout << "\nОбъект для считывания" << tmp << endl;
    //cout << "\nОбъект для считывания" << list2 << endl;
    //cout << "\nОбъект для считывания" << list4 << endl;
    cout << "\n------------------------------------------------\n";
    FILE* f2;
    errno_t err2;
    err2 = fopen_s(&f2, "str3.dat", "rb");

    if (!err2)
    {
          tmp.read_from_bin_file(f2);
        //list2.read_from_bin_file(f2);
        //list4.read_from_bin_file(f2);
          cout << "\nОбъект из файла  " << tmp;
        //cout << list4;
       
        fclose(f2);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }
    


    system("pause");
}