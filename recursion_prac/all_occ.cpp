#include<bits/stdc++.h>
using namespace std;

void allOcc(int *a, int n, int key, int i)
{
	if(i == n)
		return ;
	if(a[i] == key)
	{
		cout<<i<<" ";
	}

	allOcc(a,n,key,i+1);
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

	allOcc(a,n,key,0);
	return 0;
}