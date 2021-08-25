#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{	
	ll x,y;
	cin>>x>>y;

	ll maxx =0;
 
	for(ll i=x;i<=y;i++)
	{
		for (ll j = i+1; j<=y; j++)
		{
			maxx = max( maxx, i^y);
		}
		
	}

	cout<<maxx<<endl;

	return 0;
}