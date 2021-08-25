#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	//construcutor
	node(int d)
	{
		data = d;
		next = NULL;
	}
};


void insertAtTail(node*&head, int d)
{
	if(head == NULL)
	{
		head = new node(d);
		return ;
	}

	node*tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new node(d);
}


int build_list(node*&head)
{
	int n;
	int k;
	cin>>n;
	cin>>k;
	while(n>0)
	{
		int data;
		cin>>data;
		insertAtTail(head,data);
		n--;
	}
	return k;
}

node* reverse(node*&head, int k)
{
	int x = k;
	node *c = head;
	node *p = NULL;
	node *n;

	while(c!= NULL && x>0)
	{
		n = c->next;
		c->next = p;
		p = c;
		c = n;
		x--;
	}
	if(n !=NULL)
		head->next = reverse(n, k);

	return p;
	
}



void print(node*head)
{
	if(head ==NULL)
		return ;
	cout<<head->data<<" ";
	print(head->next);
}



int main()
{
	node*head = NULL;
	int k = build_list(head);
	head = reverse(head,k);
	print(head);
	cout<<endl;

	return 0;
}