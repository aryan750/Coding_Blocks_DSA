#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void insertAtBottom(int x){
	if(s.size() == 0){
		s.push(x);
	}
	else{
		int h = s.top();
		s.pop();
		insertAtBottom(x);
		s.push(h);
	}
	
}


void reverse()
{
	if(s.size() > 0){
		int n = s.top();
		s.pop();
		reverse();
		insertAtBottom(n);
	}

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.push(a[i]);
	}

	reverse();

	for(int i =0;i<n;i++)
	{
		int l = s.top();
		cout<<l<<endl;
		s.pop();
	}


	return 0;
}