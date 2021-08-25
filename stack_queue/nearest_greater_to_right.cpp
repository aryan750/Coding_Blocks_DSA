
//we will use stack in these type of questions because in brute force solution
//j depends on i

#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{	
	ll n;
	cin>>n;

	ll arr[n];
	for(ll i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	vector<ll> v;
	stack<ll> s;

	for(ll i=n-1;i>=0;i--)
	{
		if(s.size() == 0)
		{
			v.push_back(-1);
		}
		else if(s.size() > 0 && s.top() > arr[i])
		{
			v.push_back(s.top());
		}
		else if(s.size() > 0 && s.top() <= arr[i]){
			while(s.size() > 0 && s.top() <= arr[i])
			{
				s.pop();
			}
			if(s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}

	reverse(v.begin(),v.end());
	for(ll i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
		while(s.size() > 0 && s.top() <= arr[i])
		{
			s.pop();
		}
		if(s.size() == 0)
		{
			v.push_back(-1);
		}
	}
	cout<<endl;



	return 0;
}