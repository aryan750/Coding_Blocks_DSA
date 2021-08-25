#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n][n];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}

	//reversing row
	for(int i=0;i<n;i++)
	{
		int start=0;
		int end=n-1;
		while(start<end)
		{
			swap(a[i][start],a[i][end]);
			start++;
			end--;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j <= i)
			{
				swap(a[i][j],a[j][i]);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;	
	// }

	return 0;
}