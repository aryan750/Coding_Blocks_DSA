#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int m,int curr_sum)
{
	int stud_used =1;
	int pages_reading = 0;

	for(int i=0;i<n;i++)
	{
		if(a[i] + pages_reading > curr_sum)
		{
			stud_used++;
			pages_reading = a[i];
			if(stud_used > m)
			{
				return false;
			}
		}
		pages_reading += a[i];
	}
	return true;
}

int book_allocation(int a[], int n, int m)
{
	int sum=0;
	if(n<m)
		return -1;

	for(int i=0;i<n;i++)
	{
		sum += a[i];
	}
	int s=a[n-1];
	int e=sum;
	int ans=INT_MAX;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(isPossible(a,n,m,mid))
		{
			ans=min(mid,ans);
			e=mid-1;
		}
		else
			s=mid+1;
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		int n;
		int m;
		cin>>n;
		cin>>m;
		int a[1000];

		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		//solution starts
		cout<<book_allocation(a,n,m)<<endl;
		t--;
	}



	return 0;
}