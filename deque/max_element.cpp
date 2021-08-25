#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int k;
	cin>>k;

	//logic 
	deque<int> dq;
	vector<int> v;
	int i ;
	for(i=0;i<k;i++)
	{
		while( !dq.empty() && a[i] >= a[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}

	for(;i<n;i++)
	{
		v.push_back(a[dq.front()]);
		while(!dq.empty() && dq.front() <= i-k){
			dq.pop_front();
		}
		while(!dq.empty() && a[i] >= a[dq.back()]){
			dq.pop_back();
		}
		dq.push_back(i);
	}
	v.push_back(a[dq.front()]);

	for(auto it = v.begin(); it!= v.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}




