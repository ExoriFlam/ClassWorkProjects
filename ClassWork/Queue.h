#pragma once

class Queue
{
	int * w;               //Очередь 
	int MaxLength;         //Максимальный размер очереди
	int Length;            //Текущий размер очереди
public:
	Queue(int m = 10);          //Конструктор
	~Queue();                   //Деструктор
	void Add(int c);            //Добавление элемента
	int Extract();              //Извлечение элемента
	void Clear();               //Очистка очереди
	bool IsEmpty()const;             //Проверка существования элементов в очереди
	bool IsFull()const;              //Проверка на переполнение очереди
	int GetCount()const;             //Количество элементов в очереди
	void Show()const;                //Вывод очереди на экран
};
