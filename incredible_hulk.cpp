#include<bits/stdc++.h>
using namespace std;

int moves(int n)
{
	int count=0;

	while(n>0)
	{
		count++;
		n = n&(n-1);
	}
	return count;
}



int main()
{
	int t;
	cin>>t;

	while(t>0)
	{	
		int n;
		cin>>n;
		cout<<moves(n)<<endl;
		t--;
	}



	return 0;
}