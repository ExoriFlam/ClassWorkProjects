#include "ListTwo.h"
using namespace std;


ListTwo::ListTwo()
{
	this->head = this->tail = nullptr;
	count = 0;
}

void ListTwo::push_back(const int& add)
{
	Node* temp = new Node(add);

	if (head)
	{
		this->tail->next = temp;
		temp->prev = tail;
		this->tail = temp;
	}
	else
	{
		this->head = this->tail = temp;
	}
	count++;
}

void ListTwo::show(bool dir) const
{
	if (this->head == nullptr)
	{
		cout << "\nСписок пуст";
		return;
	}
	if (dir)
	{
		Node* current = this->head;


		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	else
	{
		Node* current = this->tail;


		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->prev;
		}
		cout << endl;
	}
	


}

ListTwo::~ListTwo()
{

	Node* current = this->head;
	Node* prev_current = this->head;

	while (current != nullptr)
	{
		current = current->next;
		delete prev_current;
		prev_current = current;
		count--;
	}
	this->head = tail = nullptr;
}
