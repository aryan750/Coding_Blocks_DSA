//dequeue efficient 
//means always put the odest element on top 



#include<bits/stdc++.h>
using namespace std;

struct Queue{
	stack<int> s1, s2;

	void enQ(int x){

		while(!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		s2.push(x);

		while(!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}

	int deq()
	{
		if(s1.empty()){
			exit(0);
		}

		int x = s1.top();
		s1.pop();
		return x;
	}

};


int main()
{
	int n;
	cin>>n;

	Queue q;
	for(int i=0;i<n;i++)
	{
		q.enQ(i);
	}


	for(int i=0;i<n;i++)
	{
		int k = q.deq();
		cout<<k<<" ";
	}
	cout<<endl;

	return 0;
}