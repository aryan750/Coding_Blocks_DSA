#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll a[1000005], pre[1000005];


int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		int n;
		cin>>n;
		memset(pre, 0 ,sizeof(pre));

		pre[0] = 1;

		//read the input
		int sum =0;
		for(int i =0;i<n;i++)
		{
			cin>>a[i];
		}

		for(int i=0;i<n;i++)
		{
			sum += a[i];
			sum %= n;
			sum = (sum + n) % n;
			pre[sum]++;
		}


		ll ans =0;
		for(ll i=0;i<n;i++)
		{
			int m =pre[i];
			ans += m * (m-1)/2;
		}

		cout<<ans<<endl;


		t--;
	}




	return 0;
}