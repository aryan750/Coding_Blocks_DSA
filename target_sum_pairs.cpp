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
		cin.get();
	}
	int target;
	cin>>target;

	//finding pairs 
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]+a[j] == target)
			{
				if(a[i]<a[j])
					cout<<a[i]<<" and "<<a[j]<<endl;
				else
					cout<<a[j]<<" and "<<a[i]<<endl;
			}
		}
	}
// another approach
// sort(a,a+n);
// while(i<j)
// {
// 	if(target > a[i] + a[j])
// 	{
// 		i--;
// 	}
// 	else if(target < a[i] + a[j]) 
// 	{
// 		j++;
// 	}
// 	else
// 	{
// 		cout<<a[i]<<" and "<<a[j]<<endl;
// 	}
// }
	return 0;
}

