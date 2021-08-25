#include<bits/stdc++.h>
using namespace std;

bool sorto(int a[], int n)
{
	//base case
	if(n == 1)
	{
		return true;
	}

	//rec case
	if(a[0] <= a[1] && sorto(a+1,n-1))
		return true;

	return false;
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
	bool ans = sorto(a, n);
	if(ans == 1)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}