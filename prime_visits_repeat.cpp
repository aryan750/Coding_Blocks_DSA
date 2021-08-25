#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void prime_sieve(int p[])
{	
	//marking all the odd no prime
	for(ll i =3;i<=1000000;i+=2)
	{
		p[i] =1;
	}

	for(ll i = 3;i<=1000000;i+=2)
	{
		if(p[i] == 1)
		{
			//marking all the multiples odd no not prime
			for(ll j=i*i;j<=1000000;j= j+i)
			{
				p[j] = 0;
			}
		}
	}

	p[0] = 0;
	p[1] = 0;
	p[2] = 1;
}


int main()
{
	

	int p[1000005] = {0};
	
	prime_sieve(p);

	int csum[1000005] = {0};

	for(int i=1;i<=1000000;i++)
	{
		csum[i] = csum[i-1] + p[i];
	}
	int k;
	cin>>k;

	while(k>0)
	{
		int a;
		int b;
		cin>>a>>b;
		cout<<csum[b] - csum[a-1]<<endl;
		k--;
	}
	// int p[1000005] = {0};
	// prime_sieve(p);

	// int csum[1000005] = {0};

	// for(int i=1;i<=1000000;i++)
	// {
	// 	csum[i] = csum[i-1] + p[i];
	// }

	// int q;
	// cin>>q;

	// while(q>0)
	// {
	// 	int a, b;
	// 	cin>>a>>b;
	// 	cout<<csum[b] - csum[a-1]<<endl;
	// 	q--;
	// }




	return 0;
}