#include<bits/stdc++.h>
using namespace std;

int clearRangeItoJ( int n, int i, int j)
{
	int ones= (~0);
	int a = ones << (j+1);
	int b= (1<<i) -1;
	int mask= a|b;
	return (n&mask);
}

int replaceBit(int n, int m, int i, int j)
{
	int  n_=clearRangeItoJ(n,i,j);
	int ans= n_ | (m<<i);
	return ans;
}

int main()
{
	int n=15;
	int m=2;
	int i=1;
	int j=3;
	
	cout<<replaceBit(n,m,i,j)<<endl ;
	






	return 0;
}