#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];

	//input the array
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int target;
	cin>>target;

	sort(arr,arr+n);
	int i=0;
	while(i<n)
	{
		int j=i+1;
		int k=n-1;
		int jj=target-arr[i];
		while(j<k)
		{
			if(arr[j]+arr[k] < jj)
			{
				j++;
			}
			else if(arr[j]+arr[k] > jj)
			{
				k--;
			}
			else
			{
				cout<<arr[i]<<", "<<arr[j]<<" and "<<arr[k]<<endl;
				j++;
				k--;
			}
		}
		i++;
	}

	// int a,b,c;

	// int j=3;
	// while(j<n)
	// {
	// 	a=arr[0];
	// 	b=arr[1];
	// 	c=arr[2];
	// 	//SUM>TARGET
	// 	if(a+b+c > target)
	// 	{
	// 		//find max and change it  
	// 		int maxi=max(a,b);
	// 		int most=max(maxi,c);

	// 		//if a is min
	// 		if(most==a)
	// 		{
	// 			a=arr[j];
	// 		}
	// 		//if b is min
	// 		else if(most==b)
	// 		{
	// 			b=arr[j];
	// 		}
	// 		//if c is min 
	// 		else
	// 		{
	// 			c=arr[j];
	// 		}
	// 		j++;
	// 	}
	// 	//sum<target
	// 	else if(a+b+c < target)
	// 	{
	// 		//find min 
	// 		int mini=min(a,b);
	// 		int least=min(mini,c);

	// 		//if a is min
	// 		if(least==a)
	// 		{
	// 			a=arr[j];
	// 		}
	// 		//if b is min
	// 		else if(least==b)
	// 		{
	// 			b=arr[j];
	// 		}
	// 		//if c is min 
	// 		else
	// 		{
	// 			c=arr[j];
	// 		}
	// 		j++;
			

	// 	}
	// 	//sum=target
	// 	else
	// 	{
	// 		//print a,b,c
	// 		cout<<a<<", "<<b<<" and "<<c<<endl;


	// 	}
	// }

	return 0;
}