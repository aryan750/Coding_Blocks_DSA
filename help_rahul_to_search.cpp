#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll find_key( ll a[], ll n, ll key)
{
	

	ll s=0;
	ll e=n-1;

	while(s<=e)
	{
		ll mid =(s+e)/2;
		if(a[mid] == key)
			return mid;

		else if(a[s] <= a[mid])
		{
			//2 case first if the key is on lift or right 
			if(key >= a[s] && key <= a[mid])
			{
				e=mid-1;
			}
			else 
				s=mid+1;
		}
		else
		{
			if(key <=a[e] && key >=a[mid])
			{
				s=mid+1;
			}
			else
				e =mid-1;
		}	
	}
	return -1;
}


int main()
{
	ll n;
	cin>>n;
	ll a[n];

	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ll key;
	cin>>key;

	cout<<find_key(a,n,key)<<endl;

	return 0;
}