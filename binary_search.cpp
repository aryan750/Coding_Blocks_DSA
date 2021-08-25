#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int key)
{
	int s=0;
	int e=n-1;
	
	while(s<=e)
	{
		int mid = (s+e)/2;
		if( key > arr[mid] )
			s = mid + 1;
		else if(key < arr[mid])
			e =mid -1;
		else
		{
			return mid;
		}
	}
	return -1;
	
}



int main()
{
	int n;
	cin>>n;	
	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int m;
	cin>>m;

	cout<<binary_search(arr,n,m)<<endl;




	return 0;
}