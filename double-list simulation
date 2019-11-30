//双向链表
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class List;

class ListNode
{
	friend class List;
public:
	ListNode(int data=0) : m_data(data), next(nullptr)
	{}
	ListNode(int data, ListNode *n)
		: m_data(data), next(n)
	{}
	~ListNode()
	{}
public:
	ListNode*& GetNext()
	{
		return next;
	}
private:
	int m_data;
	ListNode *next;
};

class List
{
public:
	List()
	{
		first = last = new ListNode;
		size = 0;
	}
	~List()
	{}
public:
	void push_back(int x)
	{
		ListNode *s = new ListNode(x);
		last->next = s;
		last = s;
		size++;
	}
	void push_front(int x)
	{
		ListNode *s = new ListNode(x);
		s->next = first->next;
		first->next = s;
		size++;
	}
private:
	ListNode *first;
	ListNode *last;
	size_t    size;
};

int main()
{
	List mylist;
	mylist.push_back(1);
	return 0;
}
