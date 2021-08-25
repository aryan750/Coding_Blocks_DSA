#include<bits/stdc++.h>
using namespace std;

// int count_set_bits(int n)
// {
		
// }



int main()
{
	int q;
	cin>>q;

	while(q>0)
	{
		int a, b;
		cin>>a;
		cin>>b;
		int ans=0;

		for(int i=a;i<=b;i++)
		{
			ans += __builtin_popcount(i);
		}
		cout<<ans<<endl;
		q--;

	}



	return 0;
}