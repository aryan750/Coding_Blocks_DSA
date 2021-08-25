#include<bits/stdc++.h>
using namespace std;
#define ll long long  
long long a[1000000];

void prime_sieve(ll *p, ll n)
{	
	//marking all the odd no prime
	for(ll i =3;i<=n;i+=2)
	{
		p[i] =1;
	}

	for(ll i = 3;i<=n;i+=2)
	{
		if(p[i] == 1)
		{
			//marking all the multiples odd no not prime
			for(ll j=i*i;j<=n;j= j+i)
			{
				p[j] = 0;
			}
		}
	}

	p[0] = 0;
	p[1] = 0;
	p[2] = 1;
	int k=0;
	for(int i =2 ;i<1000000;i++)
	{
		if(p[i])
		{
			a[k] = i;
			k++;
		}
	}
	return;
}



int main()
{
	ll N = 1000001;
	ll p[N] = {0};
	prime_sieve(p,N-1);

	int t;
	cin>>t;
	ll n;

	while(t>0)
	{
		cin>>n;
		cout<<a[n-1]<<endl;
		t--;
	}




	return 0;
}