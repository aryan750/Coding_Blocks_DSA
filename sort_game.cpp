#include<bits/stdc++.h>
using namespace std;

bool mycompare( pair<string,int> p1, pair<string,int> p2)
{
	if(p1.second ==  p2.second)
	{
		return p1.first < p2.first; 
	}
	return p1.second > p2.second;
}



int main()
{
	int x;
	cin>>x;

	int n;
	cin>>n;
	pair<string,int> lis[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>lis[i].first;
		cin>>lis[i].second;
	}

	sort(lis,lis+n,mycompare);
	//print the output
	for(int i=0;i<n;i++)
	{
		if(lis[i].second >= x)
		{
			cout<<lis[i].first<<" ";
			cout<<lis[i].second<<endl;

		}
	}


	return 0;
}