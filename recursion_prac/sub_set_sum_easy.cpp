#include<bits/stdc++.h>
using namespace std;

bool subset(int *a , int n , int count, int i, int sum)
{
	//base case
	if(i == n)
	{
		if(sum == 0 && count>0)
			return true;
		return false;
	}

	return subset(a, n ,count+1, i+1, sum+a[i]) || subset(a,n,count,i+1,sum);
}


int main(){

	int t;
	cin>>t;

	while(t>0)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}

		if(subset(a, n,0,0,0))
		{
			cout<<"Yes";
		}
		else
			cout<<"No";

		cout<<endl;


		t--;
	}




	return 0;
}