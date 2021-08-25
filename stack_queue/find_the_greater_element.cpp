#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}


	vector<int> v;
	stack<int> s;
	int j =n-1;
	while( j != -1)
	{
		s.push(a[j]);
		j--;
	}
	for(int i= n-1;i>=0;i--)
	{
		if(s.size() == 0)
			v.push_back(-1);
		else if(s.size() >0 && s.top() > a[i])
		{
			v.push_back(s.top());
		}
		else if(s.size() > 0 && s.top() <= a[i])
		{
			while(s.size() > 0 && s.top() <= a[i])
			{
				s.pop();
			}
			if(s.size() == 0)
				v.push_back(-1);
			else
				v.push_back(s.top());
		}
		s.push(a[i]);
	}

	reverse(v.begin(), v.end());
	for(int i = 0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}