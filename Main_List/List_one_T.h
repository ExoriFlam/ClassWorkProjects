#pragma once
#include <iostream>
using namespace std;

template<class Type>
struct ElementType
{
	Type data;                  // данные
	ElementType<Type>* next;   // адрес следующего элемента

};

template<class Type>
class ListOneType
{
private:

	ElementType<Type>* head;
	int count;

public:

	ListOneType();
	ListOneType(const ListOneType& other);
	//ListOneType& operator=(const ListOneType& other);

	void push_back(const Type& data);
	void push_front(const Type& data);

	void pop_back();
	void pop_front();

	void insert_after_data(const Type& a, const Type& src);

	void clear();
	void show()const;


	int get_index_by_data(const Type& data);
	Type get_date_by_index(const int& index);

	int get_count()const { return count; }

	bool containe(const Type& data)const;

	template<class Type>
	friend ostream& operator <<(ostream& out, const ListOneType& obj);

	~ListOneType();
};

///////////////////////////////////////////////////////////////////////////////
template<class Type>
ListOneType<Type>::ListOneType()
{
	this->head = nullptr;
	count = 0;
}

template<class Type>
ListOneType<Type>::ListOneType(const ListOneType& other)
{
	this->head = nullptr;
	ElementType<Type>* current = other.head;
	while (current != nullptr)
	{
		this->push_back(current->data);
		current = current->next;
	}

}
//template<class Type>
//ListOneType<Type>& ListOneType<Type>::operator=(const ListOneType<Type>& other)
//{
//	if (this == &other) return *this;
//	if (count != other.count)
//	{
//		this->clear();
//
//		ElementType<Type>* current = other.head;
//
//		while (other.head)
//		{
//			this->push_back(current->data);
//			current = current->next;
//		}
//	}
//
//
//
//	return *this;
//}


template<class Type>
void ListOneType<Type>::push_back(const Type& data)
{
	ElementType<Type>* add = new ElementType<Type>;
	add->data = data;
	add->next = nullptr;

	ElementType<Type>* current = head;
	if (head)
	{

		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = add;
	}
	else
	{
		head = add;
	}
	count++;
}

template<class Type>
void ListOneType<Type>::push_front(const Type& data)
{
	//ElementType<Type>* temp = this->head;

	ElementType<Type>* add = new ElementType<Type>;
	add->data = data;
	add->next = nullptr;

	if (this->head)
	{
		add->next = this->head;
		this->head = add;

	}
	else
	{
		this->head = add;

	}
	count++;
}

template<class Type>
void ListOneType<Type>::pop_back()
{
	if (head)
	{
		if (head->next != nullptr)
		{
			ElementType<Type>* current = head;

			while (current->next && current->next->next)
			{
				current = current->next;
			}

			delete current->next;
			current->next = nullptr;

		}
		else
		{
			delete head;
			head = nullptr;
		}

		count--;

	}



}
template<class Type>
void ListOneType<Type>::pop_front()
{
	if (this->head)
	{
		ElementType<Type>* temp = head;
		head = head->next;
		delete temp;
		count--;
	}
}
template<class Type>
void ListOneType<Type>::insert_after_data(const Type& after, const Type& src)
{
	if (this->containe(after))
	{
		ElementType<Type>* current = head;

		while (current->data != after)
		{
			current = current->next;
		}

		ElementType<Type>* add = new ElementType<Type>;
		add->data = src;
		add->next = nullptr;

		add->next = current->next;
		current->next = add;
	}


}

template<class Type>
void ListOneType<Type>::clear()
{
	if (head)
	{
		ElementType<Type>* current = head;
		ElementType<Type>* prev = head;

		while (current)
		{
			current = current->next;
			delete prev;
			prev = current;

		}
		count = 0;
		head = nullptr;

	}

}
template<class Type>
void ListOneType<Type>::show() const
{
	if (this->head == nullptr)
	{
		cout << "\nСписок пуст";
		return;
	}
	ElementType<Type>* current = this->head;

	/*for (int i = 0; i < count; i++)
	{

		cout << current->data << " ";
		current = current->next;
	}*/
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;

}
template<class Type>
int ListOneType<Type>::get_index_by_data(const Type& data)
{
	int index = 0;
	bool found = false;

	ElementType<Type>* current = head;

	while (current)
	{

		if (current->data == data)
		{
			found = true;
			break;
		}

		index++;
		current = current->next;
	}

	if (!found) index = -1; // если данных нет то вернем -1

	return index;
}
template<class Type>
Type ListOneType<Type>::get_date_by_index(const int& index)
{
	int cnt = 0;

	if (head)
	{
		ElementType<Type>* current = head;

		while (current)
		{
			if (cnt == index) return current->data;
			cnt++;
			current = current->next;

		}
	}
	return '\0';

}
template<class Type>
bool ListOneType<Type>::containe(const Type& data) const
{
	if (!this->head)
		return false;
	ElementType<Type>* current = this->head;

	while (current != nullptr)
	{

		if (current->data == data)
		{
			return true;

		}

		current = current->next;

	}


	return false;
}
template<class Type>
ListOneType<Type>::~ListOneType()
{
	ElementType<Type>* current = this->head;
	ElementType<Type>* prev_current = this->head;

	while (current != nullptr)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = nullptr;
}
template<class Type>
ostream& operator<<(ostream& out, const ListOneType<Type>& obj)
{


	if (obj.head)
	{
		ElementType<Type>* current = obj.head;

		while (current)
		{
			out << current->data << " ";
			current = current->next;
		}
	}
	else
	{
		out << "\nСписок пуст.";
	}


	return out;
}
