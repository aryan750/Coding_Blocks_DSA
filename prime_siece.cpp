#include<bits/stdc++.h>
using namespace std;
#define ll long long int 


void prime_sieve(int p[], int n)
{
	//first mark all odd no prime ie marked 
	for(int i=3;i<=n;i+=2)
	{
		p[i]=1;
	}

	for(int i=3;i<=n;i+=2)
	{
		//if the current no is marked 
		if(p[i] == 1)
		{
			//marking all the multiples of i not prime
			for(int j = i*i;j<=n;j=j+i)
			{
				p[j] = 0;
			}
		}
	}
	p[2] = 1;
	p[1] = p[0] = 0;
}



int main()
{
	int n;
	cin>>n;

	int p[n];
	prime_sieve(p, n);

	for(int i=0;i<=n;i++)
	{
		if(p[i] == 1)
			cout<<i<<" ";
	}
	cout<<endl;



	return 0;
}