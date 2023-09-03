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
    sub1.push_back("C");
    sub1.push_back("C++");
    sub1.push_back("ASM");
   
    StudentAgr s2("A", "Tatiana", 20, "Step", MyArray(5, 6, 12), sub1);
    StudentAgr s3("B", "Vasilii", 25, "UTM", MyArray(5, 7, 11), sub1);
    StudentAgr s4("C", "Serghei", 30, "MFTI", MyArray(5, 8, 10), sub1);
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
    
    MyString a("Hello, World!");

    FILE* f;
    errno_t err;
    err = fopen_s(&f, "str3.dat", "wb");

    if (!err)
    {
        s2.save_to_bin_file(f);
        printf("Ok");
        fclose(f);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }

    StudentAgr tmp;
    cout << "\nОбъект для считывания" << tmp << endl;
    FILE* f2;
    errno_t err2;
    err2 = fopen_s(&f2, "str3.dat", "rb");

    if (!err2)
    {
        tmp.read_from_bin_file(f2);
        cout << "\nОбъект из файла  " << tmp;
       
        cout << endl << tmp;
        fclose(f2);
    }
    else
    {
        cout << "\nОшибка записи файла";
    }
   

    system("pause");
}