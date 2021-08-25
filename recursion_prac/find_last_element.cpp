#include<bits/stdc++.h>
using namespace std;

int find_last_element(int a[], int n, int key)
{
	//base case
	if(n==0)
		return -1;

	//rec case
	int i = find_last_element(a+1,n-1,key);
	if(i == -1)
	{
		if(a[0] == key)
			return 0;
		else 
			return -1;
	}
	return i+1;	
}



int main()
{

	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int key;
	cin>>key;

	cout<<find_last_element(a, n, key)<<endl;

	return 0;
}