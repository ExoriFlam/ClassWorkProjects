#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
	//Node* node;

	Node()
	{
		//Node* node = new Node;
		data = 0;
		this-> next = prev = nullptr;

	}

	Node(const int& data)
	{
		
		this -> data = data;
		this-> next = prev = nullptr;
		
	}



};


class ListTwo
{
	Node* head;
	Node* tail;
	int count;

public:
	ListTwo();
	void push_back(const int& add);
	void show(bool dir = false)const;

	~ListTwo();


};