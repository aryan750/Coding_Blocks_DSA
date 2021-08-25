#include<bits/stdc++.h>
using namespace std;

bool staircase_search(int a[][1000],int n,int key)
{
	int i=0;
	int j=n-1;
	
	while(1)
	{
		if(key == a[i][j])
			return true;
		if(i >= n || j<0 )
			return false;
		if(key > a[i][j])
			i++;
		else 
			j--;
	}
}



int main()
{
	int n;
	cout<<"No of elemenmts: ";
	cin>>n;
	int value=1;
	int key;
	cout<<"key: ";
	cin>>key;
	int a[1000][1000];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}		
	}
	cout<<staircase_search(a,n,key);

	return 0;
}