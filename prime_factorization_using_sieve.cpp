//time complexity O(log N)


#include<bits/stdc++.h>
using namespace std;

vector<int> prime_sieve(int p[], int n)
{
	p[2] = 1;
	p[1] = p[0] = 0;
	//first makr all even no not prime
	for(int i=3;i<=n;i+=2)
	{
		p[i] = 1;
	}

	for(int i=3;i<=n;i+=2)
	{
		if(p[i] == 1)
		{
			//mark all the multiples of odd no as 0
			for(int j = i*i ;j<=n;j=j+i)
				p[j] = 0; 
		}
	}
	
	vector<int> primes;
	primes.push_back(2);

	for(int i=3;i<=n;i+=2)
	{
		if(p[i] == 1)
			primes.push_back(i);
	}

	return primes;
}

vector<int> factorize( int m, vector<int> primes)
{
	vector<int> factors;
	factors.clear();

	int i=0;
	int p = primes[0];

	while(p * p <= m)
	{
		if(m % p == 0)
		{
			factors.push_back(p);
			while(m % p == 0)
			{
				m = m/p;
			}
		}
		i++;
		p = primes[i];
	}
	if( m != 1)
		factors.push_back(m);

	return factors;

}


int main()
{
	int n=1000000;
	int p[n]= {0};
	vector<int> primes =prime_sieve(p,10000);

	int t;
	cin>>t;

	while(t>0)
	{
		int no;
		cin>>no;
		vector<int> factors = factorize(no, primes);
		for(auto f : factors)
		{
			cout<<f<<" "<<endl;
		}
		t--;
	}
	return 0;
}