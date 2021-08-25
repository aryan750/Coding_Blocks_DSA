#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	//constructor
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void print(node*head)
{
	if(head == NULL)
		return ;
	cout<<head->data<<" ";
	print(head->next);
}


void insertAtTail(node*&head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
		return ;
	}
	node*temp = head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new node(data);
}



int build_list(node*&head)
{
	int data;
	cin>>data;
	while(data != -1)
	{
		insertAtTail(head, data);
		cin>>data;
	}
	int k;
	cin>>k;
	return k;
}




node* last(node*head,int k)
{	
	if(head == NULL || head->next == NULL)
		return head;

	node*slow = head;
	node*fast = head;
	while(k>0)
	{
		fast = fast->next;
		k--;
	}

	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


int main()
{	
	node*head = NULL;
	int k = build_list(head);
	node*temp = last(head, k);
	cout<<temp->data;
	cout<<endl;
	return 0;
}