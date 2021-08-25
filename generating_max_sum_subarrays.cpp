#include<bits/stdc++.h>
using namespace std;

int main()
{
	int current_sum;
	int N;
	cin>>N;

	int a[N];
	int max_sum=INT_MIN;
	for(int i=0;i<N;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<N;i++)
	{
		for(int j=i;j<N;j++)
		{
			current_sum=0;
			for(int k=i;k<=j;k++)
			{
				current_sum+=a[k];
			}
			max_sum=max(max_sum,current_sum);

		}
	}
	cout<<max_sum;
	return 0;
}