#include<bits/stdc++.h>
using namespace std;
#define ll long long 

vector<ll> rght(ll *arr, ll n)
{
	vector<ll> v;
	stack<ll> s;

	for(ll i=n-1;i>=0;i--)
	{
		if(s.size() == 0)
			v.push_back(n);
		else if(s.size() > 0 && arr[s.top()] < arr[i])
			v.push_back(s.top());
		else if(s.size() > 0 && arr[s.top()] >= arr[i])
		{
			while(s.size() > 0 && arr[s.top()] >= arr[i])
			{
				s.pop();
			}
			if(s.size() == 0)
				v.push_back(n);
			else
				v.push_back(s.top());
		}
		s.push(i);
	}
	reverse(v.begin(), v.end());
	return v;
}

vector<ll> lft(ll *arr, ll n)
{
	vector<ll> v;
	stack<ll> s;

	for(ll i=0;i<n;i++)
	{
		if(s.size() == 0)
			v.push_back(-1);
		else if(s.size() > 0 && arr[s.top()] < arr[i])
			v.push_back(s.top());
		else if(s.size() > 0 && arr[s.top()] >= arr[i])
		{
			while(s.size() > 0 && arr[s.top()] >= arr[i])
			{
				s.pop();
			}
			if(s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(i);
	}
	return v;
}


int main()
{
	ll n;
	cin>>n;
	ll a[n];

	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}

	//right NSR
	vector<ll> right = rght(a,n);

	//left NRL
	vector<ll> left = lft(a,n);

	//width
	ll width[n];
	for(ll i= 0;i<n;i++)
	{
		width[i] = right[i] - left[i] -1;
	}


	//area
	ll area[n];
	for(ll i=0;i<n;i++)
	{
		area[i] = width[i]* a[i];
	}


	//max of area
	ll maxy= INT_MIN;
	for(ll i=0;i<n;i++)
	{
		maxy = max(maxy, area[i]);
	}

	cout<<maxy<<endl;

	return 0;
}