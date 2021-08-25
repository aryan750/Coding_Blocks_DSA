#include<bits/stdc++.h>
using namespace std;

int pivot( int a[], int n)
{
	int s=0;
	int e=n-1;

	while(s<=e)
	{
		int mid=(s+e/2);
		if(a[mid] > a[mid+1] && mid<e)
		{
			return mid;
		}
		if(a[mid] < a[mid-1] && mid>s)
		{
			return mid-1;
		}
		if(a[s] >= a[mid])
		{
			e=mid-1;
		}
		else 
			s=mid+1;
	}
	return 0;
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

	cout<<pivot(a,n)<<endl;



	return 0;
}