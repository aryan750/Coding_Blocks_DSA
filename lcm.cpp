#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcd(ll a , ll b)
{
	return b==0 ? a : gcd(b , a%b);
}



int main()
{
	ll a;
	ll b;
	cin>>a>>b;
	ll k = gcd(a,b);
	ll lcm = (a*b)/k;
	cout<<lcm<<endl;




	return 0;
}