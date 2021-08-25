#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x){

	//base case
	if(s.empty()){
		s.push(x);
		return;
	}


	//rec case
	int data = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(data);
}



void reverseStack(stack<int> &s){
	
	//base case
	if(s.empty())
	{
		return;
	}

	//rec case
	//otherwise pop the element and insert it at the bottom of the reversed stack
	int x = s.top();
	s.pop();

	reverseStack(s);
	insertAtBottom(s,x);
}



int main(){

	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	reverseStack(s);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}



	return 0;
}