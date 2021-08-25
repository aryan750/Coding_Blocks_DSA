#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*next;

	node(int d){
		data = d;
		next = NULL;
	}
};	


void insertAtTail(node*&head, int d){
	if(head == NULL){
		head = new node(d);
		return ;
	}
	node*tail = head;
	while(!tail != NULL){
		tail = tail->next;
	}
	tail = new node(d);
}

void buildlist(node*&head){
	int n; 
	cin>>n;
	while(n>0){
		int data;
		cin>>data;
		insertAtTail(head,data);
	}

void print(node*head){
	if(head == NULL)
		return;
	cout<<head->data;
	print(head->next);
}

node*findSum(node*head){

	node*me = head;
	node*c = head;
	node*p = NULL;
	node*n;
	while( c != NULL){

		n = c->next;
		c->next = p;
		p = c;
		c = n;
	}
	head = p;

	node*temp = head;

	node





}

int main()
{







}