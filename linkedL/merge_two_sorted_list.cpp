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

void insertAtTail(node*&head, int d){

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


//input the all the values
void build_list(node*&head)
{
	int n;
	cin>>n;
	while(n>0)
	{	
		int data;
		cin>>data;
		insertAtTail(head, data);
		n--;
	}
}

// //calculating the midpoint of LL
// node* midpoint(node*head)
// {

// 	if(head == NULL)
// 		return 0;
// 	node*slow;
// 	node*fast;
// 	while(fast == NULL && fast->next == NULL)
// 	{
// 		fast = fast->next->next;
// 		slow = slow->next;
// 	}
// 	return slow;
// }

//printing the output
void print(node*head)
{
	if(head ==NULL)
		return ;
	cout<<head->data<<" ";
	print(head->next);
}

//merge two arrays 
//using merge sort
node* merger(node*a, node*b)
{
	if(a == NULL)
		return b;
	if(b == NULL)
		return a;
	node *c;

	if(a->data <= b->data)
	{
		c= a;
		c->next = merger(a->next, b);
	}
	else
	{
		c = b;
		c->next = merger(a, b->next);
	}
	return c;
}





int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		node*head = NULL;
		node*head2 = NULL;
		build_list(head);
		build_list(head2);
	
		node*newhead = merger(head,head2);
		print(newhead);
		cout<<endl;

		t--;
	}
	return 0;
}