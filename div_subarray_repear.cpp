#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll a[100010], pre[100010];


int main()
{
	int t;
	cin>>t;

	while(t>0)
	{
		int n;
		cin>>n;
		memset(pre, 0 ,sizeof(pre));

		ll sum =0;
	
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			sum += a[i];
			sum %= n;
			sum = (sum+n) % n;
			pre[sum]++;
		}

		ll ans=(pre[0]*(pre[0]+1))/2;
        
        for(int i=1;i<n;i++)
        {
            ans+=(pre[i]*(pre[i]-1))/2;
        }

		cout<<ans<<endl;
		t--;
	}




	return 0;
}