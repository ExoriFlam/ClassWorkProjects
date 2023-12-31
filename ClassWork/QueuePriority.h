#pragma once

class QueuePriority
{
	int * w;				//Очередь
	int * p;				//Приоритет
	int MaxLength;			//Максимальный размер очереди
	int Length;				//Текущий размер очереди
public:
	QueuePriority(int m);		//Конструктор
	~QueuePriority();			//Деструктор
	void Add(int c, int pr);		//Добавление элемента
	bool Extract();			//Извлечение элемента
	void Clear();			//Очистка очереди
	bool IsEmpty()const;			//Проверка существования элементов в очереди
	bool IsFull()const;			//Проверка на переполнение очереди
	int GetCount()const;			//Количество элементов в очереди
	void Show()const;			//Отображение очереди
};
