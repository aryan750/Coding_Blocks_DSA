#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		int n;
		cin>>n;
		int ans = __builtin_popcount(n);
		cout<<ans<<endl;
		t--;

	}


	return 0;
}