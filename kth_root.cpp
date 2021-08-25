#include<bits/stdc++.h>
using namespace std;

long long int kroot(long long int n,long long int k)
{
	long long int ans=1;

	long long int s=0;
	long long int e=n;

	while(s<=e)
	{
		long long int mid = (s+e)/2;
		if(pow(mid,k) == n)
		{
			ans = mid;
			break;
		}
		else if(pow(mid, k) < n)
		{
			ans = mid;
			s = mid+1;
		}
		else
			e = mid-1;
	}



	return ans;
}



int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		long long int n;
		cin>>n;
		long long int k;
		cin>>k;
		cout<<kroot(n,k)<<endl;
		t--;
	}



	return 0;
}