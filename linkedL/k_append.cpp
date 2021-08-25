#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	//consructor
	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void insertAtTail(node*&head,int d)
{
	if(head == NULL)
	{
		head = new node(d);
		return;
	}
	node*tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}	
	tail->next = new node(d);
}




// //take input
// void build_list(node*&head)
// {
// 	int n;
// 	cin>>n;
// 	int a = n;
// 	while(n>0)
// 	{
// 		int data;
// 		cin>>data;
// 		insertAtTail(head,data);
// 		n--;
// 	}
// }

//print the output
void print(node*head)
{
	if(head == NULL)
		return;
	cout<<head->data<<" ";
	print(head->next);
}


//append
node* odd_even(node*&head)
{
	node*oddHead = NULL;
	node*evenHead = NULL;

	while(head!= NULL)
	{
		if(((head->data)&1))
			insertAtTail(oddHead,head->data);
		else
			insertAtTail(evenHead,head->data);
		head = head->next;
	}
	if(oddHead == NULL)
	oddHead = evenHead;
	else
	{
		node*temp = oddHead;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = evenHead;
	}		
	return oddHead;
}

int main()
{
	node*head = NULL;

	int n;
	cin>>n;
	int data;
	while(n>0)
	{
		cin>>data;
		insertAtTail(head,data);
		n--;
	}
	// print(head);
	node*p = NULL;
	p = odd_even(head);
	print(p);
	cout<<endl;



	return 0;
}