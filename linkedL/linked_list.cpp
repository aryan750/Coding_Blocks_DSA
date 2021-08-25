#include<iostream>
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

//passsing the value of head by reference, 
//otherise the if passed by value , 
//there willl be no change in main() funciton
void insertAtHeat(node*&head, int d)	
{
	if(head == NULL)
	{
		head = new node(d);
		return ;
	}
	node *n= new node(d);
	n->next = head;
	head = n;
}



void print(node *head)
{

	while(head != NULL)
	{
		cout<<head->data<<" ->";
		head = head->next;
	}
	cout<<endl;
}

int length(node * head)
{
	int count =0;
	while(head!= NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}


void insertAtTail(node*&head, int data)
{
	if(head == NULL)
	{
		head = new node(data);
		return;
	}
	node*tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = new node(data);
	return ;
}


void insertInMiddle(node*&head, int data, int p)
{
	//corner case
	if(head == NULL || p==0)
	{
		insertAtHeat(head, data);
		return ;
	}
	else if(p>=length(head))
	{
		insertAtTail(head,data);
	}
	else
	{
		//take p-1 jumps
		int jump = 0;
		node*temp = head;
		while(jump<=p-1)
		{
			temp = temp->next;
			jump++;
		}

		//create a new node
		node*n = new node(data);
		n-> next = temp-> next;
		temp->next = n;
	}
}


//delete head
void deleteHead(node*&head)
{
	if(head == NULL)
	{
		return ;
	}
	node*temp = head->next;
	delete head;
	head = temp;
}

void deleteinMiddle(node*head)
{
	if(head == NULL)
		return ;
	if(head->next == NULL)
	{
		delete head;
		return ;
	}
	struct node*slow_ptr;
	struct node*fast_ptr;

	struct node*prev;

	while(fast_ptr!= NULL && fast_ptr->next == NULL)
	{
		fast_ptr = fast_ptr->next->next;
		prev = slow_ptr;
		slow_ptr= slow_ptr->next;
	}
	prev->next = slow_ptr->next;
	delete slow_ptr;
	return;
}

bool search(node*head, int key)
{	
	if(head == NULL)
	{
		return false;
	}

	node*temp = head;
	while(temp != NULL)
	{
		if(head->data ==  key)
		{
			return true;
		}
		head = head->next;
	}
	return false;
}


bool searchRec(node*head, int key)
{
	if(head == NULL)
	{
		return false;
	}
	//rec case
	if(head->data == key)
		return true;
	else
		return searchRec(head->next, key);
}

node* take_input()
{
	int d;
	cin>>d;
	node*head = NULL;

	while(d != -1)
	{
		insertAtHeat(head, d);
		cin>>d;
	}
	return head;
}
//overloading operator
//implementing cout<<head prints value not address
//as cout is of ostream header file so we pass it as a 
//parameter
ostream& operator<<(ostream &os, node*head)
{
	print(head);
	return os; 
}

//for cin
istream& operator>>(istream &is, node*&head)
{
	head = take_input();
	return is ;
}

//time : O(n)
//space : O(1)
void reverse(node*&head)
{
	node* c = head;
	node* p = NULL;
	node*n;

	while(c!=NULL)
	{
		//save the next node
		n = c->next;
		//make the current node point to prev 
		c->next = p;

		//update  p and c take them 1 step forward
		p = c;
		c = n;
	}
	head = p;

}

//time : O(n)
//space : O(n) stack space 
node* recReverse(node*head)
{
	//smallest linked list
	if(head->next == NULL || head == NULL)
		return head;

	//rec case
	node*shead = recReverse(head->next);

	// node*temp = shead;
	// while(shead->next != NULL)
	// {
	// 	temp = temp->next;
	// }
	// head->next = NULL;
	// temp->next = head;


	//better than before
	head->next->next = head;
	head->next = NULL;


	return shead;
}



//calcilate the mid point of linked list
node* midpoint(node*head)
{
	if(head == NULL || head->next == NULL)
		return head;

	node*slow = head;
	node*fast = head->next;

	while(fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}



//calculate the kth node from the end od linkedlist
node* kth(node*head, int k)
{
	if(head == NULL || head->next == NULL)
		return head;

	node*fast = head;
	node*slow = head;

	int len = length(head);
	int p= len-k;
	while(p > 0)
	{
		fast = fast->next;
		p--;
	}

	while(fast != NULL && fast->next != NULL)
	{
		fast= fast->next;
		slow= slow->next;
	}
	return slow;
}

//merge two sorted list into one
//using recursion
node* merge(node*a, node*b)
{
	//base case
	if(a==NULL)
		return b;

	if(b == NULL)
		return a;

	//take a head pointer for c
	node*c;

	if(a->data < b->data)
	{
		c =a ;
		c->next = merge(a->next, b);
	}
	else
	{
		c=b;
		c->next = merge(a, b->next);
	}
	return c;

}

//sort an unsorted linked list
//using merge sort
//space : O(N)
//time: O(NlogN)
node*merge_sort(head)
{
	//base case
	if(head == NULL || head->next == NULL)
		return head;

	// rec case
	//1. break
	node*mid = midpoint(head);
	node*a = head;
	node*b = mid->next;

	mid->next = NULL;

	//2.rec sort the two parts
	a = merge_sort(a);
	b = merge_sort(b);

	//3. merge them
	node*c = merge(a,b);
	return c;
}

//cycle detection
bool detectCycle(node*head)
{

	if(head->next == NULL || head == NULL)
		return head;

	node*slow;
	node*fast;

	while(fast != NULL && fast->next == NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
		{
			return true;
		}
	}
	return false;
}

node*removeCycle(node*head)
{
	
	if(head->next == NULL || head == NULL)
		return head;

	node*slow;
	node*fast;
	while(fast != NULL && fast->next == NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
		{
			fast = slow;
			slow = head;
			break;
		}
	}
	while(fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	node*prev = slow;
	while(prev->next != slow && slow->next != slow)
	{
		prev = prev->next;
	}
	prev->next = NULL;
	return head;

}






int main()
{
	node*head ;
	node*head2;
	
	cin>>head>>head2;
	cout<<head<<head2;

	node* newhead = merge(head, head2);
	cout<<newhead<<endl;
	




	// node*head ;
	// node*head2;
	// // cout<<head;//print entire linked list
	// //print(head);
	// cin>>head>>head2;
	// cout<<head<<head2;


	// node *head = NULL;
	// insertAtHeat(head,5);
	// insertAtHeat(head, 9);
	// insertAtHeat(head,1);
	// insertAtHeat(head,0);
	// insertInMiddle(head, 4,3);
	// insertAtTail(head,7);
	// print(head); 
	// node*head = take_input();
	//  print(head);

	// deleteHead(head);
	// print(head);
	// // deleteinMiddle(head);
	// // print(head);
	// int key;
	// cin>>key;
	// if(searchRec(head, key))
	// {
	// 	cout<<"Element found"<<endl;
	// }
	// else
	// 	cout<<"Element not found"<<endl;
	return 0;
}