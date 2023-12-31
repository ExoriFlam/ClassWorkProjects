#pragma once

class QueueRing
{
	int * w;				//Очередь
	int MaxLength;			//Максимальный размер очереди
	int Length;			//Текущий размер очереди
public:
	QueueRing(int m);		//Конструктор
	~QueueRing();			//Деструктор
	void Add(int c);		//Добавление элемента
	bool Extract();			//Извлечение элемента
	void Clear();			//Очистка очереди
	bool IsEmpty()const;			//Проверка существования элементов в очереди
	bool IsFull()const;			//Проверка на переполнение очереди
	int GetCount()const;			//Количество элементов в очереди
	void Show()const;			//Отображение очереди
};
