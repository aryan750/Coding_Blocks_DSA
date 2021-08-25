#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a[],int stalls, int cows, int curr_dis)
{
	int cow_used =1;
	int last_cow=a[0];
	for(int i=1;i<stalls;i++)
	{
		if(a[i] - last_cow >= curr_dis)
		{
			cow_used++;
			last_cow = a[i];
			if(cow_used == cows)
			{
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int stalls;
	cin>>stalls;
	int cows;
	cin>>cows;
	int a[100000];
	for(int i=0;i<stalls;i++)
	{
		cin>>a[i];
	}
	sort(a,a+stalls);
	//solution
	int s=a[0];
	int e=a[stalls-1]-a[0];
	int ans;
	while(s<=e)
	{
		int mid=(s+e)/2;

		if(isPossible(a,stalls,cows,mid))
		{	
			ans=mid;
			s=mid+1;
		}
		else
			e=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}