#pragma once
template<class T>
class ListNode
{
public:
	ListNode()
	{
		next = last = nullptr;
	}
	ListNode(T data)
	{
		this->data = data;
		next = last = nullptr;
	}

	ListNode *next;
	ListNode *last;
	T data;
};

