#include<bits/stdc++.h>
using namespace std;

bool esearch(int a[][1000] , int n , int m, int key)
{
	int i=0;
	int j=m-1;

	while(1)
	{

		if(j < 0 || i >= n)
			return false;
		if(a[i][j] == key)
			return true;
		if(key > a[i][j])
			i++;
		else 
			j--;
	}
}

int main()
{	
	int n;
	int m;
	cin>>n>>m;
	int a[1000][1000];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	int key;
	cin>>key;

	bool y=esearch(a,n,m,key);
	cout<<y<<endl;
	return 0;
}