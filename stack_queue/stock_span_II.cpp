#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;

	int a[n+1];
	a[0] = INT_MAX;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	vector<int> v;
	stack<int> s;

	for(int i=0;i<=n;i++)
	{
		if(s.size() == 0)
		{
			v.push_back(i);
		}
		else if(s.size() > 0 && a[s.top()] > a[i])
		{
			v.push_back(i - s.top());
		}
		else if(s.size() > 0 && a[s.top()] <= a[i])
		{
			while(s.size() > 0 && a[s.top()] <= a[i])
			{
				s.pop();
			}
			if(s.size() == 0)
			{
				v.push_back(i);
			}
			else
				v.push_back(i - s.top());
		}
		s.push(i);
	}

	for(int i=1;i<=n;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"END"<<endl;



	return 0;
}