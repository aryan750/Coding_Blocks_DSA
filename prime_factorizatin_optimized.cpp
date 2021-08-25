#include<bits/stdc++.h>
using namespace std;

void primefactor(int n)
{
	vector<pair<int, int>> factors;

	int count;
	for(int i=2;i*i <= n;i++)
	{
		if(n%i == 0)
		{
			count = 0;
			while(n%i == 0)
			{
				count++;
				n = n/i;
			}
			factors.push_back(make_pair(i, count));
		}
	}
	if( n != 1)
	{
		//whatever the no other than 1 is prime no itself
		factors.push_back(make_pair(n,1));
	}

	for(auto p: factors)
	{
		cout<<p.first<<"^"<<p.second<<endl;
	}
	return ;

}




int main()
{
	int n;
	cin>>n;

	primefactor(n);

	return 0;
}