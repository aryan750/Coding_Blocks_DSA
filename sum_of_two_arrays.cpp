#include<bits/stdc++.h>
using namespace std;

int add(int a[],int b[],int n,int m)
{
	int carry = 0;
	int sum[n+m];
	
	if(n > m)
	{
		while(i>=0)
		{
			sum[i] = carry + a[i] +b[j];
			carry = sum / 10;
			sum = sum % 10;
			i--;
		}
	}
	else
	{
		while(j>=0)
		{
			sum[i] = carry + a[i] +b[j];
			carry = sum / 10;
			sum = sum % 10;
			j--;
		}
	}




	return 0;
}




int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}

	cout<<add(a,b,n,m)<<endl;
	return 0;
}