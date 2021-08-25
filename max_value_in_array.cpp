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

	//max value
	int max_value=INT_MIN;

	for(int i=0;i<n;i++)
	{
		max_value=max(max_value,a[i]);
	}	
	cout<<max_value<<endl;
	return 0;
}