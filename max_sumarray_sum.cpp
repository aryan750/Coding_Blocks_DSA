#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	int n;
	
	while(T>0)
	{		
		cin>>n;
		int a[n];	
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int curr_sum=0;
		int max_sum=INT_MIN;
	
		for(int i=0;i<n;i++)
		{
			curr_sum=max(curr_sum+a[i],a[i]);
			max_sum=max(max_sum,curr_sum);
		}

		cout<<max_sum<<endl;
		T--;
	}
	return 0;
}