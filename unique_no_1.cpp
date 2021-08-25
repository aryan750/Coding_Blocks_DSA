#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[100005];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int ans;

	for(int i=0;i<n;i++)
	{
		ans = ans ^ a[i];
	}
	
	cout<<ans<<endl;


	return 0;
}