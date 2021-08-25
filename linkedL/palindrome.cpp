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

void insertAtTail(node*&head,int data)
{
	while(head == NULL)
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


//input
void buildlist(node*&head)
{
	int n;
	cin>>n;
	int data;
	while(n>0)
	{
		cin>>data;
		insertAtTail(head, data);
		n--;
	}
}

node* midpoint(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;

    }
    node*slow=head;

    //Modification
    // node*fast =head->next;
    node*fast =head;
    
    while(fast!= NULL && fast->next!= NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


node*reverse(node*&head)
{
	node*c = head;
	node*p = NULL;
	node*n ;
	while(c != NULL)
	{
		n = c->next;
		c->next = p;
		p = c;
		c= n;
	}
	head = p;
	return head;
}


bool isPalindrome(node*head, node*temp)
{
	bool flag = 1;
	while(temp!=NULL)
    {   
        //compare 
        if(head->data==temp->data)
        {
            head=head->next;
            temp=temp->next;
        }
        else
        {
            flag=0;
            break;
        }
    }
    return flag;
}


int main()
{
	node*head = NULL;
	buildlist(head);
	
	node*temp = midpoint(head);

	node*rev = reverse(temp);

	if(isPalindrome(head, rev))
		cout<<"True"<<endl;
	else
		cout<<"False"<<endl;


	return 0;
}