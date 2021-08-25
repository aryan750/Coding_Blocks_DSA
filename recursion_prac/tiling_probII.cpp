#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long tiling(long long n,long long m)
{
	if(n == m)
		return 2;
	if(n>=1 && n<m)
		return 1;
	if(n<=0)
		return 0;
	return tiling(n-m,m)%mod + tiling(n-1,m)%mod;
}


int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		long long n, m;
		cin>>n>>m;
		long long ans = tiling(n,m)%mod;
		cout<<ans<<endl;
		t--;
	}





	return 0;
}