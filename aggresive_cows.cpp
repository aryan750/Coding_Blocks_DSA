#include<bits/stdc++.h>
using namespace std;

bool canPlacecow(int stalls[], int n, int cows, int min_sep)
{
	int count_of_cows = 1;
	int last_cow = stalls[0];
	for(int i=1;i<n;i++)
	{
		if(stalls[i] - last_cow >= min_sep)
		{
			last_cow = stalls[i];
			count_of_cows++;
			if(count_of_cows == cows)
			{
				return true;
			}

		}
	}
	return false;
}


int main()
{
	int stalls[] = {1,2,4,8,9};
	int n=5;

	int cows=3;

	//binary search 
	int s=0;
	int e=stalls[n-1] - stalls[0];
	int ans=0;
	while(s<=e)
	{
		int mid=(s+e)/2;

		bool cowsRakhPaye = canPlacecow(stalls, n, cows, mid);
		if(cowsRakhPaye)
		{
			ans= mid;
			s=mid + 1;
		}	
		else 
			e=mid-1;
	}

	cout<<ans<<endl;

	return 0;
}