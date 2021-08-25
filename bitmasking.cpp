#include<bits/stdc++.h>
using namespace std;

int isOdd(int n) // check if n is odd
{
	return (n&1);
}

int getBit(int n, int i) //find ith bit
{
	int mask= (1<<i);
	int bit = (n&mask)>0 ? 1:0;
	return bit;
}

int setBit(int n, int i) //set ith bit 
{
	int mask = (1<<i);
	int ans = n | mask;
	return ans;
}

//clear the ith bit 
//mask = take 1 on ith bit and then negate it and do the &
int clearBit(int &n, int i)
{
	int mask = ~(1<<i);
	n = (n&mask);
	return n;
} 

//first we clear the bit and then
//take | 

void updateBit( int &n, int i, int v)
{
	int mask = ~(1<<i);
	int cleared_n = n&mask;
	n = cleared_n | (v << i);
}

int clearLastBits(int n, int i)
{
	int mask = (-1 << i);
	return n&mask;
}

int clearRangeItoJ( int n, int i, int j)
{
	int ones=(~0);
	int a = ones<<(j+1);
	int b = (1<<i)-1;
	int mask =a|b;
	int ans = n&mask;
	return ans;
}

int main()
{
	int n=31;
	int i=1;
	int j=3;
	cout<<clearRangeItoJ(n,i,j)<<endl;

	// // cout<<getBit(n,i)<<endl;
	// n = setBit(n,i);
	// cout<<"ans: "<<n;

	

	return 0;
}