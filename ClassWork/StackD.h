#pragma once

class StackD
{
private:
	static const int MAX = 10;
	static int count;
	int size;    // размер
	int * items; // адрес стека
	int top;     // индекс вершины стека
public:
	StackD(int s = MAX);				// конструктор
	bool isempty() const { return top == 0; }
	bool isfull() const  { return top == size; }
	bool push(const int & item);		// добавление элемента в стек
	bool pop(int & item);				// извлечение элемента из стека
	void show() const; 
	int getCount() const{ return top; } // текущее количество элементов стека
	static int getCountAll() {  return count; }
	~StackD() { count--; delete[] items; } // деструктор
};