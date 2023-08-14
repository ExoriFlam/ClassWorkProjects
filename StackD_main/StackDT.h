#pragma once
#include <iostream>
using namespace std;


template<class Type, int sz = 10>
class StackDT
{
private:
	
	
	int size;
	Type* items;
	int top;

public:
	StackDT();
	StackDT(const StackDT& other);
	StackDT(StackDT&& other)noexcept;
	StackDT& operator=(const StackDT& other);
	friend ostream& operator<<(ostream& out, StackDT& obj);
	StackDT& operator=(StackDT&& other)noexcept;

	bool is_empty() const { return top == 0; }
	bool is_full() const { return top == size; }
	bool push(const Type& item);
	bool pop(Type& item);
	
	~StackDT() { delete[] items; }
};







//int StackDT::count = 0; // инициализация статической переменной класса
template<class Type, int sz>
StackDT<Type, sz>::StackDT() :
	size{ sz }
{
	items = new Type[this->size];
	
}
template<class Type, int sz>
StackDT<Type, sz>::StackDT(const StackDT& other) :
	size{ other.size }
{
	items = new Type[this->size] {};
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
	
}
template<class Type, int sz>
StackDT<Type, sz>::StackDT(StackDT&& other)noexcept :
	size{ other.size }
{
	items = other.items;
	other.items = nullptr;

	other.size = 0;

}
template<class Type, int sz>
StackDT<Type, sz>& StackDT<Type, sz>::operator=(const StackDT<Type, sz>& other)
{
	if (this == &other) return *this;

	if (this->size != other.size)
	{
		delete[]items;
		items = new Type[other.size] {0};

	}

	this->size = other.size;
	

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
template<class Type, int sz>
StackDT<Type, sz>& StackDT<Type, sz>::operator=(StackDT<Type, sz>&& other)noexcept
{
	if (this == &other) return *this;

	delete[]items;
	items = other.items;
	size = other.size;
	
	other.size = 0;
	other.items = nullptr;

	return *this;
}

template<class Type, int sz>
bool StackDT<Type, sz>::push(const Type& item)
{
	if (top < size)
	{
		items[top++] = item;
		return 1;
	}
	return 0;
}
template<class Type, int sz>
bool StackDT<Type, sz>::pop(Type& item)
{
	if (top > 0)
	{
		item = items[--top];
		return 1;
	}
	return 0;
}
template<class Type, int sz>
ostream& operator<<(ostream& out, StackDT<Type, sz>& obj)
{
	if (obj.top == 0)
	{
		out << "\nstack is empty\n";
		return out;
	}
	int i;
	for (i = 0; i < obj.top - 1; i++)
	{
		out << obj.items[i] << ", ";
	}

	out << obj.items[i] << "!";

	out << endl;

	return out;
}
