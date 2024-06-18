#pragma once
#include"ListNode.h"
template<class T>
class List
{
public:
	List()
	{
		head = new ListNode<T>();
		tail = new ListNode<T>();
		connect(head, tail);
	}
	ListNode<T> *head;
	ListNode<T> *tail;

	void connect(ListNode<T> *last, ListNode<T> *next)
	{
		last->next = next;
		next->last = last;
	}
	void push_back(T data)
	{
		ListNode<T> *temp= new ListNode<T>(data);
		connect(tail->last, temp);
		connect(temp, tail);
	}
	void push_front(T data)
	{
		ListNode<T> *temp= new ListNode<T>(data);
		connect(temp,head->next);
		connect(head,temp);	
	}
	void insert_back(ListNode<T> * pos, T data)
	{
		ListNode<T> *temp = new ListNode<T>(data);
		connect(temp, pos->next);
		connect(pos,temp);
	}
	void insert_front(ListNode<T> * pos,T data)
	{
		ListNode<T> *temp= new ListNode<T>(data);
		connect(pos->last,temp);
		connect(temp, pos);
	}
	void print()
	{
		ListNode<T> * temp = head->next;
		while (temp != tail)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << "\n";
	}
};

