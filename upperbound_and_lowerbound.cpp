#include<bits/stdc++.h>
using namespace std;

int lower(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	int ans =-1;

	while(s<=e)
	{
		int mid = (s+e)/2;

		if(key > arr[mid])
			s=mid+1;
		else if(key == arr[mid])
		{
			ans =mid;
			e = mid-1;
		}
		else
			e = mid -1;
	}
	return ans;
}

int upper(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	int ans =-1;

	while(s<=e)
	{
		int mid = (s+e)/2;

		if(key > arr[mid])
			s=mid+1;
		else if(key == arr[mid])
		{
			ans =mid;
			s= mid+1;
		}
		else
			e = mid -1;
	}
	return ans;
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

	int q;
	cin>>q;
	int b[q];

	for(int i=0;i<q;i++)
	{
		cin>>b[i];
	}

	for(int i=0;i<q;i++)
	{
		int key = b[i];
		cout<<lower(a,n,key)<<" ";
		cout<<upper(a,n,key)<<endl;
	}

	return 0;
}