//could not implement properly

#include<bits/stdc++.h>
using namespace std;

bool isCook(int ranks[],int p, int cooks,int mid)
{
	int count=0;
	for(int i=0;i<cooks;i++)
	{
		int time=0;
		int j=1;
		while(1)
		{
			time = time+ j*ranks[i];
			j++;
			if(time>mid)
			{
				break;
			}
			count++;
		}
	}
	return (count >= p);
}



int findprata(int ranks[], int p, int cooks)
{
	int maxx= INT_MIN;
	for(int i=0;i<cooks;i++)
	{
		maxx = max(maxx,ranks[i]);
	}
	int i=1;
	int time=0;
	int count =0;
	//find time by the cook for binary search 
	while(count<p)
	{
		time = time + i*maxx;
	}

	//binary search 
	int s=0;
	int e=time;
	while(s <= e)
	{
		int mid=(s+e)/2;
		// int ans;
		if(isCook(ranks,p,cooks,mid))
		{	
			// ans = min(ans,mid);
			e = mid;
		}
		else
			s= mid;
	}
	return e;
}



int main()
{
	int t;
	cin>>t;

	for(int i=0;i<t;i++)
	{
		int p;
		cin>>p;

		int cooks;
		cin>>cooks;
		int ranks[cooks];
		for(int j=0;j<cooks;j++)
		{
			cin>>ranks[j];
		}

		cout<<findprata(ranks,p,cooks)<<endl;
	}
	return 0;
}