#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	return a.second < b.second;
}



int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		cin>>n;
		int a,b;
		pair<int,int> p[n];

		//input the pair array
		for(int i=0;i<n;i++)
		{
			cin>>a >> b;
			p[i] = make_pair(a,b);
		}

		sort(p,p+n,compare);

		int ans=1;
		int ch = 0;
		for(int i=1;i<n;i++)
		{
			if(p[i].first >= p[ch].second)
			{
				ans++;
				ch = i;
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}