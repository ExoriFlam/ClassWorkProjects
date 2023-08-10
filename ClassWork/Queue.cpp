
#include <iostream>

using namespace std;
#include "Queue.h"

//-----------------------------------------------------
Queue::Queue(int m)			          //Конструктор
{
	MaxLength = m;             //получаем размер
	w = new int[MaxLength];    //создаем очередь
	Length = 0;                //Изначально очередь пуста
}

//-----------------------------------------------------
Queue::~Queue()						  //Деструктор
{
	delete[]w;  //удаление очереди
}


//-----------------------------------------------------
void Queue::Show()const {
	if (!IsEmpty())
	{
		cout << "\n-----------------------------------\n";
		//демонстрация очереди
		for (int i = 0; i < Length; i++) {
			cout << w[i] << " ";
		}
		cout << "\n-----------------------------------\n";
	}
	else cout << "\nОчередь пуста\n";
}

//-----------------------------------------------------
void Queue::Clear()
{
	Length = 0;			//Эффективная "очистка" очереди
}
//-----------------------------------------------------
bool Queue::IsEmpty()const
{
	return Length == 0;
}

//-----------------------------------------------------
bool Queue::IsFull()const
{
	return Length == MaxLength;
}

//-----------------------------------------------------
int Queue::GetCount()	const		//Количество присутствующих в очереди элементов
{	
	return Length;
}

//-----------------------------------------------------
void Queue::Add(int c)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и добавляем новый элемент
	if (!IsFull())
		w[Length++] = c;
}
//-----------------------------------------------------
int Queue::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//который вошел первым и сдвигаем очередь
	if (!IsEmpty())
	{
		int temp = w[0];                 //запомнить первый
		for (int i = 1; i < Length; i++) //сдвинуть все элементы
			w[i - 1] = w[i];
		
		Length--;						 //уменьшить количество
		return temp;					 //вернуть первый(нулевой)
	}
	else return -1;						 //Если в очереди элементов нет
}