#pragma once
#include <iostream>
using namespace std;


template<class Type>
class StackDTemplate
{
private:
	static const int MAX{ 10 };
	static int count;
	int size;
	Type* items;
	int top;

public:
	StackDTemplate(int s = MAX);
	StackDTemplate(const StackDTemplate& other);
	StackDTemplate(StackDTemplate&& other)noexcept;
	StackDTemplate& operator=(const StackDTemplate& other);
	friend ostream& operator<<<Type>(ostream& out, StackDTemplate& obj);
	
	
	StackDTemplate& operator=(StackDTemplate&& other)noexcept;

	bool is_empty() const { return top == 0; }
	bool is_full() const { return top == size; }
	bool push(const Type& item);
	bool pop(Type& item);
	int get_сount() const { return top; }
	static int get_сount_all() { return count; }
	~StackDTemplate() { count--; delete[] items; }
};







template<class Type>
int StackDTemplate<Type>::count = 0; // инициализация статической переменной класса

template<class Type>
StackDTemplate<Type>::StackDTemplate(int size) :
	size{ size }, top{ 0 }
{
	items = new Type[this->size];
	count++;
}

template<class Type>
StackDTemplate<Type>::StackDTemplate(const StackDTemplate& other) :
	size{ other.size }, top{ other.top }
{
	items = new Type[this->size] {0};
	const Type* source = other.items;
	const Type* end = other.items + size;
	Type* dest = this->items;

	if (items)
	{
		while (source < end)
		{
			*(dest++) = *(source++);
		}
	}

	source = nullptr;
	end = nullptr;
	dest = nullptr;
	count++;
}

template<class Type>
StackDTemplate<Type>::StackDTemplate(StackDTemplate&& other)noexcept :
	size{ other.size }, top{ other.top }
{
	items = other.items;
	other.items = nullptr;

	other.size = other.top = 0;

}
template<class Type>
StackDTemplate<Type>& StackDTemplate<Type>::operator=(const StackDTemplate& other)
{
	if (this == &other) return *this;

	if (this->size != other.size)
	{
		delete[]items;
		items = new Type[other.size] {0};

	}

	this->size = other.size;
	this->top = other.top;

	const Type* source = other.items;
	const Type* end = other.items + size;
	Type* dest = this->items;

	if (items)
	{
		while (source < end)
		{
			*(dest++) = *(source++);
		}
	}

	source = nullptr;
	end = nullptr;
	dest = nullptr;

	return *this;
}

template<class Type>
StackDTemplate<Type>& StackDTemplate<Type>::operator=(StackDTemplate&& other)noexcept
{
	if (this == &other) return *this;

	delete[]items;
	items = other.items;
	size = other.size;
	top = other.top;
	other.size = other.top = 0;
	other.items = nullptr;

	return *this;
}

template<class Type>
bool StackDTemplate<Type>::push(const Type& item)
{
	if (top < size)
	{
		items[top++] = item;
		return 1;
	}
	return 0;
}

template<class Type>
bool StackDTemplate<Type>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return 1;
	}
	return 0;
}

template<class Type>
ostream& operator<<(ostream& out, StackDTemplate<Type>& obj)
{
	if (obj.top == 0)
	{
		out << "\nstack is empty\n";
		return out;
	}
	int i;
	for (i = 0; i < obj.top ; i++)
	{
		out << obj.items[i] << ", ";
	}

	

	out << endl;

	return out;
}
