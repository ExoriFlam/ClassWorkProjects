#pragma once

class Stack
{
	enum { EMPTY = -1, FULL = 10 };     //Нижняя и верхняя границы стека
	char st[FULL + 1];					//Массив для хранения данных
	int top;							//Индекс  вершины стека
public:
	
	Stack();							//Конструктор
	void Push(char c);					//Добавление элемента
	char Pop();							//Извлечение элемента
	void Clear();						//Очистка стека
	bool IsEmpty()const;						//Проверка существования элементов в стеке
	bool IsFull()const;						//Проверка на переполнение стека
	int GetCount()const;						//Количество элементов в стеке
	void Show()const;						//Вывод  стека на экран
};