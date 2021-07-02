#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};
int main()
{
	Node *head = NULL,*p = NULL,*q = NULL:
		int n;
		cin>>n;
		for(int i = 0;i<n;i++){
		int t;
		cin>>t;
		p = new Node;
		p->data = t;
		p->next = NUll;
		if(head == NULL){head = p;
		}
		else{q->next = p;
		}
		q = p;
	}

	Node  *t = head;
	while(t != NULL){
		cout<<t->data<<" ";
		t = t->next;
	}
	return 0 ;
}
