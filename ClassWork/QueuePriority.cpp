
#include <iostream>

using namespace std;

#include "QueuePriority.h"



//------------------------------------------------------
QueuePriority::QueuePriority(int m)
{
	MaxLength = m;            //получаем размер
	w = new int[MaxLength];   //создаем очередь
	p = new int[MaxLength];
	Length = 0;			//Изначально очередь пуста
}

//------------------------------------------------------
QueuePriority::~QueuePriority()
{
	delete[]w;			//удаление очереди
	delete[]p;
}


//------------------------------------------------------
void QueuePriority::Show()const {
	if (!IsEmpty())
	{
		cout << "\n-----------------------------------\n";
		//демонстрация очереди
		for (int i = 0; i < Length; i++)
		{
			cout << w[i] << " - " << p[i] << "\n\n";
		}
		cout << "\n-----------------------------------\n";
	}
	else cout << "\nОчередь пуста\n";
}

//------------------------------------------------------
void QueuePriority::Clear()
{
	Length = 0;	//Эффективная "очистка" очереди
}





//------------------------------------------------------
bool QueuePriority::IsEmpty()const
{
	return Length == 0;
}

//------------------------------------------------------
bool QueuePriority::IsFull()const
{
	return Length == MaxLength;
}

//------------------------------------------------------
int QueuePriority::GetCount()const
{
	//Количество присутствующих в очереди элементов
	return Length;
}

//------------------------------------------------------


void QueuePriority::Add(int c, int pr)
{
	//Если в очереди есть свободное место,
	//то увеличиваем количество
	//значений и вставляем новый элемент
	if (!IsFull()) {
		w[Length] = c;
		p[Length] = pr;
		Length++;
	}
}

//------------------------------------------------------
bool QueuePriority::Extract()
{
	//Если в очереди есть элементы, то возвращаем тот,
	//у которого наивысший приоритет и сдвигаем очередь
	if (!IsEmpty()) {
		
		int max_pri = p[0];			//пусть приоритетный элемент - нулевой
		int pos_max_pri = 0;		//а приоритетный индекс = 0
		
		for (int i = 1; i < Length; i++) //ищем приоритет
			//если встречен более приоритетный элемент
			if (max_pri < p[i]) {
				max_pri = p[i];
				pos_max_pri = i;
			}
		//вытаскиваем приоритетный элемент
		int temp1 = w[pos_max_pri];
		int temp2 = p[pos_max_pri];
		//сдвинуть все элементы
		for (int i = pos_max_pri; i < Length - 1; i++) {
			w[i] = w[i + 1];
			p[i] = p[i + 1];
		}
		Length--;				//уменьшаем количество
		return temp1;			//возврат извлеченного элемента
	}
	else return -1;
}