#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(ll a[], ll n, ll k, ll curr_sum)
{
	ll painter_used =1;
	ll board_painted =0;

	for(int i=0;i<n;i++)
	{
		if(a[i] > curr_sum)
			return false;
		
		if(a[i] + board_painted <= curr_sum)
		{
			board_painted += a[i];
		}
		else
		{
			painter_used++;
			board_painted = a[i];
			if(painter_used > k)
				return false;
		}		
	}
	return true;
}



int main()
{
	ll n,k,t;
	cin>>n>>k>>t;

	ll a[n];
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}

	ll sum=0;
	ll max =a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i] > max)
			max =a[i];
		sum += (a[i]);
	}

	ll s=max;
	ll e=sum;
	ll ans=INT_MAX;
	while(s<=e)
	{
		ll mid = (s+e)/2;
		if(check(a,n,k,mid))
		{
			ans = min(ans,mid);
			e=mid-1;
		}
		else
			s=mid+1;
	}
	cout<<((ans%10000003)*t)%10000003<<endl;


	return 0;
}