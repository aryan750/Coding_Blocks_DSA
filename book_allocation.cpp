#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int n,int m,int curr_sum)
{
	int student_used = 1;
	int pages_reading =0;
	for(int i=0;i<n;i++)
	{
		if(pages_reading + arr[i] > curr_sum)
		{
			student_used++;
			pages_reading = arr[i];
			if(student_used > m)
				return false;
		}
		pages_reading += arr[i];

	}



	return true;
}



int findpages(int arr[],int n,int m)
{
	int sum=0;

	if(n<m)
		return -1;

	//count the no. of pages
	for(int i=0;i<n;i++)
	{
		sum +=arr[i];	
	}

	int s=arr[n-1];
	int e=sum;
	int ans = INT_MAX;

	while(s <= e)
	{
		int mid = (s+e)/2;

		if(isPossible(arr,n,m,mid))
		{
			ans = min(ans, mid);
			e=mid-1;
		}
		else
		{
			s=mid+1;
		}
	}
	return ans;
}



int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int n;
		int m;

		cin>>n>>m;
		int arr[1000];
		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}

		cout<<findpages(arr,n,m)<<endl;

	}





	return 0;
}