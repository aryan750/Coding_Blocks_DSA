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

	int low=0;
	int high=n-1;
	int maxL=0;
	int maxR=0;
	int cur_water =0;

	while(low <= high)
	{
		if(a[low] < a[high])
		{
			if(a[low] > maxL)
			{
				maxL = a[low];
			}
			else 
				cur_water += maxL - a[low];
			low++;
		}
		else 
		{
			if(a[high] > maxR)
				maxR = a[high];
			else 
				cur_water += maxR -a[high];
			high--;
		}
	}
	cout<<cur_water<<endl;

	return 0;
}