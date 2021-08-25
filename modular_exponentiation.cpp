#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll power_fast(ll a, ll b, ll c)
{
	ll ans=1;
	while(b>0)
	{
		int last_bit = b&1;
		if(last_bit)
		{
			ans = ans *a;
			ans = ans % c;
			ans = (ans+c) % c;
		}
		a= a*a;
		a = a%c;
		b = b>>=1;
	}
	return ans;

}



int main()
{
	ll a;
	ll b;
	ll c;
	cin>>a>>b>>c;
	ll k = power_fast(a,b,c);

	ll pp = k % c;
	cout<<pp<<endl;

	return 0;
}